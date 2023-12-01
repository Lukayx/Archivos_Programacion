#ifndef DIRECTORIOLISTACIRCULAR_H
#define DIRECTORIOLISTACIRCULAR_H

#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <unistd.h>
#include <sys/stat.h>
#include <functional>

struct Nodo{
  std::string directory_name;
  std::string root_path;
  std::vector<std::string> files;
  Nodo *Next;
};

namespace fs = std::filesystem;
using MAPA = std::map<std::string, std::vector<std::string>>;

bool verificaRuta(std::string path);
Nodo* creaListaCircular(std::string path);
MAPA creaMapa(std::string path, std::string &dirbase);
bool Recorre_Y_Crea(Nodo *listaCircular);
void eliminarRetornoDeCarro(std::string& cadena);

#endif // DIRECTORIOLISTACIRCULAR_H