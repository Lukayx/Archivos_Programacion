#include "Functions/databaseManagement.cpp"
#include <cstdlib>
#include <limits>
#include <filesystem>

namespace fs = std::filesystem;

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
        std::ifstream archivo(usuario.input, std::ios::ate);
        if (!archivo.is_open()) {
          std::cout << "La ruta dada en el parametro '-i' no se pudo encontrar, revise bien la ruta ingresada." << std::endl;
          std::cout << "Se cerrara el programa." << std::endl;
          exit(1);
        }
        std::streampos fileSize = archivo.tellg(); // Obtener tamaño del archivo
        archivo.close();
        if (fileSize == -1) {
          std::cout << "No se pudo obtener el tamaño del archivo." << std::endl;
          exit(1);
        } else if (fileSize < 1048576) {
          std::cout << "El archivo pasado por el input pesa menos de 1 MB" << std::endl;
          exit(1);
        }
        break;
      }
      case 'o': {
        usuario.output = optarg;
        break;
      }
    }
  }
  system("cls");
  getout(usuario);
  return 0;
}

void getout(Usuario& usuario) {
  dbMAP dataBase = leerEnv();
  menuMAP menuOptions = crearMapa(usuario, dataBase["DB_MENU"]);
  if (validation(usuario, dataBase)) {
    bool condition = true;
    bool entradaValida = true;
    std::string respuesta;
    while (condition) {
      std::cout << "\nUsuario Actual: " << usuario.u << " / " << usuario.userProfile << std::endl;
      std::cout << "\nOPCIONES DE MENU\n" << std::endl;
      for (const auto& option : menuOptions) {
        std::cout << option.first << ")- " << option.second.first << std::endl;
      }
      do {
        std::cout << "\nElija una Opcion: ";
        std::cin >> respuesta;
        entradaValida = true;
        for (char a : respuesta) {
          if (!isdigit(a)) {
            entradaValida = false;
            std::cout << "\nOpcion invalida, Elija denuevo: ";
            break;
          }
        }
      } while (!entradaValida);
      system("cls");
      std::cout << "==================================================" << std::endl;
      int opcion = std::stoi(respuesta);
      if (confirmPermiss(usuario, opcion) || opcion == 0 || opcion > 7) {
        if (menuOptions.find(opcion) != menuOptions.end()) {
          menuOptions[opcion].second(usuario);
        } else {
          std::cout << "Opcion invalida." << std::endl;
        }
      } else {
        std::cout << "No tiene permiso para acceder a esta operacion." << std::endl;
      }
      std::cout << "===================================================" << std::endl;
    }
  } else {
    signIn(usuario.u, menuOptions, dataBase["DB_USER"]);
  }
  std::cout << "Que tenga un buen dia" << std::endl;
  std::cout << "===================================================" << std::endl;
}
