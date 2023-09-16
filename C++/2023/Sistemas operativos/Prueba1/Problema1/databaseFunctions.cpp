#include "menuOptions.cpp"

bool validation(User& user, std::string database);
menuMap menuOptions(User& user, databaseMap database);
databaseMap leerEnv();
void eliminarRetornoDeCarro(std::string& cadena);

bool validation(User& user, std::string database){
  std::ifstream archivo(database);
  std::string linea;
  if(!archivo.is_open()) {
    std::cout << "No se pudo abrir el la base de datos de Usuario" << std::endl;
    std::cout << "Verifique que la ruta este correcta";
    exit(1);
  }
  while (getline(archivo, linea)){
    eliminarRetornoDeCarro(linea); //ELIMINA ULTIMO CARACTER NO IMPRIMIBLE '\r'
    size_t pos = linea.find(user.userName + ";");
    if(pos==0){
      std::string password = linea.substr(user.userName.length() + 1); //Recorta la contraseña
      if(user.password == password){
        return true;
      } else {
        std::cout << "Password incorrecta, verifiquela e ingrese nuevamente." << std::endl;
        return false;
      }
    }
  }
  std::cout << "#####################################################" << std::endl;
  std::cout << "Usted no se encuentra en la base de datos" << std::endl;
  return false; //NO ENCONTRO EL USUARIO
}

menuMap menuOptions(User& user, databaseMap database){
  menuMap mapa;
  std::string userDatabase = database["USERS"];
  std::function<void(User&)> function;
  std::string label;
  int i = 0;
  function = [](User& user) { options::exit(user); };
  label = "SALIR";
  mapa[i] = make_pair(label, function);

  if(user.admin){
    function = [userDatabase](User& user) { userCreation(user, userDatabase); };
    label = "CREAR USUARIO";
    mapa[++i] = make_pair(label, function);
  }

  function = [](User& user) { MSG_to_the_User(user); };
  label = "IMPRIMIR MSG PARA EL USUARIO";
  mapa[++i] = make_pair(label, function);

  function = [](User& user) { sortVector(user); };
  label = "ORDENAR VECTOR";
  mapa[++i] = make_pair(label, function);
  return mapa;
}

databaseMap leerEnv(){
  databaseMap dataBase;
  std::ifstream archivo(".env");
  std::string key;
  std::string linea;
  size_t indice;
  if (!archivo.is_open()) {
    std::cout << "No se pudo abrir el archivo .env" << std::endl;
    std::cout << "Verifique de que se encuentre en la carpeta actual";
    exit(1);
  }
  while (getline(archivo, linea)){
    size_t pos = linea.find("DB_");
    if(pos == 0){
      indice = linea.find('=');
      key = linea.substr(3, indice-3);
      dataBase[key] = linea.substr(indice + 1, linea.length());
    } 
  }
  archivo.close();
  return dataBase;
}

void eliminarRetornoDeCarro(std::string& cadena) {
  cadena.erase(std::remove(cadena.begin(), cadena.end(), '\r'), cadena.end());
}