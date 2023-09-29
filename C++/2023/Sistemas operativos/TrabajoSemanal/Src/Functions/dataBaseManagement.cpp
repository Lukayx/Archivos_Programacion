#include "menuOptions.cpp"
#include "../../Include/dataBaseManagement.h"

bool validation(Usuario& usuario, std::unordered_map<std::string, std::string> dataBase);
std::vector<int> userProfileAssignment(std::string userProfile, std::string dataBase);
std::unordered_map<std::string, std::string> leerEnv();
void signIn(std::string username, std::map<int, std::pair<std::string, std::function<void(Usuario& usuario)>>> menuOptions, std::string dataBase);
bool confirmPermiss(Usuario& usuario, int opcion);
std::map<int, std::pair<std::string, std::function<void(Usuario& usuario)>>> crearMapa(Usuario& usuario, std::string dataBase);

bool validation(Usuario& usuario, std::unordered_map<std::string, std::string> dataBase) {
  std::ifstream archivo(dataBase["USER"]);
  std::string linea;
  if (!archivo.is_open()) {
    std::cout << "No se pudo abrir la base de datos del usuario";
    exit(1);
  }
  while (getline(archivo, linea)) {
    size_t pos = linea.find(usuario.u + ";"); // Buscar el nombre de usuario en la línea
    if (pos == 0) {
      std::string profile = linea.substr(usuario.u.length() + 1); // Obtener la parte después del nombre
      usuario.options = userProfileAssignment(profile, dataBase["PROFILES"]);
      usuario.userProfile = profile;
      archivo.close();
      std::cout << "\n-------Usuario Valido-------" << std::endl;
      ::Sleep(1000);
      system("cls");
      return true; // Usuario encontrado y opciones procesadas
    }
  }
  archivo.close();
  std::cout << "\n-------Usuario Invalido-------" << std::endl;
  ::Sleep(1000);
  system("cls");
  std::cout << std::endl << "Usted no se encuentra en la base de datos" << std::endl;
  return false; // Usuario no encontrado en la base de datos
}

std::vector<int> userProfileAssignment(std::string userProfile, std::string dataBase){
  std::ifstream archivo(dataBase);
  std::string linea;
  if (!archivo.is_open()) {
    std::cout << "No se pudo abrir la base de datos de los Perfiles de Usuario";
    exit(1);
  }
  while(getline(archivo, linea)) {
    size_t pos = linea.find(userProfile + ";"); // Buscar el nombre de usuario en la línea
    if (pos == 0) {
      std::string permissions = linea.substr(userProfile.length() + 1); // Obtener la parte después del nombre
      std::stringstream dd(permissions);
      std::string value;
      std::vector<int> v;
      while(getline(dd, value, ',')) {
        int i = std::stoi(value);
        v.push_back(i);
      }
      archivo.close();
      return v;
    }
  }
  std::cout << "\n---Error al buscar el perfil de usuario---\n";
  exit(1);
}

std::unordered_map<std::string, std::string> leerEnv(){
  std::unordered_map<std::string, std::string> dataBase;
  std::ifstream archivo("../.env");
  std::string key;
  std::string linea;
  size_t indice;
  if (!archivo.is_open()) {
    std::cout << "No se pudo abrir el archivo .env" << std::endl;
    std::cout << "Verifique de que se encuentre en la carpeta actual";
    exit(1);
  }
  while (getline(archivo, linea)){
    size_t pos = linea.find("DB_");
    if(pos == 0){
      indice = linea.find('=');
      key = linea.substr(3, indice-3);
      dataBase[key] = linea.substr(indice + 1, linea.length());
      // std::cout << key << " --- " << dataBase[key] << std::endl;
    } 
  }
  archivo.close();
  return dataBase;
}

void signIn(std::string username, std::map<int, std::pair<std::string, std::function<void(Usuario& usuario)>>> menuOptions, std::string dataBase) {
  std::string respuesta;
  do {
    std::cout << " Desea Registrarse? (Si/No): ";
    std::cin >> respuesta;
  } while (respuesta != "Si" && respuesta != "No");
  if (respuesta == "Si") {
    std::ofstream archivo(dataBase, std::ios::app);
    int respuesta;
    if (!archivo.is_open()) {
      std::cout << "No se pudo abrir la base de datos de Usuarios";
      exit(1);
    }
    std::string linea = username + ";";
    do{
      std::cout << "\nQue tipo de usuario desea ser? " << std::endl;
      std::cout << "1)-admin" << std::endl;
      std::cout << "2)-userGeneral" << std::endl; 
      std::cout << "3)-userRookie" << std::endl;
      std::cin >> respuesta;
    } while(respuesta < 1 || respuesta > 3);
    if(respuesta == 1){
      linea += "admin";
    } else if(respuesta == 2){
      linea += "userGeneral";
    } else {
      linea += "userRookie";
    }
    archivo << std::endl << linea;
    system("cls");
    std::cout << std::endl << "------Se ha registrado exitosamente------\n" << std::endl;  
    archivo.close();
  }
}

bool confirmPermiss(Usuario& usuario, int opcion) {
  for(int i : usuario.options){
    if(i == opcion){
      return true;
    }
  }
  return false;
}

std::map<int, std::pair<std::string, std::function<void(Usuario& usuario)>>> crearMapa(Usuario& usuario, std::string dataBase){
  std::map<int, std::pair<std::string, std::function<void(Usuario& usuario)>>> mapa;

  std::ifstream archivoMenu(dataBase);
  std::string linea;

  if (!archivoMenu.is_open()) {
    std::cout << "No se pudo abrir el archivo del menu";
    exit(1);
  }

  while (getline(archivoMenu, linea)) {
    std::string x;
    std::stringstream dd(linea);
    std::string valor;
    getline(dd, valor, ',');
    int opcion = std::stoi(valor);

    getline(dd, valor, ',');
    std::string label = valor;

    getline(dd, valor, ',');
    std::function<void(Usuario&)> funcion;

    if (valor == "salir") {
      funcion = [](Usuario&) { salir(); };
    } else if (valor == "sumatoria") {
      funcion = [](Usuario& usuario) { sumatoria(usuario); };
    } else if (valor == "promedio") {
      funcion = [](Usuario& usuario) { promedio(usuario); };
    } else if (valor == "moda") {
      funcion = [](Usuario& usuario) { moda(usuario); };
    } else if (valor == "contar") {
      funcion = [](Usuario& usuario) { contar(usuario); };
    } else if (valor == "crearArchivo") {
      funcion = [](Usuario& usuario) { crearArchivo(usuario); }; // Agrega la ruta que necesites
    } else if (valor == "agregarTexto") {
      funcion = [](Usuario& usuario) { agregarTexto(usuario); }; // Agrega el texto que necesites
    } else if (valor == "contarPalabras") {
      funcion = [](Usuario& usuario) { conteoPalabras(usuario); }; // Agrega el texto que necesites
    } else {
      funcion = [](Usuario&) { opcionIndefinida(); };
    }
    mapa[opcion] = std::make_pair(label, funcion);
  }
  archivoMenu.close();
  return mapa;
}
