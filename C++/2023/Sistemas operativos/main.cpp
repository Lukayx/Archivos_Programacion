#include "dataBaseManagement.cpp"
#include <cstdlib>
#include <limits> 
using namespace std;

void getout(string u, vector<int> v, string path, string texto);

int main(int argc, char **argv) {
  string u, valor, path, texto;
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
  system("cls");
  getout(u,v,path,texto);
  return 0;
}

void getout(string u, vector<int> v, string path, string texto) {
  Usuario usuario;
  usuario.u = u;
  usuario.v = v;
  usuario.path = path;
  usuario.text = texto;
  map<int, pair<string, function<void(Usuario& usuario)>>> menuOptions = crearMapa(usuario);
  if(validation(usuario)) {
    bool condition = true;
    bool entradaValida = true;
    string respuesta;
    while(condition){
      cout << "\nOPCIONES DE MENU\n" << endl;
      for (const auto& option : menuOptions){
        cout << option.first << ")- " << option.second.first << endl;
      }
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
            menuOptions[opcion].second(usuario);
        } else {
            cout << "Opcion invalida." << endl;
        }
      } else {
        cout << "No tiene permiso para acceder a esta operacion." << endl;
      }
      cout << "\nPresiona Enter para limpiar la pantalla  ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cin.get();
      system("cls");
    }
  } else {
    signIn(usuario.u, menuOptions);
  }
  cout << "\nQue tenga un buen dia" << endl;
}