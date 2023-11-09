#include "memcache.h"

int main(int argc, char **argv){
  bool existe;
  dbCACHE estructura;
  dbMAP env = leerEnv();
  int cacheSocket, cacheSocket2, clientSocket;
  cacheSocket = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in frontendAddress;
  frontendAddress.sin_family = AF_INET;
  frontendAddress.sin_port = htons(std::stoi(env["PORT_FRONTEND"]));
  frontendAddress.sin_addr.s_addr = inet_addr(env["IP"].c_str());
  socklen_t frontendAddressLength = sizeof(frontendAddress);
  // Verifica si se pudo conectar el frontend y el cache
  if(bind(cacheSocket, (struct sockaddr*)&frontendAddress, frontendAddress) == -1) {
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
  
  cacheSocket2 = socket(AF_INET, SOCKET_STREAM, 0);
  struct sockaddr_in backendAddress;
  backendAddress.sin_family = AF_INET;
  backendAddress.sin_port = htons(std::stoi(env["PORT_FRONTEND"]));
  backendAddress.sin_addr.s_addr = inet_addr(env["IP"].c_str());
  socklen_t backendAddressLength = sizeof(backendAddress);
  // Conecta el socket del cache con el backend
  if(connect(cacheSocket2, (struct sockaddr*)&backendAddress, backendAddress) == -1) {
    std::cout << "Error al tratar de conectar el cache con el backend" << std::endl;
    return 1;
  }
  
  return 1;

  //Aca comienza la copia del while
  while(true){
    std::string txtToSearch, mensaje, respuesta;
    std::ostringstream contenido;
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer),0); // Cantidad de Bytes que se leyeron
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
    std::cout << mensaje << std::endl;
    memset(buffer, 0, sizeof(buffer)); // Llena el búfer con ceros
    // Recortando informacion
    size_t pos = mensaje.find("txtToSearch:")+12;
    txtToSearch = mensaje.substr(pos,(mensaje.length()-2) - pos);
    // Almacena datos del archivo de indice invertido
    // Calcula tiempo que demoró en encontrar todas las coincidencias
    auto start = std::chrono::high_resolution_clock::now();
    existe = buscar_en_estructura(txtToSearch, estructura, mensaje);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_milliseconds = end - start;
    mensaje = empaquetarMensaje(estructura, duration_milliseconds, env);
    
    // Escribiendo mensaje de vuelta
    // mensaje={origen:”XXXX”,destino:”XXXX”,contexto:{tiempo:”XXXX”, ori=”CACHE”,
    // isFound=true, resultados:[{archivo:”XXXX”, puntaje:”XXXX”}] }}
    std::string isFound;
    contenido = 
    if(existe){
      
    } else {
      // Formatea y luego envia el mensaje al servidor de cache
      mensaje = formateoMensaje(env, txtToSearch);
      ssize_t bytesSent = send(cacheSocket2, mensaje.c_str(), mensaje.length(), 0);
      if(bytesSent == -1){ // Verifica si se envió bien el mensaje
        std::cout << "\nError al enviar la mensaje al servidor de backend." << std::endl;
        exit(1);
      }

      // Recive la respuesta del cache
      ssize_t bytesReceived = recv(cacheSocket2, buffer, sizeof(buffer),0);
      if(bytesReceived == -1){
        std::cout << "\nNo fue recivida ninguna respuesta desde el backend." << std::endl;
        exit(1);
      }
      std::string respuesta(buffer, bytesReceived);

      
    }
  }
}

bool buscar_en_estructura(std::string palabra, dbCACHE estructura, mensaje){
  bool exist;
  if(estructura.find(palabra) != estructura.end()){
    exist = true;
    estructura[palabra].second++;
  } else {
    exist = false;
  }
  return exist
}

std::string empaquetarMensaje(dbCACHE estructura, std::chrono::duration<double> tiempo, std::string palabra, dbMAP env){
  std::ostringstream mensaje;
  bool isFound = !estructura[palabra].first.empty();
  mensaje << "{origen=" << env["HOST"]
          << ",destino=" << env["FRONT"]
          << ",contexto:{" << tiempo << "ms"
          << ",origen=CACHE"
          << ",isFound=" << isFound ? "true" : "false"
          << ",resultados:[";
  if(isFound){
    size_t largo = estructura[palabra].first.size();
    for(size_t i = 0; i < largo; i++){
      auto element = estructura[palabra].first[i];
      if(i == 0){
          contenido << "{archivo:" << element.first << ",puntaje:" << element.second << "}";
        } else {
          contenido << ",{archivo:" << element.first << ",puntaje:" << element.second << "}";
        }
    }
  } 
  mensaje << "]}}";
  return mesaje.str();
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
  
}
