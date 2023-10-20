#include "../../Include/buscador.h"

int pid = getpid();

int main(int argc, char **argv){
  std::string INVERTED_INDEX_FILE = argv[1];
  std::string TOPK = argv[2];
  wordCount_files mapa = agregaPalabrasMapa(INVERTED_INDEX_FILE);
  interfaz(mapa, TOPK);
  std::string perro;
  std::cin >> perro;
  std::system("clear");
  return 0;
}

void interfaz(wordCount_files mapa, std::string TOPK){
  std::system("clear");
  std::string respuesta;
  std::cout << "BUSCADOR BASADO EN INDICE INVERTIDO (" << pid << ")" << std::endl;
  std::cout << "Los top K documentos serán " << TOPK << std::endl;
  std::cout << "Escriba texto a buscar: ";
  std::getline(std::cin >> std::ws, respuesta); //Pregunta y evita el buffer de cin 
  // std::unordered_map<std::string, int>
  std::cout << "Respuesta ( tiempo = perro ):" << std::endl;
  vector vectorTOP = creaVector(mapa, respuesta);
  for(int i = 0; i < std::stoi(TOPK); i++){
    std::cout << i+1 << ") " << vectorTOP[i].first << ", " << vectorTOP[i].second << std::endl;
  }
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
      while(getline(ss, valores, ';')){
        name = valores.substr(valores.find_first_of('(')+1,valores.find(':'));
        count = std::stoi(valores.substr(valores.find_first_of(':')+1,valores.find_last_of(')')));
        map[word][name] = count;
      }
    }
  }
  file.close();
  return map;
}

vector creaVector(wordCount_files mapa, std::string frase){
  std::vector<std::string> palabras;
  std::istringstream stream(frase);
  std::vector<std::thread> hilos;
  archivos coincidenciasArchivos;
  std::string palabra;
  vector vectorTOP;
  while(stream >> palabra) {
      palabras.push_back(palabra);
  }
  for (size_t i = 0; i < palabras.size(); i++) {
    hilos.emplace_back(buscadorPalabras, std::ref(coincidenciasArchivos), palabras[i], mapa);
  }

  for(std::thread& hilo : hilos){
    hilo.join();
  }

  for(auto& value : coincidenciasArchivos){
    std::pair<std::string, int> par = std::make_pair(value.first, value.second);
    vectorTOP.push_back(par);
  }

  std::sort(vectorTOP.begin(), vectorTOP.end(), [](const auto& a, const auto& b) {
    return a.second > b.second;
  });

  return vectorTOP; 
}

void buscadorPalabras(archivos& mapaConteo, std::string palabra, wordCount_files mapa){
  if(mapaConteo.empty()){
    mapaConteo = mapa[palabra];
  } else {
    for(auto& value : mapa[palabra]){
      mapaConteo[value.first] += value.second;
    }
  }
}