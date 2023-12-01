#include "../../Include/directorioListaCircular.h"

int main(int argc, char **argv){
  if (argc < 2) {
    std::cout << "Por favor, proporcione la ruta del archivo como argumento." << std::endl;
    return 0;
  }
  std::string path = argv[1];
  if(!verificaRuta(path)) return 0;
  Nodo *root = creaListaCircular(path);
  bool resultado = Recorre_Y_Crea(root);
  return resultado;
}

bool verificaRuta(std::string path){
  if (path.find_last_of('/') != std::string::npos) {
    size_t last = path.find_last_of('/');
    std::string directoryPath = path.substr(0, last);
    std::string nameFile = path.substr(last+1, path.length() - (last+1));
    if (!(fs::exists(directoryPath) && fs::is_directory(directoryPath))) {
      std::cout << "La ruta entregada no es válida." << std::endl;
      std::cout << "Se cerrará el proceso externo." << std::endl;
      return false;
    } else {
      if (nameFile.length() < 4 || nameFile.substr(nameFile.length() - 4) != ".dre") {
        std::cout << "La extensión del archivo es invalida, por favor, use un archivo '.dre'" << std::endl;
        exit(1);
      }
      std::ifstream archivo(path);
      if(!archivo.is_open()){
        std::cout << "El archivo no fue encontrado en la ruta entregada." << std::endl;
        std::cout << "Se cerrará el proceso externo." << std::endl;
        return false;
      }
      archivo.close();
    }
  } else {
    return false;
  }
  return true;
}

Nodo* creaListaCircular(std::string path){
  std::string dirbase;
  Nodo *root = nullptr;
  Nodo *p = nullptr;
  Nodo *nuevo_nodo;
  MAPA mapa = creaMapa(path, dirbase);
  for(auto& it : mapa){
      nuevo_nodo = new Nodo();
      nuevo_nodo->root_path = dirbase;
      nuevo_nodo->directory_name = it.first;
      nuevo_nodo->files = it.second;
      nuevo_nodo->Next = root;
    if(p == nullptr){
      root = nuevo_nodo;
      p = root;
    } else {
      p->Next = nuevo_nodo;
      p = p->Next;
    }
  }
  return root;
}

MAPA creaMapa(std::string path, std::string &dirbase){
  std::ifstream archivo(path);
  std::vector<std::string> nombreDirectorios;
  std::string linea;
  MAPA mapa;
  while(getline(archivo, linea)){
    eliminarRetornoDeCarro(linea);
    size_t dirbase_pos = linea.find("dirbase="); 
    size_t n = linea.length();
    if(dirbase_pos != std::string::npos && dirbase_pos == 0){
      dirbase_pos += 8;
      std::string origen = linea.substr(dirbase_pos, n - dirbase_pos);
      dirbase = origen;
    } else {
      size_t dirs = linea.find("dirs=");
      if(dirs != std::string::npos && dirs == 0){
        dirs += 5;
        std::istringstream directorios(linea.substr(dirs, n - dirs));
        std::string valor;
        while(getline(directorios,valor, ';')){
          nombreDirectorios.push_back(valor);
        }
        std::vector<std::string> archivos;
        for(size_t i = 0; i < nombreDirectorios.size(); i++){
          mapa[nombreDirectorios[i]]=archivos;
        }
      } else {
        size_t pos = linea.find_first_of('=');
        if(pos == std::string::npos){
          std::cout << "Error, Verifica que el formato del archivo este correcto." << std::endl;
          exit(1);
        }
        std::string indice = linea.substr(0,pos);
        ++pos;
        std::istringstream files(linea.substr(pos, (n - pos)));
        std::string valor;
        std::vector<std::string> archivos;
        while(getline(files,valor, ';')){
          archivos.push_back(valor);
        }
        mapa[indice] = archivos;
      }
    }
  }
  return mapa;
}

bool Recorre_Y_Crea(Nodo *listaCircular){
  std::string directoryBase = listaCircular->root_path.substr(listaCircular->root_path.find_last_of("/")+1);
  std::string path = listaCircular->root_path.substr(0,listaCircular->root_path.find_last_of("/"));
  if (!(fs::exists(path) && fs::is_directory(path))){
    std::cout << "La ruta especificada en el archivo no se logró encontrar." << std::endl;
    std::cout << "Por favor verifique el 'dirbase' en el archivo de extension .dre" << std::endl;
    return 0;
  }
  if(fs::exists(listaCircular->root_path) && fs::is_directory(listaCircular->root_path)){
    std::cout << "El directorio base del archivo .dre ya existe." << std::endl;
    std::cout << "Verifique su contenido, si no hay nada importante en él puede borrarlo y después ejecutar esta opcion denuevo. " << std::endl; 
    return 1;
  } else {
    Nodo *puntero = listaCircular;
    fs::create_directory(listaCircular->root_path);
    do{
      std::string newDirectoryPath = puntero->root_path+"/"+puntero->directory_name;
      fs::create_directory(newDirectoryPath);
      for(size_t i = 0; i < puntero->files.size(); i++){
        std::string newFilePath = puntero->root_path + "/" + puntero->directory_name + "/" + puntero->files[i] + ".txt";
        std::ofstream archivo(newFilePath);
        if(archivo.is_open()){
          archivo.close();
        } else {
          std::cout << "No se pudo crear el archivo " << puntero->files[i] << std::endl;
        }
      }
      if(puntero->Next == listaCircular){
        std::string enlaceVirtual = "ln -s \""+ puntero->root_path + "/" + puntero->Next->directory_name + "\" \"" + puntero->root_path + "/" + puntero->directory_name + "/\"";
        std::system(enlaceVirtual.c_str());

        std::cout<< "Para verificar si el enlace virtual funciona correctamente se hace un tree en él:" << std::endl;
        std::string comando = "tree \"" + puntero->root_path + "/" + puntero->directory_name + "/" + puntero->Next->directory_name + "\"";
        std::system(comando.c_str());
      }
      puntero = puntero->Next;
    }while(puntero != listaCircular);
  }
  std::string comando = "tree \"" + listaCircular->root_path + "\"";
  std::cout << "\nEl resultado final sería: " << std::endl;
  std::system(comando.c_str());
  return 1;
}

void eliminarRetornoDeCarro(std::string& cadena) { //DETECTA Y ELIMINA SALTOS DE LINEA INVISIBLES
  cadena.erase(std::remove(cadena.begin(), cadena.end(), '\r'), cadena.end());
}