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
  cacheAddress.sin_port = htons(std::stoi(env["PORT_TO"]));
  cacheAddress.sin_addr.s_addr = inet_addr(env["IP"].c_str());
  socklen_t cacheAddressLength = sizeof(cacheAddress);
  // Conecta el socket del frontend con el cache
  if(connect(frontendSocket, (struct sockaddr*)&cacheAddress, cacheAddressLength) == -1) {
    std::cout << "Error al tratar de conectar el frontend con el cache" << std::endl;
    return 1;
  }

  while (true){  
    interfaz(env, frontendSocket);
    do{
      std::cout << "\nDesea salir? (Si/No): ";
      std::cin >> respuesta;
    }while(respuesta != "Si" && respuesta != "No");
    if(respuesta == "Si") break;
  }
  close(frontendSocket);
  std::system("clear");
  return 0;
}

void interfaz(dbMAP env, int frontendSocket){
  std::system("clear");
  std::string mensaje, txtToSearch, tiempo, origen;;
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
  // Recive la respuesta del cache
  ssize_t bytesReceived = recv(frontendSocket, buffer, sizeof(buffer),0);
  if(bytesReceived == -1){
    std::cout << "\nNo fue recivida ninguna respuesta." << std::endl;
    exit(1);
  }
  std::string respuesta(buffer, bytesReceived); // transforma el buffer a string
  // std::cout << respuesta << std::endl;
  vector info = quitaFormatoMensaje(respuesta, tiempo, origen);
  for(size_t i = 0; i < info.size(); i++){
    std::cout << i+1 << ") " << info[i].first << ", " << info[i].second << std::endl;
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
  std::cout << "\nRespuesta  ( Tiempo = " << tiempo << ", origen = " << origen << " )\n" << std::endl;
  if(mensaje.find("isFound=true") != std::string::npos){
    int first, second; 
    std::string val1, val2;
    vector archivos;
    size_t pos = mensaje.find("archivo:");
    while (pos != std::string::npos) {
        // Encuentra "archivo:" y avanza a la posición del nombre del archivo
        pos = pos + 8;
        size_t siguiente_coma = mensaje.find(',', pos);
        if (siguiente_coma != std::string::npos) {
            std::string nombre_archivo = mensaje.substr(pos, siguiente_coma - pos);
            // Busca "puntaje:" después de la coma
            pos = mensaje.find("puntaje:", siguiente_coma);
            if (pos != std::string::npos) {
                pos = pos + 8;
                size_t siguiente_llave = mensaje.find('}', pos);
                if (siguiente_llave != std::string::npos) {
                    std::string puntaje = mensaje.substr(pos, siguiente_llave - pos);
                    archivos.push_back(std::make_pair(nombre_archivo, puntaje));
                    std::cout << nombre_archivo << "  " << puntaje <<  std::endl;
                }
            }
        }
        // Continúa buscando "archivo:" desde la última posición
        pos = mensaje.find("archivo:", siguiente_coma);
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