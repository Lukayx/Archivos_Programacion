#include "../../Include/dataBaseManagement.h"
#include "menuOptions.cpp"

bool validation(Usuario& usuario, dbMAP database);
std::vector<int> userProfileAssignment(std::string userProfile, std::string database);
dbMAP leerEnv();
void signIn(std::string username, menuMAP menuOptions, dbMAP database);
bool confirmPermiss(Usuario& usuario, int opcion);
menuMAP crearMapa(Usuario& usuario, dbMAP database);
void eliminarRetornoDeCarro(std::string& cadena);

bool validation(Usuario& usuario, dbMAP database) {
  std::ifstream archivo(database["DB_USER"].c_str());
  std::string linea;
  if (!archivo.is_open()) {
    std::cout << "No se pudo abrir la base de datos del usuario" << std::endl;
    exit(1);
  }
  while (getline(archivo, linea)) {
    size_t pos = linea.find(usuario.u + ";"); // Buscar el nombre de usuario en la línea
    if (pos == 0) {
      std::string profile = linea.substr(usuario.u.length() + 1); // Obtener la parte después del nombre
      eliminarRetornoDeCarro(profile);
      usuario.options = userProfileAssignment(profile, database["DB_PROFILES"].c_str());
      usuario.userProfile = profile;
      archivo.close();
      std::cout << "\n-------Usuario Valido-------" << std::endl;

      system("clear");
      return true; // Usuario encontrado y opciones procesadas
    }
  }
  archivo.close();
  std::cout << "\n-------Usuario Invalido-------" << std::endl;

  system("clear");
  std::cout << std::endl << "Usted no se encuentra en la base de datos" << std::endl;
  return false; // Usuario no encontrado en la base de datos
}

std::vector<int> userProfileAssignment(std::string userProfile, std::string database){
  std::ifstream archivo(database);
  std::string linea;
  std::cout << "gatoo" << std::endl;
  if (!archivo.is_open()) {
    std::cout << "No se pudo abrir la base de datos de los Perfiles de Usuario" << std::endl;
    exit(1);
  }
  while(getline(archivo, linea)) {
    size_t first = linea.find_first_of(";");
    size_t pos = linea.find(userProfile + ";"); // Buscar el nombre de usuario en la línea
    if (pos == first+1) {
      std::string permissions = linea.substr(linea.find_last_of(";") + 1); // Obtener la parte después del nombre
      std::stringstream dd(permissions);
      std::string value;
      std::vector<int> v;
      while(getline(dd, value, ',')) {
        int i = std::stoi(value);
        std::cout << "perroo" << std::endl;
        v.push_back(i);
      }
      archivo.close();
      return v;
    }
  }
  std::cout << "\n---Error al buscar el perfil de usuario---\n" << std::endl;
  exit(1);
}

dbMAP leerEnv(){
  dbMAP database;
  std::ifstream archivo("../.env");
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
  
  std::ifstream archivoIndexFile(database["INVERTED_INDEX_FILE"]);
  if(!archivoIndexFile.is_open()){
    std:: cout << "El archivo de indice invertido no existe." << std::endl;
    exit(1);
  }
  archivoIndexFile.close();

  if(std::stoi(database["TOPK"]) < 4){
    std::cout << "La variable TOPK del .env debe ser mayor o igual a 4." << std::endl;
    exit(1);
  }

  if(database["PATH_FILES_OUT"]==database["PATH_FILES_IN"]){
    std::cout << "Los path PATH_FILES_IN y PATH_FILES_OUT no pueden ser iguales." << std::endl;
    exit(1);
  }
  if(std::stoi(database["AMOUNT_THREADS"])<=0 || std::stoi(database["AMOUNT_THREADS"]) > 10){
    std::cout << "La variable AMOUNT_THREADS como máximo puede ser 10." << std::endl;
    exit(1);
  }
  return database;
}

void signIn(std::string username, menuMAP menuOptions, dbMAP database) {
  std::string respuesta;
  int opcion;
  do {
    std::cout << " Desea Registrarse? (Si/No): ";
    std::cin >> respuesta;
  } while (respuesta != "Si" && respuesta != "No");
  if (respuesta == "Si") {
    std::ofstream archivo(database["DB_USER"].c_str(), std::ios::app);
    if (!archivo.is_open()) {
      std::cout << "No se pudo abrir la base de datos de Usuarios" << std::endl;
      exit(1);
    }
    std::string linea = username + ";";
    std::string iterador;
    std::map<int,std::string> perfiles;
    int j = 1;
    std::ifstream perfilFile(database["DB_PROFILES"].c_str());
    while(getline(perfilFile, iterador)){
      opcion = j++;
      size_t inicio = iterador.find_first_of(";")+1;
      std::string perfil = iterador.substr(inicio,iterador.find_last_of(";")-inicio);
      perfiles[opcion] = perfil;
    }
    perfilFile.close();
    std::map<int, std::string>::iterator check;
    do{
      std::cout << "\nQue Perfil de usuario desea ser? " << std::endl;
      for(auto i : perfiles) std::cout << i.first <<")-" << i.second <<std::endl;
      std::cin >> opcion; 
      check = perfiles.find(opcion);
    }while(check == perfiles.end());
    linea += perfiles[opcion];
    archivo << std::endl << linea;
    system("clear");
    std::cout << "===============================================================================" << std::endl;
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

menuMAP crearMapa(Usuario& usuario, dbMAP database){
  menuMAP mapa;
  std::ifstream archivoMenu(database["DB_MENU"].c_str());
  std::string linea;

  if (!archivoMenu.is_open()) {
    std::cout << "No se pudo abrir el archivo del menu" << std::endl;
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
    eliminarRetornoDeCarro(valor);
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
      funcion = [database](Usuario&) { prepararIndiceInvertido(database); }; 
    } else if (valor == "crearIndiceInvertido") {
      funcion = [database](Usuario&) { crearIndiceInvertido(database); }; 
    } else if (valor == "buscador") {
      funcion = [database](Usuario&) { llamarBuscador(database); }; 
    } else {
      funcion = [](Usuario&) { opcionIndefinida(); };
    } 
    mapa[opcion] = std::make_pair(label, funcion);
  }
  archivoMenu.close();
  return mapa;
}

void eliminarRetornoDeCarro(std::string& cadena) {
  cadena.erase(std::remove(cadena.begin(), cadena.end(), '\r'), cadena.end());
}