#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>

namespace fs = std::filesystem;
using MAPA = std::map<std::string, std::vector<std::string>>;

bool verificaRuta(std::string path);
MAPA creaMapa(std::string path);