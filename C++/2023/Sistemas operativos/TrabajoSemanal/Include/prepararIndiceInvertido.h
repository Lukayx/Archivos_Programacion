#include <unordered_map>
#include <filesystem>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <unistd.h>

using mapEnv = std::unordered_map<std::string, std::string>;
using vector = std::vector<std::string>;
namespace fs = std::filesystem;

vector fileRead(mapEnv env);
void countWords(std::string input, std::string output);
void procesarArchivos(vector& archivos, std::mutex& mtx, std::string output, int startIndex, int step);