#include <iostream>
#include <cstring>
#include <unordered_map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <unistd.h>

using dbMAP = std::unordered_map<std::string, std::string>;
using vector = std::vector<std::pair<std::string, string>>;
using dbCACHE = std::unordered_map<pair<vector, int>>;

dbMAP leerEnv();
void eliminarRetornoDeCarro(std::string& cadena);