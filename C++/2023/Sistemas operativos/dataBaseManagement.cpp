#include "menuOptions.cpp"
#include <functional>
#include <windows.h>
#include <unordered_map>

using namespace std;

unordered_map<string, string> db;

void leerEnv(unordered_map<string, string>& db);
bool validation(Usuario& usuario);
vector<int> userProfileAssignment(string userProfile);
bool confirmPermiss(Usuario& usuario, int opcion);
void signIn(string username, map<int, pair<string, function<void(Usuario& usuario)>>> menuOptions);
map<int, pair<string, function<void(Usuario& usuario)>>> crearMapa(Usuario& usuario);

bool validation(Usuario& usuario) {
  ifstream archivo("Bases_de_datos/db.txt");
  string linea;
  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo";
    exit(1);
  }

  while (getline(archivo, linea)) {
    size_t pos = linea.find(usuario.u + ";"); // Buscar el nombre de usuario en la línea
    if (pos == 0) {
      string profile = linea.substr(usuario.u.length() + 1); // Obtener la parte después del nombre
      usuario.options = userProfileAssignment(profile);
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

vector<int> userProfileAssignment(string userProfile){
  ifstream archivo("Bases_de_datos/userProfiles.txt");
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

void leerEnv(unordered_map<string, string>& db){
  ifstream archivo(".env");
  string key;
  size_t i;
  string linea;
  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo";
    exit(1);
  }
  while (getline(archivo, linea)){
    size_t pos = linea.find("DB_");
    if(pos == 0){
      i = linea.find("=");
      key = linea.substr(3, i);
      db[key] = linea.substr(i+1, linea.length());
      cout << key << " --- " << db[key];
    } 
  }
  archivo.close();
}

void signIn(string username, map<int, pair<string, function<void(Usuario& usuario)>>> menuOptions) {
  string respuesta;
  do {
    cout << " Desea Registrarse? (Si/No): ";
    cin >> respuesta;
  } while (respuesta != "Si" && respuesta != "No");
  if (respuesta == "Si") {
    ofstream archivo("Bases_de_datos/db.txt", ios::app);
    string respuesta;
    bool unaVez = false;
    if (!archivo.is_open()) {
      cout << "No se pudo abrir el archivo";
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

map<int, pair<string, function<void(Usuario& usuario)>>> crearMapa(Usuario& usuario){
  map<int, pair<string, function<void(Usuario& usuario)>>> mapa;

  ifstream archivoMenu("Bases_de_datos/menu.txt");
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
    } else {
      funcion = [](Usuario&) { opcionIndefinida(); };
    }
    mapa[opcion] = make_pair(label, funcion);
  }
  archivoMenu.close();
  return mapa;
}