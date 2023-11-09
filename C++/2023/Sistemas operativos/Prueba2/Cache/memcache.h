#include <iostream>
#include <cstring>
#include <unordered_map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <unistd.h>

using dbMAP = std::unordered_map<std::string, std::string>;
using vector = std::vector<std::pair<std::string, std::string>>;
using dbCACHE = std::unordered_map<std::string, std::pair<vector, int>>;

dbMAP leerEnv();
void eliminarRetornoDeCarro(std::string& cadena);
bool buscar_en_estructura(std::string palabra, dbCACHE estructura, std::string& mensaje);
std::string empaquetarMensaje(dbCACHE estructura, std::chrono::duration<double> tiempo, std::string palabra, dbMAP env);
void almacenar_en_estructura(std::string mensaje, dbCACHE& estructura, int MEMORYSIZE, std::string txtToSearch);
std::string formateoMensaje(dbMAP env, std::string text);