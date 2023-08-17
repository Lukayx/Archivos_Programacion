#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getout(string u, int v);
void signIn(string username);
bool validation(string username);
  
int main(){
  string nombre;
  cout << "Ingrese nombre de usuario: ";
  getline(cin, nombre);
  if(validation(nombre)){
    cout << endl << "-------Usuario Valido-------" << endl;
    
    // getout(nombre,);
  } else {
    string respuesta;
    cout << endl << "-------Usuario Invalido-------" << endl;
    cout << "Usted no se encuentra en la base de datos" << endl;
    do{
      cout << " Desea Registarse? (Si/No): ";
      cin >> respuesta;
    } while(respuesta != "Si" && respuesta != "No");    
    if(respuesta == "Si"){
      signIn(nombre);
      cout << "Se ha registrado exitosamente";
    } else {
      cout << "Que tenga un buen dia";
    }
    return 0;
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
      return true;
    }
  }
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

// int getout(string u, int v){
  
// }