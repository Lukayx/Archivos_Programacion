#include <functional>
#include <windows.h>

using dbMAP = std::unordered_map<std::string, std::string>;
using menuMAP = std::map<int, std::pair<std::string, std::function<void(Usuario& usuario)>>>;