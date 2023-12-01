#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>

namespace fs = std::filesystem;
using Puntos = std::vector<std::pair<int,int>>;

bool verificaRuta(std::string path);
Puntos creaVectorPuntos(std::string path, std::string &nombreGrafico);
void creaGrafico(Puntos puntos, std::string nombreGrafico);
void conectaPuntos(sf::RenderWindow& window, Puntos puntos, int inicialX, int inicialY, int multiplicadorX, int multiplicadorY);
void dibujaPuntos(sf::RenderWindow& window, sf::CircleShape& punto, Puntos puntos, int inicialX, int inicialY, int multiplicadorX, int multiplicadorY, int grosorPunto);