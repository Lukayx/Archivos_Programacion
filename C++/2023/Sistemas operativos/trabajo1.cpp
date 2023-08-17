#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>
using namespace std;

void getout(string u, vector<int> v);
void signIn(string username);
bool validation(string username);
  
struct usuario{
  string u;
  vector<int> options;
  vector<int> v;
}

int main(int argc, char **argv){
  string nombre;
  vector<int> valores;
  string valor;
  int c;
  while((c=getopt(argc,argv, "u:v:"))!=-1) {
    switch (c) {
      case 'u': {
        nombre = optarg;
        cout << nombre << endl;
        break;
      }
      case 'v': {
        stringstream ss(optarg);
        while(getline(ss, valor, ';')){
          int i = stoi(valor);
          valores.push_back(i);
        }
        break;
      }
    }
  }
  getout(nombre, valores);
  // cout << "Ingrese nombre de usuario: ";
  // getline(cin, nombre);
  return 0;
}

void getout(string u, vector<int> v){
  if(validation(u)){
    cout << endl << "-------Usuario Valido-------" << endl;
    usuario.u = u;
    } else {
    string respuesta;
    cout << endl << "-------Usuario Invalido-------" << endl;
    cout << "Usted no se encuentra en la base de datos" << endl;
    do{
      cout << " Desea Registarse? (Si/No): ";
      cin >> respuesta;
    } while(respuesta != "Si" && respuesta != "No");    
    if(respuesta == "Si"){
      signIn(u);
      cout << "Se ha registrado exitosamente";
    }
    cout << "Que tenga un buen dia";
  }
}

bool validation(string username){
  ifstream archivo;
  string texto;


  archivo.open("db.txt",ios::in);

  if(!archivo.is_open()){
    cout << "No se pudo abrir el archivo";
    exit(1); 
  }
  while (getline(archivo, texto, ';')) { // Read lines from the file
    if(username == texto) {
      archivo.close();

      break;
    }
  }
  if()
  cout << texto << endl;
  archivo.close();
  return false;
}

void signIn(string username){
  ofstream archivo;

  archivo.open("db.txt",ios::app);

  if(!archivo.is_open()){
    cout << "No se pudo abrir el archivo";
    exit(1); 
  }

  archivo << ";" << username;

  archivo.close();
}