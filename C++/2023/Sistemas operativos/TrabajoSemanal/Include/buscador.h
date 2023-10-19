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

wordCount_files agregaPalabrasMapa(std::string filePath);