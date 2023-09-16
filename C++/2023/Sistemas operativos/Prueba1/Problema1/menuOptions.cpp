#include "include.h"

namespace options{
  void exit(User& user){
    std::cout << "#####################################################" << std::endl;
    std::cout << "Que tenga un buen dia estimado/a " << user.userName << std::endl;
    std::cout << "#####################################################" << std::endl;
    std::exit(1);
  }
}

void userCreation(User& user, std::string database);
void MSG_to_the_User(User& user);
void sortVector(User& user);
std::string printVector(std::vector<int> vector);

void userCreation(User& user, std::string database){
  std::string name;
  std::string password1;
  std::string password2;
  bool passValidation = false;
  std::cout << "Ingrese el nombre de Usuario que va a crear: ";
  std::getline(std::cin >> std::ws, name);
  do{
    std::cout << "Ingrese la clave del Usuario: ";
    std::cin >> password1;
    std::cout << "Ingrese la clave del Usuario nuevamente: ";
    std::cin >> password2;
    if(password1 != password2) 
      std::cout << "Las claves no coinciden, intentelo nuevamente." << std::endl;  
    else
      passValidation = true;
    
  }while(!passValidation);
  std::ofstream archivo(database, std::ios::app);
  if (!archivo.is_open()) {
    std::cout << "No se pudo abrir la base de datos de Usuarios";
    exit(1);
  }
  std::string linea = name + ";" + password1;
  archivo << std::endl << linea;  
  archivo.close();
}

void MSG_to_the_User(User& user){
  std::cout << "#####################################################" << std::endl;
  int pid = fork();
  if(pid == 0) {
    std::cout << "HOLA COMO ESTAS " << user.userName << " PID HIJO = " << getpid() << std::endl;
    exit(0);
  }
  else {
    wait(NULL);
  }
}

void sortVector(User& user){
  std::cout << "#####################################################" << std::endl;
  int pid = fork();
  if(pid == 0) {
    printf("PID HIJO = %d\n", getpid());
    std::vector<int> oldVector= user.vector;
    sort(user.vector.begin(), user.vector.end());
    std::cout << "El vector ha sido ordenado exitosamente!" << std::endl;
    std::cout << "El vector anterior era este: " << printVector(oldVector) << std::endl;
    std::cout << "El vector ordenado es este: " << printVector(user.vector) << std::endl;
    exit(0);
  }
  else {
    wait(NULL);
  }
}

std::string printVector(std::vector<int> vector){
  std::string linea;
  for(int i = 0; i < vector.size(); i++){
    i==0 ? linea += "<" + std::to_string(vector[i]) : linea += "," + std::to_string(vector[i]);
  }
  linea += ">";
  return linea;
}