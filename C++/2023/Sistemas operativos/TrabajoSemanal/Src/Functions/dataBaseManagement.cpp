#include "menuOptions.cpp"
#include "../../Include/databaseManagement.h"

bool validation(Usuario& usuario, dbMAP database);
std::vector<int> userProfileAssignment(std::string userProfile, std::string database);
dbMAP leerEnv();
void signIn(std::string username, menuMAP menuOptions, std::string database);
bool confirmPermiss(Usuario& usuario, int opcion);
menuMAP crearMapa(Usuario& usuario, std::string database);

bool validation(Usuario& usuario, dbMAP database) {
  std::ifstream archivo(database["USER"]);
  std::string linea;
  if (!archivo.is_open()) {
    std::cout << "No se pudo abrir la base de datos del usuario";
    exit(1);
  }
  while (getline(archivo, linea)) {
    size_t pos = linea.find(usuario.u + ";"); // Buscar el nombre de usuario en la línea
    if (pos == 0) {
      std::string profile = linea.substr(usuario.u.length() + 1); // Obtener la parte después del nombre
      usuario.options = userProfileAssignment(profile, database["DB_PROFILES"]);
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

std::vector<int> userProfileAssignment(std::string userProfile, std::string database){
  std::ifstream archivo(database);
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

dbMAP leerEnv(){
  dbMAP database;
  std::ifstream archivo("../.env");
  std::string key;
  std::string linea;
  size_t indice;
  if (!archivo.is_open()) {
    std::cout << "No se pudo abrir el archivo .env" << std::endl;
    std::cout << "Verifique de que se encuentre en la carpeta actual";
    exit(1);
  }
  while(getline(archivo, linea)){
    int pos = linea.find("=");
    key = line.substr(0, pos); //Recorta el nombre de la variable
    map[key] = linea.substr(pos+1, linea.length()); //Almacena el contenido de la variable del .env al map
  }
  if(database["PATH_FILES_OUT"]==database["PATH_FILES_IN"]){
    std::cout << "Los path PATH_FILES_IN y PATH_FILES_OUT no pueden ser iguales." << std::endl;
    exit(1);
  }

  if(database["AMOUNT_THREADS"]<0 || database["AMOUNT_THREADS"] > 10){
    std::cout << "La variable AMOUNT_THREADS como máximo puede ser 10." << std::endl;
    exit(1);
  }

  archivo.close();
  return database;
}

void signIn(std::string username, menuMAP menuOptions, std::string database) {
  std::string respuesta;
  do {
    std::cout << " Desea Registrarse? (Si/No): ";
    std::cin >> respuesta;
  } while (respuesta != "Si" && respuesta != "No");
  if (respuesta == "Si") {
    std::ofstream archivo(database, std::ios::app);
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

menuMAP crearMapa(Usuario& usuario, std::string database){
  menuMAP mapa;

  std::ifstream archivoMenu(database);
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
      funcion = [](Usuario& usuario) { crearArchivo(usuario); }; 
    } else if (valor == "agregarTexto") {
      funcion = [](Usuario& usuario) { agregarTexto(usuario); }; 
    } else if (valor == "contarPalabras") {
      funcion = [](Usuario& usuario) { conteoPalabras(usuario); }; 
    } else if (valor == "prepararIndiceInvertido") {
      funcion = [](Usuario& usuario) { prepararIndiceInvertido(usuario); }; 
    } else if (valor == "crearIndiceInvertido") {
      funcion = [](Usuario& usuario) { crearIndiceInvertido(usuario); }; 
    } else {
      funcion = [](Usuario&) { opcionIndefinida(); };
    } 
    mapa[opcion] = std::make_pair(label, funcion);
  }
  archivoMenu.close();
  return mapa;
}
