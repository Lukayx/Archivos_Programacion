#include "Functions/databaseManagement.cpp"
#include <cstdlib>
#include <limits>
#include <filesystem>

namespace fs = std::filesystem;
int pid = getpid();
void getout(Usuario& usuario);

int main(int argc, char **argv) {
  std::string path, valor;
  Usuario usuario;
  int c;
  while ((c = getopt(argc, argv, "u:v:f:t:i:o:")) != -1) {
    switch (c) {
      case 'u': {
        usuario.u = optarg;
        break;
      }
      case 'v': {
        std::stringstream ss(optarg);
        while (getline(ss, valor, ';')) {
          int i = std::stoi(valor);
          usuario.v.push_back(i);
        }
        break;
      }
      case 'f': {
        path = optarg;
        if (path.find_last_of('/') != std::string::npos) {
          std::string directoryPath = path.substr(0, path.find_last_of('/'));
          if (!(fs::exists(directoryPath) && fs::is_directory(directoryPath))) {
            std::cout << "La ruta dada en el parametro '-f' no es válida, intente ingresarla nuevamente." << std::endl;
            exit(1);
          }
        }
        usuario.path = path;
        break;
      }
      case 't': {
        usuario.text = optarg;
        break;
      }
      case 'i': {
        usuario.input = optarg;
        std::ifstream archivo(usuario.input, std::ios::in);
        if (!archivo.is_open()) {
          std::cout << "La ruta dada en el parametro '-i' no se pudo encontrar, revise bien la ruta ingresada." << std::endl;
          std::cout << "Se cerrara el programa." << std::endl;
          exit(1);
        }
        archivo.close();
        // std::streampos fileSize = archivo.tellg(); // Obtener tamaño del archivo
        // if (fileSize == -1) {
        //   std::cout << "No se pudo obtener el tamaño del archivo." << std::endl;
        //   exit(1);
        // } else if (fileSize < 1048576) {
        //   std::cout << "El archivo pasado por el input pesa menos de 1 MB" << std::endl;
        //   exit(1);
        // }
        break;
      }
      case 'o': {
        usuario.output = optarg;
        break;
      }
    }
  }
  system("clear");
  getout(usuario);
  return 0;
}

void getout(Usuario& usuario) {
  dbMAP database = leerEnv();
  menuMAP menuOptions = crearMapa(usuario, database);
  if (validation(usuario, database)) {
    bool respuestaValida = true;
    bool opcion_8 = false;
    bool opcion_9 = false;
    std::string respuesta;
    while (true) {
      std::cout << "\nUsuario Actual: " << usuario.u << " / " << usuario.userProfile << " / Pid = " << pid << std::endl;
      std::cout << "\nOPCIONES DE MENÚ\n" << std::endl;
      for (const auto& option : menuOptions) {
        std::cout << option.first << ")- " << option.second.first << std::endl;
      }
      do {
        std::cout << "\nElija una Opcion: ";
        std::cin >> respuesta;
        respuestaValida = true;
        for (char a : respuesta) {
          if (!isdigit(a)) {
            respuestaValida = false;
            std::cout << "\nOpcion invalida, Elija denuevo: ";
            break;
          }
        }
      } while (!respuestaValida);
      int opcion = std::stoi(respuesta);
      if (!(opcion>10 && opcion<14)) system("clear");
      if (confirmPermiss(usuario, opcion) || opcion == 0 || opcion > 7) {
        if (menuOptions.find(opcion) != menuOptions.end()) {
          if(opcion < 8 || opcion > 10){
            if(!(opcion > 10 && opcion < 14)){
              std::cout << "===============================================================================" << std::endl;
            } 
            menuOptions[opcion].second(usuario);
          } else {
            if(opcion == 8){
              std::cout << "===============================================================================" << std::endl;
              opcion_8 = true;
              menuOptions[opcion].second(usuario);
            } else if(opcion == 9){
              std::cout << "===============================================================================" << std::endl;
              if(opcion_8){
                opcion_9 = true;
                menuOptions[opcion].second(usuario);
              } else {
                std::cout << "Tiene que haber usado la opcion 8 al menos una vez." << std::endl;
              }
            } else if (opcion == 10){
              if(opcion_9){
                menuOptions[opcion].second(usuario);
                std::cout << "===============================================================================" << std::endl;
                std::cout << "Opcion 10 ejecutada exitosamente." << std::endl;
              } else {
                std::cout << "===============================================================================" << std::endl;
                std::cout << "Tiene que haber usado la opcion 9 al menos una vez." << std::endl;
              }
            }
          }
        } else {
          std::cout << "===============================================================================" << std::endl;
          std::cout << "Opcion invalida." << std::endl;
        }
      } else {
        std::cout << "===============================================================================" << std::endl;
        std::cout << "No tiene permiso para acceder a esta operacion." << std::endl;
      }
      std::cout << "===============================================================================" << std::endl;
    }
  } else {
    signIn(usuario.u, database);
  }
  std::cout << "===============================================================================" << std::endl;
  std::cout << "Que tenga un buen dia" << std::endl;
  std::cout << "===============================================================================" << std::endl;
}