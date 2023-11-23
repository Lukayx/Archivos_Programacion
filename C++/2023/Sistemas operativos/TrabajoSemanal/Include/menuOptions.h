#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <cctype>
#include "user.h"
#include <locale>
#include <map>  
#include <codecvt>

using dbMAP = std::unordered_map<std::string, std::string>;
using menuMAP = std::map<int, std::pair<std::string, std::function<void(Usuario&)>>>;

void salir();
void sumatoria(Usuario& usuario);
void promedio(Usuario& usuario);
void moda(Usuario& usuario);
void contar(Usuario& usuario);
void crearArchivo(Usuario& usuario);
void agregarTexto(Usuario& usuario);
void conteoPalabras(Usuario& usuario);
void prepararIndiceInvertido(dbMAP database);
void crearIndiceInvertido(dbMAP database);
void llamarBuscador(dbMAP database);
void directorioArbol();
void directorioListaCircular ();
void procesamientoGrafico();
void opcionIndefinida();