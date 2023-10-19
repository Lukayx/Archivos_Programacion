#include "../../Include/buscador.h"

int pid = getpid();

int main(int argc, char **argv){
  std::string INVERTED_INDEX_FILE = argv[1];
  std::string TOPK = argv[2];
  wordCount_files mapa = agregaPalabrasMapa(INVERTED_INDEX_FILE);


}

void interfaz(wordCount_files mapa, std::string TOPK){
  std::cout << "BUSCADOR BASADO EN INDICE INVERTIDO (" << pid << ")" << std::endl;
  std::cout << "Los top K documentos serán " << TOPK << std::endl;
}

wordCount_files agregaPalabrasMapa(std::string filePath){
  std::ifstream file(filePath);
  std::string linea, valores, name;
  wordCount_files map;
  int count;
  while(getline(file, linea)){
    if(linea != ""){
      std::string word = linea.substr(0,linea.find(":"));
      std::string info = linea.substr(linea.find(":")+1, linea.length());
      std::stringstream ss(info);
      while(getline(ss, valores, ";")){
        name = valores.substr(valores.find_first_of('(')+1,valores.find(':'));
        count = stoi(valores.substr(valores.find(':')+1,valores.find_last_of(')')));
        map[word][name] = count;
      }
    }
  }
  file.close();
  return map;
}