#include "../../Include/menuOptions.h"
#include "utilidades.cpp"

void salir(){
  std::cout << "Que tenga un buen dia" << std::endl;
  std::cout << "===============================================================================" << std::endl;
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

void conteoPalabras(Usuario& usuario) {
  std::ifstream input(usuario.input, std::ios::in | std::ios::binary);
  std::string linea;
  std::unordered_map<std::string, int> resultado;
  while (getline(input, linea)) {
    std::string cleanedLine = "";
    const char* lineaEspecial = linea.c_str();
    for(const char* c = lineaEspecial; *c; c++) {
      cleanedLine += isSpecialCharacter(c);
    }    
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
    output << indice.first << ":" << indice.second << std::endl;
  }
  output.close();
  std::cout << "Se contaron las palabras con éxito y se creó un archivo con sus frecuencias." << std::endl;
}

void prepararIndiceInvertido(dbMAP database){
  std::string str = database["PATH_PREPARE_INVERTED_INDEX"];
  str += " " + database["EXTENTION"];
  str += " " + database["PATH_FILES_IN"];
  str += " " + database["PATH_FILES_OUT"];
  str += " " + database["AMOUNT_THREADS"];
  const char* comando = str.c_str();
  // Llama a std::system para ejecutar el comando
  std::system(comando);
}

void crearIndiceInvertido(dbMAP database){
  std::string str = database["PATH_CREATE_INVERTED_INDEX"];
  str += " " + database["INVERTED_INDEX_FILE"];
  str += " " + database["PATH_FILES_OUT"];
  const char* comando = str.c_str();
  // Llama a std::system para ejecutar el comando
  std::system(comando);
}

void llamarBuscador(dbMAP database){
  std::string str = database["PATH_BUSCADOR"];
  str += " " + database["INVERTED_INDEX_FILE"];
  str += " " + database["TOPK"];
  const char* comando = str.c_str();
  std::system(comando);
}

void opcionIndefinida(){
  std::cout << "La opción que elegiste aún no ha sido implementada." << std::endl;
}

void directorioArbol(){
  
}

void directorioListaCircular (){

}

void procesamientoGrafico(){

}