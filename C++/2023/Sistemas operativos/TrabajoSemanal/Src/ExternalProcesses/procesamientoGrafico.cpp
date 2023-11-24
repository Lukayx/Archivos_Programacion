#include "../../Include/procesamientoGrafico.h"

int pid = getpid();

int main(int argc, char **argv){
  std::string path = argv[1];
  if(!verificaRuta(path)) return 0;
  
  return 1;
}

bool verificaRuta(std::string path){
  if (path.find_last_of('/') != std::string::npos) {
    std::string directoryPath = path.substr(0, path.find_last_of('/'));
    if (!(fs::exists(directoryPath) && fs::is_directory(directoryPath))) {
      std::cout << "La ruta entregada al proceso externo no es válida." << std::endl;
      std::cout << "Se cerrará el proceso externo." << std::endl;
      return false;
    } else {
      std::ifstream archivo(path, std::ios::in);
      if(!archivo.is_open()){
        std::cout << "El archivo no fue encontrado en la ruta entregada." << std::endl;
        std::cout << "Se cerrará el proceso externo." << std::endl;
        return false;
      }
      archivo.close();
    }
  }
  return true;
}