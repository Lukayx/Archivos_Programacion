#include "dataBaseManagement.cpp"
#include <cstdlib>
#include <limits> 
#include <filesystem>
using namespace std;

void getout(Usuario& usuario);

int main(int argc, char **argv) {
  string u, valor, path, texto, input, output;
  vector<int> v;
  int c;
  while ((c = getopt(argc, argv, "u:v:f:t:i:o:")) != -1) {
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
        // if(path.find_last_of('/') != string::npos){
        //   string directoryPath = path.substr(0,path.find_last_of('/'));
        //   if (!(filesystem::exists(directoryPath) && filesystem::is_directory(directoryPath))) {
        //       cout << "La ruta dada en el parametro '-f' no es válida, intente ingresarla nuevamente." << endl;
        //       exit(1);
        //   }
        // }
        break;
      }
      case 't': {
        texto = optarg;
        break;
      }
      case 'i': {
        input = optarg;
        ifstream archivo(input, ios::ate);
        if (!archivo.is_open()) {
          cout << "La ruta dada en el parametro '-i' no se pudo encontrar, revise bien la ruta ingresada." << endl;
          cout << "Se cerrara el programa.";
          exit(1);
        }
        streampos fileSize = archivo.tellg(); // Obtener tamaño del archivo
        archivo.close();
        if(fileSize == -1) {
          cerr << "No se pudo obtener el tamaño del archivo." << endl;
          exit(1);
        }
      break;
      }
      case 'o': {
        output = optarg;
        break;
      }
    }
  }
  Usuario usuario;
  usuario.u = u;
  usuario.v = v;
  usuario.path = path;
  usuario.text = texto;
  usuario.input = input;
  usuario.output = output;
  system("cls");
  getout(usuario);
  return 0;
}

void getout(Usuario& usuario) {
  unordered_map<string, string> dataBase = leerEnv();
  map<int, pair<string, function<void(Usuario& usuario)>>> menuOptions = crearMapa(usuario, dataBase["MENU"]);
  if(validation(usuario, dataBase)) {
    bool condition = true;
    bool entradaValida = true;
    string respuesta;
    while(condition){
      cout << "Usuario Actual: " << usuario.u << " / " << usuario.userProfile << endl;
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
    signIn(usuario.u, menuOptions, dataBase["USER"]);
  }
  cout << "\nQue tenga un buen dia" << endl;
}