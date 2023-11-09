#include "invertedindex.h"

int main(int argc, char **argv){
  dbMAP env = leerEnv();
  wordCount_files mapa = agregaPalabrasMapa(env["FILE"]);
  int backendSocket, clientSocket;
  char buffer[1024];
  // Se crea y configura el socket del backend
  backendSocket = socket(AF_INET, SOCK_STREAM, 0);
  // Conecta el socket del backend con el cache
  struct sockaddr_in frontendAddress;
  frontendAddress.sin_family = AF_INET;
  frontendAddress.sin_port = htons(std::stoi(env["PORT"]));
  frontendAddress.sin_addr.s_addr = inet_addr(env["IP"].c_str());
  socklen_t frontendAddressLength = sizeof(frontendAddress);
  // std::cout << "perro" << std::endl;
  // Verifica si se pudo conectar el backend y el cache
  if(bind(backendSocket, (struct sockaddr*)&frontendAddress, frontendAddressLength) == -1) {
    std::cout << "Error al tratar de conectar el backend con el cache." << std::endl;
    close(backendSocket);
    return 1;
  }
  // Verifica si el socket pudo ponerse en modo de escucha (Permite solo una consulta a la vez)
  if(listen(backendSocket, 1) == -1){
    std::cout << "Error al intentar poner el socket en modo de escucha." << std::endl;
    return 1;
  }
  // Se crea un nuevo socket para mejorar la comunicacion
  // Luego verifica si se pudo aceptar la conexion entrante 
  clientSocket = accept(backendSocket, (struct sockaddr*)&frontendAddress, &frontendAddressLength);
  if(clientSocket == -1){
    std::cout << "Error al aceptar la conexion entrante." << std::endl;
    return 1;
  }
  while(true){
    std::string topk, txtToSearch, respuesta;
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
    size_t pos = mensaje.find("topk:")+5;
    topk = mensaje.substr(pos, (mensaje.find_first_of(',', pos) - pos));
    pos = mensaje.find("txtToSearch:")+12;
    txtToSearch = mensaje.substr(pos,(mensaje.length()-2) - pos);
    // Almacena datos del archivo de indice invertido
    // Calcula tiempo que demoró en encontrar todas las coincidencias
    auto start = std::chrono::high_resolution_clock::now();
    vector vectorTOP = creaVector(mapa, txtToSearch);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_milliseconds = end - start;  
    // Escribiendo mensaje de vuelta
    // mensaje={origen:”XXXX”,destino:”XXXX”,contexto:{tiempo:”XXXX”, ori=”CACHE”,
    // isFound=true, resultados:[{archivo:”XXXX”, puntaje:”XXXX”}] }}
    std::string isFound;
    if(vectorTOP.size() != 0) isFound = "true";
    else isFound = "false";
    contenido << "tiempo:" << duration_milliseconds.count() << ",ori=BACKEND,isFound=" << isFound << ",resultados:[";
    if(vectorTOP.size() != 0){
      size_t indice = std::stoi(topk);
      if(vectorTOP.size() < indice) indice = vectorTOP.size();
      for(size_t i = 0; i < indice; i++){
        if(i == 0){
          contenido << "{archivo:" << vectorTOP[i].first << ",puntaje:" << vectorTOP[i].second << "}";
        } else {
          contenido << ",{archivo:" << vectorTOP[i].first << ",puntaje:" << vectorTOP[i].second << "}";
        }
      }
    }
    contenido << "]}}";
    respuesta = mensaje.substr(0,mensaje.find("topk:")) + contenido.str();
    ssize_t bytesSent = send(clientSocket, respuesta.c_str(), respuesta.length(), 0);
    // Verifica si se envió bien la respuesta
    if(bytesSent == -1){
      std::cout << "\nError al enviar la mensaje al servidor de cache." << std::endl;
      break;
    }
  }
  close(clientSocket);
  close(backendSocket);
  return 0;
}

wordCount_files agregaPalabrasMapa(std::string filePath){
  std::ifstream file(filePath);
  std::string linea, valores, name;
  wordCount_files map;
  int count;
  while(getline(file, linea)){
    if(linea != ""){
      std::string word = linea.substr(0,linea.find(":"));
      std::string info = linea.substr(linea.find(":")+1, linea.length());
      std::stringstream ss(info);
      while(getline(ss, valores, ';')){
        name = valores.substr(valores.find_first_of('(')+1,valores.find(':')-1);
        count = std::stoi(valores.substr(valores.find_first_of(':')+1,valores.find_last_of(')')));
        map[word][name] = count;
      }
    }
  }
  file.close();
  return map;
}

vector creaVector(wordCount_files mapa, std::string frase){
  std::vector<std::string> palabras;
  std::istringstream stream(frase);
  std::vector<std::thread> hilos;
  archivos coincidenciasArchivos;
  std::string palabra;
  vector vectorTOP;
  while(stream >> palabra) {
      palabras.push_back(palabra);
  }
  for (size_t i = 0; i < palabras.size(); i++) {
    hilos.emplace_back(buscadorPalabras, std::ref(coincidenciasArchivos), palabras[i], mapa, i);
  }
  for(std::thread& hilo : hilos){
    hilo.join();
  }
  for(auto& value : coincidenciasArchivos){
    std::pair<std::string, int> par = std::make_pair(value.first, value.second);
    vectorTOP.push_back(par);
  }

  std::sort(vectorTOP.begin(), vectorTOP.end(), [](const auto& a, const auto& b) {
    return a.second > b.second;
  });

  return vectorTOP;
}

void buscadorPalabras(archivos& mapaConteo, std::string palabra, wordCount_files mapa, int i) {
  if (i == 0) {
    mapaConteo = mapa[palabra];
  } else {
    if (mapa.find(palabra) != mapa.end()) {
      for (auto it = mapaConteo.begin(); it != mapaConteo.end(); ) {
        if (mapa[palabra].find(it->first) == mapa[palabra].end()) {
          it = mapaConteo.erase(it);
        } else {
          mapaConteo[it->first] += mapa[palabra][it->first]; 
          ++it;
        }
      }
    } else {
      mapaConteo.clear();
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
  std::ifstream archivoIndexFile(database["FILE"]);
  if(!archivoIndexFile.is_open()){
    std:: cout << "El archivo de indice invertido no existe." << std::endl;
    exit(1);
  }
  archivoIndexFile.close();
  return database;
}

void eliminarRetornoDeCarro(std::string& cadena) {
  cadena.erase(std::remove(cadena.begin(), cadena.end(), '\r'), cadena.end());
}