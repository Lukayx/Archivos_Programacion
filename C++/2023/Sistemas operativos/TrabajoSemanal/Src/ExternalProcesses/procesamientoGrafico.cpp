#include "../../Include/procesamientoGrafico.h"

int pid = getpid();

int main(int argc, char **argv){
  if (argc < 2) {
    std::cout << "Por favor, proporcione la ruta del archivo como argumento." << std::endl;
    return 0;
  }
  std::string path = argv[1];
  if(!verificaRuta(path)) return 0;
  std::string nombre;
  Puntos puntos = creaVectorPuntos(path, nombre);
  creaGrafico(puntos, nombre);
  return 0;
}

bool verificaRuta(std::string path){
  if (path.find_last_of('/') != std::string::npos) {
    size_t last = path.find_last_of('/');
    std::string directoryPath = path.substr(0, last);
    std::string nameFile = path.substr(last+1, path.length() - (last+1));
    if (!(fs::exists(directoryPath) && fs::is_directory(directoryPath))) {
      std::cout << "La ruta entregada no es válida." << std::endl;
      std::cout << "Se cerrará el proceso externo." << std::endl;
      return false;
    } else {
      if (nameFile.length() < 4 || nameFile.substr(nameFile.length() - 4) != ".gra") {
        std::cout << "La extensión del archivo es invalida, por favor, use un archivo '.gra'" << std::endl;
        exit(1);
      }
      std::ifstream archivo(path);
      if(!archivo.is_open()){
        std::cout << "El archivo no fue encontrado en la ruta entregada." << std::endl;
        std::cout << "Se cerrará el proceso externo." << std::endl;
        return false;
      }
      archivo.close();
    }
  } else {
    return false;
  }
  return true;
}

Puntos creaVectorPuntos(std::string path, std::string &nombreGrafico){
  std::ifstream archivo(path.c_str());
  std::string linea;
  Puntos puntos;
  while(getline(archivo, linea)){
    size_t pos = linea.find("titulo:\"");
    size_t n = linea.length(); 
    if(pos != std::string::npos){
      size_t last = linea.find_last_of("\"");
      if(last == (pos+7)){
        std::cout << "Verifica que las comillas en el nombre del grafico estén bien" << std::endl;
        exit(1);
      }
      pos += 8;
      nombreGrafico = linea.substr(pos, last - pos);
      // std::cout << nombreGrafico <<std::endl;
    } else {
      size_t first = linea.find("X:");
      size_t coma = linea.find(",");
      size_t second = linea.find("Y:");
      if(first == std::string::npos || second == std::string::npos || coma == std::string::npos) {
        std::cout << "Verifica que el formato del archivo es el correcto." << std::endl;
        exit(1);
      }
      first += 2;
      second += 2;
      int val1 = std::stoi(linea.substr(first, coma - first));
      int val2 = std::stoi(linea.substr(second, n - second));
      if(!(val1 > 100 || val2 > 100)){
        std::pair<int, int> par = std::make_pair(val1, val2);
        puntos.push_back(par);
      } else {
        std::cout << "Los valores de X e Y no pueden superar el 100." << std::endl;
        exit(1);
      }
    }
  }
  return puntos;
}

void creaGrafico(Puntos puntos, std::string nombreGrafico){
  sf::RenderWindow window(sf::VideoMode(550, 550), nombreGrafico);
  //VARIABLES EJE X
    int inicialX, finalX, multiplicadorX,posicionX_respectoY;
    inicialX = 50;
    finalX = 450;
    multiplicadorX = (finalX-inicialX)/100;
    posicionX_respectoY = 500;
  //DEFINE VECTORES EJE X
  sf::VertexArray xAxis(sf::Lines, 2);
  xAxis[0].position = sf::Vector2f(inicialX, posicionX_respectoY);
  xAxis[1].position = sf::Vector2f(finalX, posicionX_respectoY);
  xAxis[0].color = sf::Color::Black;
  xAxis[1].color = sf::Color::Black;
  //VARIABLES EJE Y
    int inicialY, finalY, multiplicadorY, posicionY_respectoX;
    inicialY = 500;
    finalY = 100;
    multiplicadorY = (inicialY-finalY)/100;
    posicionY_respectoX = 50;
  //DEFINE VECTORES EJE Y
  sf::VertexArray yAxis(sf::Lines, 2);
  yAxis[0].position = sf::Vector2f(posicionY_respectoX, inicialY);
  yAxis[1].position = sf::Vector2f(posicionY_respectoX, finalY);
  yAxis[0].color = sf::Color::Black;
  yAxis[1].color = sf::Color::Black;
  // CARGA LA FUENTE
  sf::Font font;
  if (!font.loadFromFile("Fonts/arial.ttf")) {
      // Manejar el error si no se puede cargar la fuente
      std::cout << "No se pudo cargar la fuente, verifique su ubicación." << std::endl;
      return;
  }
  // Agregar texto al eje X
  std::string labelX = "X=100"; 
  sf::Text textoX(labelX, font, 20);
  textoX.setPosition(finalX + 10, posicionX_respectoY - 10);
  textoX.setFillColor(sf::Color::Black);

  // Agregar texto al eje Y
  std::string labelY = "Y=100"; 
  sf::Text textoY(labelY, font, 20);
  textoY.setPosition(posicionY_respectoX - 30, finalY - 30);
  textoY.setFillColor(sf::Color::Black);

  // Dibujar los puntos
  int grosorPunto = 3;
  sf::CircleShape punto(grosorPunto); // Círculo para representar los puntos
  punto.setFillColor(sf::Color::Red);
  //ABRE LA VENTANA
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    // SE DIBUJA TODO
    window.clear(sf::Color::White);
    window.draw(xAxis);
    window.draw(yAxis);
    conectaPuntos(window, puntos, inicialX, inicialY, multiplicadorX, multiplicadorY);
    dibujaPuntos(window, punto, puntos, inicialX, inicialY, multiplicadorX, multiplicadorY, grosorPunto);
    window.draw(textoX);
    window.draw(textoY);
    window.display();
  }
}

void dibujaPuntos(sf::RenderWindow& window, sf::CircleShape& punto, Puntos puntos, int inicialX, int inicialY, int multiplicadorX, int multiplicadorY, int grosorPunto){
  int largoVector = puntos.size();
  for (int i = 0; i < largoVector; i++) {
    int posicionX = (inicialX-grosorPunto) + (puntos[i].first * multiplicadorX);
    int posicionY = (inicialY-grosorPunto) - (puntos[i].second * multiplicadorY);
    punto.setPosition(posicionX , posicionY);
    window.draw(punto);
  }
}

void conectaPuntos(sf::RenderWindow& window, Puntos puntos, int inicialX, int inicialY, int multiplicadorX, int multiplicadorY){
  int largoVector = puntos.size();
  if(largoVector > 1){
    for(int i = 0; i < largoVector-1; i++){
      int posicionX1 = (inicialX) + (puntos[i].first * multiplicadorX);
      int posicionY1 = (inicialY) - (puntos[i].second * multiplicadorY);
      int posicionX2 = (inicialX) + (puntos[i+1].first * multiplicadorX);
      int posicionY2 = (inicialY) - (puntos[i+1].second * multiplicadorY);
      sf::VertexArray linea(sf::Lines, 2);
      linea[0].position = sf::Vector2f(posicionX1,posicionY1);
      linea[1].position = sf::Vector2f(posicionX2,posicionY2);
      linea[0].color = sf::Color::Black;   
      linea[1].color = sf::Color::Black;   
      window.draw(linea);
    }
  }
}