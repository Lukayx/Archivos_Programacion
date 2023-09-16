#include "user.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <algorithm>
#include <sys/types.h>
#include <sys/wait.h>
#include <unordered_map>
#include <functional>
#include <map>
#include <utility>

using databaseMap = std::unordered_map<std::string,std::string>;
using menuMap = std::map<int, std::pair<std::string,std::function<void(User&)>>>;
