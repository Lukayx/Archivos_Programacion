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
#include <thread>
#include <filesystem>
#include <chrono>
#include <unistd.h>

using archivos = std::unordered_map<std::string, int>;
using wordCount_files = std::unordered_map<std::string, archivos>;
using vector = std::vector<std::pair<std::string, int>>;
using dbMAP = std::unordered_map<std::string, std::string>;

wordCount_files agregaPalabrasMapa(std::string filePath);
vector creaVector(wordCount_files mapa, std::string frase);
void buscadorPalabras(archivos& mapaConteo, std::string palabra, wordCount_files mapa, int i);
dbMAP leerEnv();
void eliminarRetornoDeCarro(std::string& cadena);