#include "menuOptions.cpp"
#include <functional>
#include <windows.h>
#include <unordered_map>

using namespace std;

bool validation(Usuario& usuario, unordered_map<string, string> dataBase);
vector<int> userProfileAssignment(string userProfile, string dataBase);
unordered_map<string, string> leerEnv();
void signIn(string username, map<int, pair<string, function<void(Usuario& usuario)>>> menuOptions, string dataBase);
bool confirmPermiss(Usuario& usuario, int opcion);
map<int, pair<string, function<void(Usuario& usuario)>>> crearMapa(Usuario& usuario, string dataBase);

bool validation(Usuario& usuario, unordered_map<string, string> dataBase) {
  ifstream archivo(dataBase["USER"]);
  string linea;
  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo";
    exit(1);
  }
  while (getline(archivo, linea)) {
    size_t pos = linea.find(usuario.u + ";"); // Buscar el nombre de usuario en la línea
    if (pos == 0) {
      string profile = linea.substr(usuario.u.length() + 1); // Obtener la parte después del nombre
      usuario.options = userProfileAssignment(profile, dataBase["PROFILES"]);
      usuario.userProfile = profile;
      archivo.close();
      cout << "\n-------Usuario Valido-------" << endl;
      Sleep(1000);
      system("cls");
      return true; // Usuario encontrado y opciones procesadas
    }
  }
  archivo.close();
  cout << "\n-------Usuario Invalido-------" << endl;
  cout << endl << "Usted no se encuentra en la base de datos" << endl;
  return false; // Usuario no encontrado en la base de datos
}

vector<int> userProfileAssignment(string userProfile, string dataBase){
  ifstream archivo(dataBase);
  string linea;
  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo";
    exit(1);
  }
  while(getline(archivo, linea)) {
    size_t pos = linea.find(userProfile + ";"); // Buscar el nombre de usuario en la línea
    if (pos == 0) {
      string permissions = linea.substr(userProfile.length() + 1); // Obtener la parte después del nombre
      stringstream dd(permissions);
      string value;
      vector<int> v;
      while(getline(dd, value, ',')) {
        int i = stoi(value);
        v.push_back(i);
      }
      archivo.close();
      return v;
    }
  }
  cout << "\n---Error al buscar el perfil de usuario---\n";
  exit(1);
}

unordered_map<string, string> leerEnv(){
  unordered_map<string, string> dataBase;
  ifstream archivo(".env");
  string key;
  string linea;
  size_t indice;
  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo";
    exit(1);
  }
  while (getline(archivo, linea)){
    size_t pos = linea.find("DB_");
    if(pos == 0){
      indice = linea.find('=');
      key = linea.substr(3, indice-3);
      dataBase[key] = linea.substr(indice + 1, linea.length());
      cout << key << " --- " << dataBase[key] << endl;
    } 
  }
  archivo.close();
  return dataBase;
}

void signIn(string username, map<int, pair<string, function<void(Usuario& usuario)>>> menuOptions, string dataBase) {
  string respuesta;
  do {
    cout << " Desea Registrarse? (Si/No): ";
    cin >> respuesta;
  } while (respuesta != "Si" && respuesta != "No");
  if (respuesta == "Si") {
    ofstream archivo(dataBase, ios::app);
    string respuesta;
    bool unaVez = false;
    if (!archivo.is_open()) {
      cout << "No se pudo abrir la base de datos de Usuarios";
      exit(1);
    }
    string linea = username + ";";
    cout << linea << endl;
    cout << "Que permisos desea tener:" << endl;
    for(const auto& val : menuOptions){
      int key = val.first;
      if(key == 0 || menuOptions.find(key+1) == menuOptions.end()) continue;
      do{
        cout << "Permiso a '"<< val.second.first <<"' (Si/No): ";
        cin >> respuesta;
      }while(respuesta != "Si" && respuesta != "No");
      if(respuesta == "Si"){
        if(!unaVez){
          linea = linea + to_string(key);
        } else {
          linea = linea + "," + to_string(key);
        }
        unaVez = true;
      }
    }
    cout << linea << endl;
    if(unaVez){
      archivo << endl << linea;
      cout << endl << "------Se ha registrado exitosamente------\n" << endl;  
    } else {
      cout << endl << "--------No ha podido registrarse--------\n" << endl;  
      cout << "Debe de tener almenos un permiso." << endl;
    }
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

map<int, pair<string, function<void(Usuario& usuario)>>> crearMapa(Usuario& usuario, string dataBase){
  map<int, pair<string, function<void(Usuario& usuario)>>> mapa;

  ifstream archivoMenu(dataBase);
  string linea;

  if (!archivoMenu.is_open()) {
    cout << "No se pudo abrir el archivo";
    exit(1);
  }

  while (getline(archivoMenu, linea)) {
    string x;
    stringstream dd(linea);
    string valor;
    getline(dd, valor, ',');
    int opcion = stoi(valor);

    getline(dd, valor, ',');
    string label = valor;

    getline(dd, valor, ',');
    function<void(Usuario&)> funcion;

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
    mapa[opcion] = make_pair(label, funcion);
  }
  archivoMenu.close();
  return mapa;
}