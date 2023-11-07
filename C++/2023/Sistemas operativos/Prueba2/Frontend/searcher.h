#include <iostream>
#include <cstring>
#include <unordered_map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string> 
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <unistd.h>

using dbMAP = std::unordered_map<std::string, std::string>;
using vector = std::vector<std::pair<std::string, std::string>>;

void interfaz(dbMAP env, int frontendSocket);
std::string formateoMensaje(dbMAP env, std::string text);
vector quitaFormatoMensaje(std::string mensaje, std::string& tiempo, std::string& origen);
dbMAP leerEnv();
void eliminarRetornoDeCarro(std::string& cadena);