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

void getout(string u, vector<int> v);
void signIn(string username);
bool validation(Usuario& usuario);
bool confirmPermiss(Usuario& usuario, int num);
void sumatoria(vector<int> v);
void promedio(vector<int> v);
void moda(vector<int> v);
void conteo(vector<int> v);
int gatito(int c, string d);

int main(int argc, char **argv) {
  string u;
  string valor;
  vector<int> v;
  int c;

  while ((c = getopt(argc, argv, "u:v:")) != -1) {
    switch (c) {
      case 'u': {
        u = optarg;
        break;
      }
      case 'v': {
        stringstream ss(optarg);
        while (getline(ss, valor, ';')) {
          int i = stoi(valor);
          v.push_back(i);
        }
        break;
      }
    }
  }

  getout(u, v);
  return 0;
}

void getout(string u, vector<int> v) {
  Usuario usuario;
  usuario.u = u;

  if(validation(usuario)) {
    cout << "\n-------Usuario Valido-------" << endl;
    cout << "\nOperaciones" << endl;
    cout << " 1)-Realizar sumatoria del vector" << endl;
    cout << " 2)-Realizar promedio del vector" << endl;
    cout << " 3)-Realizar moda del vector" << endl;
    cout << " 4)-Contar elementos del vector" << endl;
    cout << " 0)-SALIR" << endl;
    int c;
    bool condition = true;
    bool entradaValida = false;
    while(condition){
      cout << "\nElija una Opcion: ";
      while(!entradaValida){
        cin >> c;
        entradaValida = true;
        for(char a : c){
          if(!isdigit(a)){
            entradaValida = false;
            cout << "\nOpcion invalida, Elija denuevo: ";
            break;
          }
        }
      }
      switch(c){
        case 1:
          if(confirmPermiss(usuario, c)){
            sumatoria(v);
          } else {
            cout << "No tiene permiso para acceder a esta operacion." << endl;
          }
          break;
        case 2:
          if(confirmPermiss(usuario, c)){
            promedio(v);
          } else {
            cout << "No tiene permiso para acceder a esta operacion." << endl;
          }
          break;
        case 3:
          if(confirmPermiss(usuario, c)){
            moda(v);
          } else {
            cout << "No tiene permiso para acceder a esta operacion." << endl;
          }
          break;
        case 4:
          if(confirmPermiss(usuario, c)){
            conteo(v);
          } else {
            cout << "No tiene permiso para acceder a esta operacion." << endl;
          }
          break;
        case 0:
          condition = false;
          break;
        default:
          cout << "Esa opcion no esta disponible por el momento."
          break;
      }
    }
  } else {
    string respuesta;
    cout << "\n-------Usuario Invalido-------" << endl;
    cout << endl << "Usted no se encuentra en la base de datos" << endl;
    do {
      cout << " Desea Registrarse? (Si/No): ";
      cin >> respuesta;
    } while (respuesta != "Si" && respuesta != "No");
    if (respuesta == "Si") 
      signIn(u);
  }
  cout << "Que tenga un buen dia" << endl;
}

bool validation(Usuario& usuario) {
  ifstream archivo("db.txt");
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
      return true; // Usuario encontrado y opciones procesadas
    }
  }

  archivo.close();
  return false; // Usuario no encontrado en la base de datos
}



void signIn(string username) {
  ofstream archivo("db.txt", ios::app);
  string respuesta;
  string text[] = {
  " Realizar sumatoria del vector",
  " Realizar promedio del vector",
  " Realizar moda del vector",
  " Contar elementos del vector"
  };
  int i = 0;
  bool unaVez = false;

  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo";
    exit(1);
  }
  string linea = username + ";";
  cout << linea << endl;
  cout << "Que permisos desea tener:" << endl;
  while (i<4){
    do{
      cout << text[i] <<" (Si/No): ";
      cin >> respuesta;
    }while(respuesta != "Si" && respuesta != "No");
    i++;
    if(respuesta == "Si"){
      if(!unaVez){
        linea = linea + to_string(i);
      } else {
        linea = linea + "," + to_string(i);
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

bool confirmPermiss(Usuario& usuario, int num) {
  for(int i : usuario.options){
    if(i == num){
      return true;
    }
  }
  return false;
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

void conteo(vector<int> v){
  cout << "El numero de elementos del vector es: " << v.size() << endl;
}