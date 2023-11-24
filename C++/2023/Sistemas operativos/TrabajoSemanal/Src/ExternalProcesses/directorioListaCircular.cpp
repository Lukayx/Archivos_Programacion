#include "../../Include/directorioListaCircular.h"

struct Nodo{
  std::string directory_name;
  std::string root_path;
  std::vector<std::string> files;
  Nodo *Next;
};

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
      std::ifstream archivo(path, std::ios:in);
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

Nodo creaListaCircular(std::string path){
  Nodo root;
  Nodo* p = root;

  MAPA mapa = creaMapa(path);
  for(auto& it : mapa){
    p->root_path = path;
    p->directory_name = it.first;
    p->files = it.second;
    

  }
}

MAPA creaMapa(std::string path){
  std::ifstream archivo(path, std::ios::in);
  std::vector<std::string> nombreDirectorios;
  MAPA mapa;
  std::string linea;
  while(getline(archivo, linea)){
    size_t dirbase_pos = linea.find("dirbase="); 
    size_t n = linea.length();
    if(dirbase_pos != std::string::npos){
      dirbase_pos += 8;
      std::string origen = linea.substr(dirbase_pos, n - dirbase_pos);
      root.root_path = root_path;
    } else {
      size_t dirs = linea.find("dirs=");
      if(dirs != std::string::npos){
        dirs += 5;
        std::istringstream directorios( linea.substr(dirs, n - dirs) );
        std::string valor;
        while(getline(directorios,valor, ';')){
          nombreDirectorios.push_back(valor);
        }
      } else {
        size_t pos = linea.find_first_of('=');
        std::string indice = linea.substr(pos);
        std::istringstream files = linea.substr(pos+1, (n - pos+1));
        std::string valor;
        std::vector<std::string> archivos;
        while(gitline(files,valor, ';')){
          archivos.push_back(valor);
        }
        mapa[indice] = archivos;
      }
    }
  }
  return mapa;
}