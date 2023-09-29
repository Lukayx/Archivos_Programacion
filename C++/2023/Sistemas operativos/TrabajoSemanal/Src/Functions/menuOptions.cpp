#include "../../Include/user.h"
#include "../../Include/menuOptions.h"

void salir();
void sumatoria(Usuario& usuario);
void promedio(Usuario& usuario);
void moda(Usuario& usuario);
void contar(Usuario& usuario);
void crearArchivo(Usuario& usuario);
void agregarTexto(Usuario& usuario);
void conteoPalabras(Usuario& usuario);
void opcionIndefinida();
bool isSpecialCharacter(unsigned char c);
char removeAccent(unsigned char c);

void salir(){
  std::cout << "Que tenga un buen dia" << std::endl;
  std::cout << "===================================================" << std::endl;
  exit(1);
}

void sumatoria(Usuario& usuario){
  int num = 0;
  for(int i : usuario.v){
    num += i;
  }
  std::cout << "La sumatoria del vector es: " << num << std::endl;
}

void promedio(Usuario& usuario){
  int num = 0;
  for(int i : usuario.v){
    num += i;
  }
  std::cout << "El promedio del vector es: " << static_cast<float>(num) / usuario.v.size() << std::endl;
}

void moda(Usuario& usuario){
  std::map<int, int> frecuencias;
  for(int num : usuario.v) {
      frecuencias[num]++;
  }

  int moda = 0;  // Valor de la moda
  int maxFrecuencia = 0;  // Frecuencia máxima

  // Encontrar la moda
  for(const auto& numero : frecuencias) {
    if(numero.second > maxFrecuencia) {
        moda = numero.first;
        maxFrecuencia = numero.second;
    }
  }
  std::cout << "La moda del vector es: " << moda << std::endl;
}

void contar(Usuario& usuario){
  std::cout << "El número de elementos del vector es: " << usuario.v.size() << std::endl;
}

void crearArchivo(Usuario& usuario){
  std::ifstream existenciaArchivo(usuario.path);
  if(existenciaArchivo){
    std::cout << "El archivo ya existe en la ruta especificada." << std::endl;
    existenciaArchivo.close();
    return;
  }
  std::ofstream archivo(usuario.path, std::ios::out);
  if (!archivo.is_open()) {
    std::cout << "No se pudo crear el archivo";
    exit(1);
  }

  archivo.close();
  std::cout << "Archivo creado exitosamente." << std::endl;
}

void agregarTexto(Usuario& usuario){
  std::ifstream existenciaArchivo(usuario.path);
  if(!existenciaArchivo){
    std::cout << "El archivo al que intentas acceder en la ruta especificada no existe." << std::endl;
    existenciaArchivo.close();
    return;
  }

  std::ofstream archivo(usuario.path, std::ios::app);
  if (!archivo.is_open()) {
    std::cout << "No se pudo abrir el archivo";
    exit(1);
  }
  archivo << usuario.text << std::endl;
  archivo.close();
  std::cout << "Texto agregado al archivo exitosamente." << std::endl;
}

bool isSpecialCharacter(unsigned char c) {
    if (c == ' ') return false;
    if (c == 225 || c == 233 || c == 237 || c == 243 || c == 250 || c == 193 || c == 201 || c == 205 || c == 211 || c == 218) {
        return false;
    }
    if (isdigit(c)) return true;
    return !isalnum(c);
}

char removeAccent(unsigned char c) {
  switch (c) {
    case 225: return 'a';
    case 233: return 'e';
    case 237: return 'i';
    case 243: return 'o';
    case 250: return 'u';
    case 193: return 'A';
    case 201: return 'E';
    case 205: return 'I';
    case 211: return 'O';
    case 218: return 'U';
    default: return c;
  }
}

void conteoPalabras(Usuario& usuario) {
  std::ifstream input(usuario.input);
  std::string linea;
  std::unordered_map<std::string, int> resultado;
  while (getline(input, linea)) {
    std::string cleanedLine;
    for (unsigned char c : linea) {
      if (!isSpecialCharacter(c)) {
        cleanedLine.push_back(removeAccent(c));
      }
    }

    std::transform(cleanedLine.begin(), cleanedLine.end(), cleanedLine.begin(), ::tolower);

    std::istringstream ss(cleanedLine);
    std::string key;
    while (ss >> key) {
      if (key.length() == 0) continue;
      resultado[key]++;
    }
  }
  input.close();
  std::ofstream output(usuario.output, std::ios::trunc);  

  for(const auto& indice: resultado){
    output << indice.first << ": " << indice.second << std::endl;
  }
  output.close();
  std::cout << "Se contaron las palabras con éxito y se creó un archivo con sus frecuencias." << std::endl;
}

void opcionIndefinida(){
  std::cout << "La opción que elegiste aún no ha sido implementada." << std::endl;
}
