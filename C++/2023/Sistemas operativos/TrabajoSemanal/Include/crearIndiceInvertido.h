#include <iostream>
#include <string> 
#include <vector>
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <unistd.h>

using wordCount_files = std::unordered_map<std::string, std::unordered_map<std::string, int>>;
using vector = std::vector<std::string>;
namespace fs = std::filesystem;

vector fileRead(std::string PATH_FILES_OUT);
void IndexFile(vector files, std::string INVERTED_INDEX_FILE);
void agregaPalabrasMapa(wordCount_files& map, std::string filePath);
void crearIndexFile(wordCount_files& map, std::string INVERTED_INDEX_FILE);