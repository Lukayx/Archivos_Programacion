#include <iostream>
#include <string> 
#include <vector>
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <unistd.h>
#include <thread>

using archivos = std::unordered_map<std::string, int>;
using wordCount_files = std::unordered_map<std::string, archivos;
using vector = std::vector<std::pair<std::string, int>>;
namespace fs = std::filesystem;

wordCount_files agregaPalabrasMapa(std::string filePath);
void interfaz(wordCount_files mapa, std::string TOPK);
vector creaVector(wordCount_files mapa, std::string TOPK, std::string frase);
void buscadorPalabras(vector vectorTOP, std::string palabra, wordCount_files mapa);