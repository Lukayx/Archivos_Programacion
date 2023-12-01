#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/value.h>
#include <sys/stat.h>
#include <sys/types.h>

namespace fs = std::filesystem;

bool verificaRuta(std::string path);