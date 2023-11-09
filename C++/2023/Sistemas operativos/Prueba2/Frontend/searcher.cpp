#include "searcher.h"

int pid = getpid();

int main(int argc, char **argv){
  dbMAP env = leerEnv();
  std::string respuesta;
  // Se crea el socket del frontend
  int frontendSocket = socket(AF_INET, SOCK_STREAM, 0);
  // Configura la direccion del cache
  struct sockaddr_in cacheAddress;
  cacheAddress.sin_family = AF_INET;
  cacheAddress.sin_port = htons(std::stoi(env["PORT"]));
  cacheAddress.sin_addr.s_addr = inet_addr(env["IP"].c_str());
  socklen_t cacheAddressLength = sizeof(cacheAddress);
  // Conecta el socket del frontend con el cache
  if(connect(frontendSocket, (struct sockaddr*)&cacheAddress, cacheAddressLength) == -1) {
    std::cout << "Error al tratar de conectar el frontend con el cache" << std::endl;
    return 1;
  }
  interfaz(env, frontendSocket);
  close(frontendSocket);
  std::system("clear");
  return 0;
}

void interfaz(dbMAP env, int frontendSocket){
  while (true){
    std::system("clear");
    std::string mensaje, txtToSearch, tiempo, origen, opcion;
    char buffer[1024];
    std::cout << "BUSCADOR BASADO EN INDICE INVERTIDO (" << pid << ")" << std::endl;
    std::cout << "\nLos top K documentos serán " << env["TOPK"] << std::endl;
    std::cout << "\nEscriba texto a buscar: ";
    std::getline(std::cin >> std::ws, txtToSearch); //Pregunta y evita el buffer de cin 
    // Estructura mensaje:
    // mensaje={origen:”XXXX”,destino:”XXXX”,contexto:{topk:”XXXX”, txtToSerarch:”XXXX”}}
    // Formatea y luego envia el mensaje al servidor de cache
    mensaje = formateoMensaje(env, txtToSearch); 
    ssize_t bytesSent = send(frontendSocket, mensaje.c_str(), mensaje.length(), 0);
    if(bytesSent == -1){ // Verifica si se envió bien el mensaje
      std::cout << "\nError al enviar la mensaje al servidor de cache." << std::endl;
      exit(1);
    }
    // std::cout << "perro" << std::endl;
    // Recive la respuesta del cache
    ssize_t bytesReceived = recv(frontendSocket, buffer, sizeof(buffer),0);
    if(bytesReceived == -1){
      std::cout << "\nNo fue recivida ninguna respuesta." << std::endl;
      exit(1);
    }
    // std::cout << "mapache" << std::endl;
    std::string respuesta(buffer, bytesReceived); // transforma el buffer a string
    // std::cout << "mapache" << std::endl;
    memset(buffer, 0, sizeof(buffer)); // Llena el búfer con ceros
    vector info = quitaFormatoMensaje(respuesta, tiempo, origen);
    std::cout << "\nRespuesta  ( Tiempo = " << tiempo << ", origen = " << origen << " )\n" << std::endl;
    for(size_t i = 0; i < info.size(); i++){
      std::cout << i+1 << ") " << info[i].first << ", " << info[i].second << std::endl;
    }
    do{
      std::cout << "\nDesea salir? (Si/No): ";
      std::cin >> opcion;
    }while(opcion != "Si" && opcion != "No");
    if(opcion == "Si") break;
  }
}

std::string formateoMensaje(dbMAP env, std::string text){
  std::ostringstream ss;
  ss<< "{origen:" << env["FROM"]
    << ",destino:" << env["TO"]
    << ",contexto:{topk:" << env["TOPK"]
    << ",txtToSearch:" << text 
    << "}}";
  return ss.str();
}

vector quitaFormatoMensaje(std::string mensaje, std::string& tiempo, std::string& origen){
  size_t pos = mensaje.find("tiempo:")+7;
  tiempo = mensaje.substr(pos, mensaje.find_first_of(',', pos) - pos);
  pos = mensaje.find("ori=")+4;
  origen = mensaje.substr(pos, mensaje.find_first_of(',', pos) - pos);
  vector archivos;
  if(mensaje.find("isFound=true") != std::string::npos){
    int first, second; 
    std::string val1, val2;
    std::pair<std::string, std::string> par;
    first = mensaje.find("archivo:", 0);
    int a = 0;
    while(first != std::string::npos){mensaje.find(',', pos);
      first += 8;
      size_t coma = mensaje.find_first_of(',', first);
      val1 = mensaje.substr(first, coma - first);
      second = mensaje.find("puntaje:", first) + 8;
      size_t llave = mensaje.find_first_of('}', second);
      val2 = mensaje.substr(second, llave - second);
      par = std::make_pair(val1, val2);
      archivos.push_back(par);
      first = mensaje.find("archivo:", second);
      // std::cout << "valor 1: " << val1 << "   valor 2: " << val2 << std::endl;
      val1 = "";
      val2 = "";
    }
  }
  return archivos;
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