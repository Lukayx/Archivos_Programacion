#include "memcache.h"

int main(int argc, char **argv){
  bool existe;
  dbCACHE estructura;
  dbMAP env = leerEnv();
  char buffer[1024];
  int cacheSocket, cacheSocket2, clientSocket;
  ssize_t bytesSent, bytesReceived, bytesRead;
  cacheSocket = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in frontendAddress;
  frontendAddress.sin_family = AF_INET;
  frontendAddress.sin_port = htons(std::stoi(env["PORT_FRONTEND"]));
  frontendAddress.sin_addr.s_addr = inet_addr(env["IP"].c_str());
  socklen_t frontendAddressLength = sizeof(frontendAddress);
  // Verifica si se pudo conectar el frontend y el cache
  if(bind(cacheSocket, (struct sockaddr*)&frontendAddress, frontendAddressLength) == -1) {
    std::cout << "Error al tratar de conectar el cache con el frontend." << std::endl;
    close(cacheSocket);
    return 1;
  }

  // Verifica si el socket pudo ponerse en modo de escucha (Permite solo una consulta a la vez)
  if(listen(cacheSocket, 1) == -1){
    std::cout << "Error al intentar poner el socket del cache en modo de escucha." << std::endl;
    return 1;
  }
  
  // Se crea un nuevo socket para mejorar la comunicacion
  // Luego verifica si se pudo aceptar la conexion entrante 
  clientSocket = accept(cacheSocket, (struct sockaddr*)&frontendAddress, &frontendAddressLength);
  if(clientSocket == -1){
    std::cout << "Error al aceptar la conexion entrante del cliente en el cache." << std::endl;
    return 1;
  }
  cacheSocket2 = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in backendAddress;
  backendAddress.sin_family = AF_INET;
  backendAddress.sin_port = htons(std::stoi(env["PORT_BACKEND"]));
  backendAddress.sin_addr.s_addr = inet_addr(env["IP"].c_str());
  socklen_t backendAddressLength = sizeof(backendAddress);
  // Conecta el socket del cache con el backend
  if(connect(cacheSocket2, (struct sockaddr*)&backendAddress, backendAddressLength) == -1) {
    std::cout << "Error al tratar de conectar el cache con el backend" << std::endl;
    return 1;
  }
  //Aca comienza la copia del while
  while(true){
    std::string txtToSearch;
    std::ostringstream contenido;
    bytesRead = recv(clientSocket, buffer, sizeof(buffer),0); // Cantidad de Bytes que se leyeron
    if(bytesRead == 0){
      // Cliente ha cerrado la conexión de forma ordenada.
      std::cout << "El cliente ha cerrado la conexión de forma ordenada." << std::endl;
      break; // Sale del bucle
    }
    if (bytesRead == -1) {
      // Si bytesRead es menor o igual a cero, el cliente cortó la conexión
      std::cout << "Error al recibir datos o el cliente ha cerrado la conexión de forma inesperada." << std::endl;
      close(clientSocket);
      break;  // Sale del bucle si el cliente corta la conexión
    }
    std::string mensaje(buffer, bytesRead); // transforma el buffer a string
    // std::cout << mensaje << std::endl;
    memset(buffer, 0, sizeof(buffer)); // Llena el búfer con ceros
    // Recortando informacion
    size_t pos = mensaje.find("txtToSearch:")+12;
    txtToSearch = mensaje.substr(pos,(mensaje.length()-2) - pos);
    // Busca en la estructura el 'txtToSearch'
    // Calcula tiempo que demoró en encontrar todas las coincidencias
    auto start = std::chrono::high_resolution_clock::now();
    existe = buscar_en_estructura(txtToSearch, estructura);
    std::cout << existe << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> second = end - start;
    if(existe){
      mensaje = empaquetarMensaje(estructura, mensaje, second, txtToSearch, env);
    } else {
      // Formatea y luego envia el mensaje al servidor de backend
      mensaje = formateoMensaje(env, txtToSearch);
      bytesSent = send(cacheSocket2, mensaje.c_str(), mensaje.length(), 0);
      if(bytesSent == -1){ // Verifica si se envió bien el mensaje
        std::cout << "\nError al enviar la mensaje al servidor de backend." << std::endl;
        exit(1);
      }
      // Recive la respuesta del backend
      bytesReceived = recv(cacheSocket2, buffer, sizeof(buffer),0);
      if(bytesReceived == -1){
        std::cout << "\nNo fue recivida ninguna respuesta desde el backend." << std::endl;
        exit(1);
      }
      std::string buff_to_string(buffer, bytesReceived);
      mensaje = empaquetarMensaje(estructura, buff_to_string, second, txtToSearch, env);
      almacenar_en_estructura(mensaje, estructura, std::stoi(env["MEMORYSIZE"]), txtToSearch);
    }
    memset(buffer, 0, sizeof(buffer)); // Llena el búfer con ceros
    bytesSent = send(clientSocket, mensaje.c_str(), mensaje.length(), 0);
    // Verifica si se envió bien la respuesta al fronted
    if(bytesSent == -1){
      std::cout << "\nError al enviar la mensaje de respuesta al frontend." << std::endl;
      return 1;
    }
  }
  return 1;
}

bool buscar_en_estructura(std::string palabra, dbCACHE estructura){
  bool exist;
  if(estructura.find(palabra) != estructura.end()){
    exist = true;
    estructura[palabra].second++;
  } else {
    exist = false;
  }
  return exist;
}

std::string empaquetarMensaje(dbCACHE estructura, std::string mensajeOLD, std::chrono::duration<double> tiempo, std::string palabra, dbMAP env){
  size_t pos = mensajeOLD.find("origen:")+7;
  int n = mensajeOLD.find(',') - pos;
  std::string origen = mensajeOLD.substr(pos, n);
  std::ostringstream mensaje;
  if(origen == env["FRONT"]){
    std::cout << "perro" << std::endl;
    bool isFound = !estructura[palabra].first.empty();
    std::string txtFound = isFound ? "true" : "false";
    mensaje << "{origen:" << env["HOST"]
            << ",destino:" << env["FRONT"]
            << ",contexto:{tiempo:" <<  tiempo.count() << "s"
            << ",ori=CACHE"
            << ",isFound=" << txtFound
            << ",resultados:[";
    if(isFound){
      size_t largo = estructura[palabra].first.size();
      for(size_t i = 0; i < largo; i++){
        auto element = estructura[palabra].first[i];
        if(i == 0){
            mensaje << "{archivo:" << element.first << ",puntaje:" << element.second << "}";
          } else {
            mensaje << ",{archivo:" << element.first << ",puntaje:" << element.second << "}";
          }
      }
    } 
    mensaje << "]}}";
    std::cout << "Mensaje desde " << env["FRONT"] << ": " << mensaje.str() << std::endl;
  } else if (origen == env["BACK"]){
    std::cout << "gato" << std::endl;
    mensaje << "{origen:" << env["HOST"]
            << ",destino:" << env["FRONT"]
            << mensajeOLD.substr(mensajeOLD.find(",contexto:"));
    std::cout << "Mensaje desde " << env["BACK"] << ": " << mensaje.str() << std::endl;
  } else {
    std::cout << "El formato del mensaje esta mal hecho" << std::endl;
    exit(1);
  }
  return mensaje.str();
}

std::string formateoMensaje(dbMAP env, std::string text){
  std::ostringstream ss;
  ss<< "{origen:" << env["HOST"]
    << ",destino:" << env["BACK"]
    << ",contexto:{txtToSearch:" << text 
    << "}}";
  return ss.str();
}

void almacenar_en_estructura(std::string mensaje, dbCACHE& estructura, int MEMORYSIZE, std::string txtToSearch){
  size_t pos = mensaje.find("isFound=")+8;
  std::string isFound = mensaje.substr(pos, mensaje.find_first_of(',',pos) - pos);
  vector archivosConteo;
  bool verificaMemorySize = estructura.size() < MEMORYSIZE;
  if(!verificaMemorySize){
    int cont, cantidad;
    std::string clave;
    cont = 0;
    for(auto elemento : estructura){
      cantidad = elemento.second.second;
      if(cont < cantidad){
        cont = cantidad;
        clave = elemento.first;
      }
    }
    estructura.erase(clave);
  }
  if(isFound == "true"){
    size_t first, second; 
    std::string val1, val2;
    std::pair<std::string, std::string> par;
    first = mensaje.find("archivo:", 0);
    while(first != std::string::npos){
      first += 8;
      size_t coma = mensaje.find_first_of(',', first);
      val1 = mensaje.substr(first, coma - first);
      second = mensaje.find("puntaje:", first) + 8;
      size_t llave = mensaje.find_first_of('}', second);
      val2 = mensaje.substr(second, llave - second);
      par = std::make_pair(val1, val2);
      archivosConteo.push_back(par);
      first = mensaje.find("archivo:", second);
      // std::cout << "valor 1: " << val1 << "   valor 2: " << val2 << std::endl;
      val1 = "";
      val2 = "";
      estructura[txtToSearch] = std::make_pair(archivosConteo, 1);
    }
  }
}

dbMAP leerEnv(){
  dbMAP database;
  std::ifstream archivo(".env");
  std::string key;
  std::string linea;
  std::string valor;
  if (!archivo.is_open()) {
    std::cout << "No se pudo abrir el archivo .env" << std::endl;
    std::cout << "Verifique de que se encuentre en la carpeta actual" << std::endl;
    exit(1);
  }
  while(getline(archivo, linea)){
    int pos = linea.find("=");
    key = linea.substr(0, pos); //Recorta el nombre de la variable
    valor = linea.substr(pos+1, linea.length());
    eliminarRetornoDeCarro(valor);
    database[key] = valor; //Almacena el contenido de la variable del .env al map
  }
  archivo.close();
  return database;
}

void eliminarRetornoDeCarro(std::string& cadena) {
  cadena.erase(std::remove(cadena.begin(), cadena.end(), '\r'), cadena.end());
}