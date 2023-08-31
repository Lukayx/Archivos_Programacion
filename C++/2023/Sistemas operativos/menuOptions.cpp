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
  string path;
  string text;
  string userProfile;
  string input;
  string output;
  vector<int> options;
  vector<int> v;
};

void salir();
void sumatoria(Usuario& usuario);
void promedio(Usuario& usuario);
void moda(Usuario& usuario);
void contar(Usuario& usuario);
void crearArchivo(Usuario& usuario);
void agregarTexto(Usuario& usuario);
void conteoPalabras(Usuario& usuario);
void opcionIndefinida();

void salir(){
  cout << "Que tenga un buen dia" << endl;
  exit(1);
}

void sumatoria(Usuario& usuario){
  int num = 0;
  for(int i : usuario.v){
    num += i;
  }
  cout << "La sumatoria del vector es: " << num << endl;
}

void promedio(Usuario& usuario){
  int num = 0;
  for(int i : usuario.v){
    num += i;
  }
  cout << "El promedio del vector es: " << float(num/usuario.v.size()) << endl;
}

void moda(Usuario& usuario){
  map<int, int> frecuencias;
  for(int num : usuario.v) {
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

void contar(Usuario& usuario){
  cout << "El numero de elementos del vector es: " << usuario.v.size() << endl;
}

void crearArchivo(Usuario& usuario){
  ifstream existenciaArchivo(usuario.path);
  if(existenciaArchivo){
    cout << "El archivo ya existe en la ruta especificada." << endl;
    existenciaArchivo.close();
    return;
  }
  ofstream archivo(usuario.path,ios::out);
  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo";
    exit(1);
  }

  archivo.close();
  cout << "Archivo creado exitosamente." << endl;
}

void agregarTexto(Usuario& usuario){
  ifstream existenciaArchivo(usuario.path);
  if(!existenciaArchivo){
    cout << "El archivo al que intentas acceder en la ruta especificada no existe." << endl;
    existenciaArchivo.close();
    return;
  }

  ofstream archivo(usuario.path,ios::app);
  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo";
    exit(1);
  }
  archivo << usuario.text << endl;
  archivo.close();
  cout << "Texto agregado al archivo exitosamente." << endl;
}

void conteoPalabras(Usuario& usuario){
  ifstream archivo(usuario.input);
  string linea;

  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo";
    exit(1);
  }

  
}

void opcionIndefinida(){
  cout << "La opcion que elejiste aun no ha sido implementada." << endl;
}