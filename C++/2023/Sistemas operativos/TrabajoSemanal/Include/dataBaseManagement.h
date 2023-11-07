#include <functional>
#include <string>
#include <map>
#include <filesystem>

namespace fs = std::filesystem;

bool validation(Usuario& usuario, dbMAP database);
std::vector<int> userProfileAssignment(std::string userProfile, std::string database);
dbMAP leerEnv();
void signIn(std::string username, menuMAP menuOptions, dbMAP database);
bool confirmPermiss(Usuario& usuario, int opcion);
menuMAP crearMapa(Usuario& usuario, dbMAP database);
void eliminarRetornoDeCarro(std::string& cadena);