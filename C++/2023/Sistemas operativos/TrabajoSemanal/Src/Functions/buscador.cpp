#include "../../Include/buscador.h"

int pid = getpid();

int main(int argc, char **argv){
  std::string INVERTED_INDEX_FILE = argv[1];
  std::string TOPK = argv[2];
  wordCount_files mapa = agregaPalabrasMapa(INVERTED_INDEX_FILE);
  std::string respuesta;
  while (true){  
    interfaz(mapa, TOPK);
    do{
      std::cout << "\nDesea salir? (Si/No): ";
      std::cin >> respuesta;
    }while(respuesta != "Si" && respuesta != "No");
    if(respuesta == "Si") break;
  }
  std::system("clear");
  return 0;
}

void interfaz(wordCount_files mapa, std::string TOPK){
  std::system("clear");
  std::string respuesta;
  std::cout << "BUSCADOR BASADO EN INDICE INVERTIDO (" << pid << ")" << std::endl;
  std::cout << "\nLos top K documentos serán " << TOPK << std::endl;
  std::cout << "\nEscriba texto a buscar: ";
  std::getline(std::cin >> std::ws, respuesta); //Pregunta y evita el buffer de cin 
  auto start = std::chrono::high_resolution_clock::now();
  vector vectorTOP = creaVector(mapa, respuesta);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_milliseconds = end - start;  
  std::cout << "\nRespuesta ( tiempo = " << duration_milliseconds.count() << " ):\n" << std::endl;
  if(vectorTOP.size() != 0){
    size_t indice = std::stoi(TOPK);
    if(vectorTOP.size() < indice) indice = vectorTOP.size();
    for(size_t i = 0; i < indice; i++){
      std::cout << i+1 << ") " << vectorTOP[i].first << ", " << vectorTOP[i].second << std::endl;
    }
  } else {
    std::cout << "No se encontraron coicidencias en ningún archivo" << std::endl;
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
        name = valores.substr(valores.find_first_of('(')+1,valores.find(':')-1);
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
    hilos.emplace_back(buscadorPalabras, std::ref(coincidenciasArchivos), palabras[i], mapa, i);
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

void buscadorPalabras(archivos& mapaConteo, std::string palabra, wordCount_files mapa, int i) {
  if (i == 0) {
    mapaConteo = mapa[palabra];
  } else {
    if (mapa.find(palabra) != mapa.end()) {
      for (auto it = mapaConteo.begin(); it != mapaConteo.end(); ) {
        if (mapa[palabra].find(it->first) == mapa[palabra].end()) {
          it = mapaConteo.erase(it);
        } else {
          mapaConteo[it->first] += mapa[palabra][it->first]; 
          ++it;
        }
      }
    } else {
      mapaConteo.clear();
    }
  }
}