#include "databaseFunctions.cpp"

void app(User& user);

int main(int argc, char **argv) {
  std::string userName;
  std::string password;
  std::vector<int> vector;
  User user;
  int c;
  while ((c = getopt(argc, argv, "u:p:v:")) != -1) {
    switch (c) {
      case 'u': {
        user.userName = optarg;
        std::cout << user.userName << std::endl;
        break;
      }
      case 'p': {
        user.password = optarg;
        std::cout << user.password << std::endl;
        break;
      }
      case 'v': {
        std::stringstream ss(optarg);
        std::string valor;
        while (getline(ss, valor, ';')) {
          int i = stoi(valor);
          vector.push_back(i);
        }
        user.vector = vector;
        break;
      }
    }
  }
  user.admin = (user.userName == "admin" && user.userName == user.password );
  system("clear");
  app(user);
  return 0;
}

void app(User& user) {
  printf("SISTEMA 1 (PID PADRE = %d)\n\n", getpid());
  databaseMap database = leerEnv();
  menuMap menu = menuOptions(user, database);
  if(user.admin || validation(user, database["USERS"])){
    bool condition = true;
    bool validOption = true;
    std::string answer;
    while(condition){
      std::cout << "\nOPCIONES DE MENU\n" << std::endl;
      for (const auto& option : menu){
        std::cout << option.first << ")- " << option.second.first << std::endl;
      }
      do{
        std::cout << "\nINGRESE UNA OPCION: ";
        std::cin >> answer;
        validOption = true;
        for(char a : answer){
          if(!isdigit(a)){
            validOption = false;
            std::cout << "\nOPCION INVALIDA, ELIJA DENUEVO: ";
            break;
          }
        }
      }while(!validOption);
      int option = stoi(answer);
      bool userCreation = (user.admin && option==1);
      if(!userCreation) {
        system("clear");
        printf("SISTEMA 1 (PID PADRE= %d)\n\n", getpid());
      }
      if(menu.find(option) != menu.end()){
        menu[option].second(user);
        if(userCreation){
          system("clear");
          printf("SISTEMA 1 (PID PADRE= %d)\n\n", getpid());
          std::cout << "#####################################################" << std::endl;
          std::cout << "------Ha creado el usuario exitosamente------" << std::endl;
        }
      } else {
        std::cout << "#####################################################" << std::endl;
        std::cout << "OPCION FUERA DEL RANGO" << std::endl;
      }
      std::cout << "#####################################################\n" << std::endl;
    }
  } else {
    std::cout << "Hasta luego" << std::endl;
    std::cout << "#####################################################" << std::endl;
  }
}