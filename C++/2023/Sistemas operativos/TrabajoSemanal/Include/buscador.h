#include <iostream>
#include <string> 
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <unistd.h>
#include <thread>

using archivos = std::unordered_map<std::string, int>;
using wordCount_files = std::unordered_map<std::string, archivos>;
using vector = std::vector<std::pair<std::string, int>>;
namespace fs = std::filesystem;

void interfaz(wordCount_files mapa, std::string TOPK);
wordCount_files agregaPalabrasMapa(std::string filePath);
vector creaVector(wordCount_files mapa, std::string frase);
void buscadorPalabras(archivos& vectorTOP, std::string palabra, wordCount_files mapa);