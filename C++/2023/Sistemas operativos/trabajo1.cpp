#include <functional>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Usuario {
  string u;
  vector<int> options;
};

void getout(string u, vector<int> v, string path, string texto);
void signIn(string username, map<int, pair<string, function<void(vector<int>)>>> menuOptions);
bool validation(Usuario& usuario);
bool confirmPermiss(Usuario& usuario, int num);
void salir();
void sumatoria(vector<int> v);
void promedio(vector<int> v);
void moda(vector<int> v);
void contar(vector<int> v);
void crearArchivo(string path);
void agregarTexto(string text, string path);
void opcionIndefinida();
map<int, pair<string, function<void(vector<int>)>>> crearMapa(string path, string texto);

int main(int argc, char **argv) {
  string u;
  string valor;
  string path;
  string texto;
  vector<int> v;
  int c;
  while ((c = getopt(argc, argv, "u:v:f:t:")) != -1) {
    switch (c) {
      case 'u': {
        u = optarg;
        break;
      }
      case 'v': {
        stringstream ss(optarg);
        while (getline(ss, valor, ';')) {
          for(const auto& a : valor){
            if(!isdigit(a) && a != '-'){
              cout << "Vector incorrecto, escribalo bien e intente nuevamente." << endl;
              exit(1);
            }
          }
          int i = stoi(valor);
          v.push_back(i);
        }
        break;
      }
      case 'f': {
        path = optarg;
        break;
      }
      case 't': {
        texto = optarg;
        break;
      }
    }
  }
  getout(u,v,path,texto);
  return 0;
}

void getout(string u, vector<int> v, string path, string texto) {
  Usuario usuario;
  usuario.u = u;
  map<int, pair<string, function<void(vector<int>)>>> menuOptions = crearMapa(path,texto);

  if(validation(usuario)) {
    bool condition = true;
    bool entradaValida = true;
    string respuesta;
    cout << "\nOPCIONES DE MENU\n" << endl;
    for (const auto& option : menuOptions){
      cout << option.first << ")- " << option.second.first << endl;
    }
    while(condition){
      do{
        cout << "\nElija una Opcion: ";
        cin >> respuesta;
        entradaValida = true;
        for(char a : respuesta){
          if(!isdigit(a)){
            entradaValida = false;
            cout << "\nOpcion invalida, Elija denuevo: ";
            break;
          }
        }
      }while(!entradaValida);
      int opcion = stoi(respuesta);
      if (confirmPermiss(usuario, opcion) || opcion==0 || opcion>6) {
        if (menuOptions.find(opcion) != menuOptions.end()) {
            menuOptions[opcion].second(v);
        } else {
            cout << "Opcion invalida." << endl;
        }
      } else {
        cout << "No tiene permiso para acceder a esta operacion." << endl;
      }
    }
  } else {
    signIn(u, menuOptions);
  }
  cout << "Que tenga un buen dia" << endl;
}

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
      string val = linea.substr(usuario.u.length() + 1); // Obtener la parte después del nombre
      stringstream dd(val);
      string x;
      while (getline(dd, x, ',')) {
        int i = stoi(x);
        usuario.options.push_back(i);
      }
      archivo.close();
      cout << "\n-------Usuario Valido-------" << endl;
      return true; // Usuario encontrado y opciones procesadas
    }
  }
  archivo.close();
  cout << "\n-------Usuario Invalido-------" << endl;
  cout << endl << "Usted no se encuentra en la base de datos" << endl;
  return false; // Usuario no encontrado en la base de datos
}

void signIn(string username, map<int, pair<string, function<void(vector<int>)>>> menuOptions) {s
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

bool confirmPermiss(Usuario& usuario, int num) {
  for(int i : usuario.options){
    if(i == num){
      return true;
    }
  }
  return false;
}

void salir(){
  cout << "Que tenga un buen dia" << endl;
  exit(1);
}

void sumatoria(vector<int> v){
  int num = 0;
  for(int i : v){
    num += i;
  }
  cout << "La sumatoria del vector es: " << num << endl;
}

void promedio(vector<int> v){
  int num = 0;
  for(int i : v){
    num += i;
  }
  cout << "El promedio del vector es: " << float(num/v.size()) << endl;
}

void moda(vector<int> v){
  map<int, int> frecuencias;
  for(int num : v) {
      frecuencias[num]++;
  }

  int moda = 0;  // Valor de la moda
  int maxFrecuencia = 0;  // Frecuencia máxima

  // Encontrar la moda
  for(const auto& numero : frecuencias) {
    if(numero.second > maxFrecuencia) {
        moda = numero.first;
        maxFrecuencia = numero.second;
    }
  }
  cout << "La moda del vector es: " << moda << endl;
}

void contar(vector<int> v){
  cout << "El numero de elementos del vector es: " << v.size() << endl;
}

void crearArchivo(string path){
  ifstream existenciaArchivo(path);
  if(existenciaArchivo){
    cout << "El archivo ya existe en la ruta especificada." << endl;
    existenciaArchivo.close();
    return;
  }
  ofstream archivo(path,ios::out);
  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo";
    exit(1);
  }

  archivo.close();
  cout << "Archivo creado exitosamente." << endl;
}

void agregarTexto(string text, string path){
  ifstream existenciaArchivo(path);
  if(!existenciaArchivo){
    cout << "El archivo al que intentas acceder en la ruta especificada no existe." << endl;
    existenciaArchivo.close();
    return;
  }

  ofstream archivo(path,ios::out);
  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo";
    exit(1);
  }
  archivo << text;
  archivo.close();
  cout << "Texto agregado al archivo exitosamente." << endl;
}

void opcionIndefinida(){
  cout << "La opcion que elejiste aun no ha sido implementada." << endl;
}

map<int, pair<string, function<void(vector<int>)>>> crearMapa(string path, string texto){
  map<int, pair<string, function<void(vector<int>)>>> mapa;

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
    function<void(vector<int>)> funcion;

    if (valor == "salir") {
      funcion = [](vector<int>) { salir(); };
    } else if (valor == "sumatoria") {
      funcion = [](vector<int> v) { sumatoria(v); };
    } else if (valor == "promedio") {
      funcion = [](vector<int> v) { promedio(v); };
    } else if (valor == "moda") {
      funcion = [](vector<int> v) { moda(v); };
    } else if (valor == "contar") {
      funcion = [](vector<int> v) { contar(v); };
    } else if (valor == "crearArchivo") {
      funcion = [path](vector<int>) { crearArchivo(path); }; // Agrega la ruta que necesites
    } else if (valor == "agregarTexto") {
      funcion = [texto,path](vector<int>) { agregarTexto(texto,path); }; // Agrega el texto que necesites
    } else {
      funcion = [](vector<int>) { opcionIndefinida(); };
    }
    mapa[opcion] = make_pair(label, funcion);
  }
  archivoMenu.close();
  return mapa;
}