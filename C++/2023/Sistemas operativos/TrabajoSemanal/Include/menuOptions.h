#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <cctype>
#include "user.h"
#include <map>  

using dbMAP = std::unordered_map<std::string, std::string>;
using menuMAP = std::map<int, std::pair<std::string, std::function<void(Usuario&)>>>;