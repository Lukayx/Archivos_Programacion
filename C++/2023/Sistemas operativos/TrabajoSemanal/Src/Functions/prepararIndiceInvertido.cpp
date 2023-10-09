#include "../../Include/prepararIndiceInvertido.h"
#include "utilidades.cpp"

int pid = getpid();

int main(int argc, char **argv){
  mapEnv env;
  env["EXTENTION"] = argv[1];
  env["PATH_FILES_IN"] = argv[2];
  env["PATH_FILES_OUT"] = argv[3];
  env["AMOUNT_THREADS"] = argv[4];
  vector vectorArchivos = fileRead(env); //Recoge los nombres de los archivos en un vector bajo los criterios de las variables de entorno
  if(vectorArchivos.size() < 20){
    std::cout << "Deben haber al menos 20 archivos " << env["EXTENTION"] << " para poder usar esta opcion." << std::endl;
    exit(1);
  }
  std::mutex mutex;
  std::vector<std::thread> hilos;
  int numThreads = std::stoi(env["AMOUNT_THREADS"]);
  for (int i = 0; i < numThreads; i++) {
    hilos.emplace_back(procesarArchivos, std::ref(vectorArchivos), std::ref(mutex), env["PATH_FILES_OUT"], i, numThreads);
  }
  for(std::thread& hilo : hilos){
    hilo.join();
  }
  return 0; 
}

void procesarArchivos(vector& archivos, std::mutex& mtx, std::string output, int startIndex, int step){
  for (size_t i = startIndex; i < archivos.size(); i += step) {
    std::string archivo;
    {
      std::lock_guard<std::mutex> lock(mtx);
      archivo = archivos[i];
    }
    if(!archivo.empty()) {
      countWords(archivo, output);
      std::string file = archivo.substr(archivo.find_last_of('/')+1,archivo.length());
      printf("Proceso pid=%d - Archivo procesado '%s' por el hilo (%u)\n",pid,file.c_str(),startIndex);
    }
  }
}

void countWords(std::string input, std::string output) {
  std::string namefile = input.substr(input.find_last_of("/") + 1,input.length());
  std::ifstream file(input);
  std::string linea;
  std::unordered_map<std::string, int> resultado;
  while(getline(file, linea)) {
    linea.erase(std::remove_if(linea.begin(), linea.end(), isSpecialCharacter), linea.end());
    std::string key;
    std::stringstream ss(linea);
    while(getline(ss, key, ' ')){
      if(key.length() == 0 ) continue;
      std::string key_minuscula = "";
      char c; 
      for(size_t i=0; i<key.length(); i++){
        c = static_cast<char>(tolower(key[i]));
        key_minuscula += c;
      }
      resultado[key_minuscula] += 1;
    }
  }
  file.close();

  std::ofstream outFile(output + "/" + namefile, std::ios::trunc);  

  for(auto& indice: resultado){
    outFile << indice.first << ";" << indice.second << std::endl;
  }
  outFile.close();
}

vector fileRead(mapEnv env){
  std::string extension = env["EXTENTION"];
  std::string folderIn = env["PATH_FILES_IN"];
  fs::path folderPath = folderIn;
  size_t n = extension.length(); // Cambiar int a size_t
  vector vectorfiles;
  if(!fs::exists(folderPath) || !fs::is_directory(folderPath)){
    std::cout << "La carpeta en " << folderIn << " no existe o no es un directorio válido." << std::endl;
    exit(1);
  }
  for(const auto& iterador : fs::directory_iterator(folderPath)){
    if(iterador.is_regular_file()){
      std::string filename = iterador.path().filename().string();
      size_t f_n = filename.length(); // Cambiar int a size_t
      size_t extensionPos = filename.find(extension);
      if(extensionPos != std::string::npos && extensionPos == (f_n - n)){
        vectorfiles.push_back(folderIn + "/" + filename);
      }
    }
  }
  return vectorfiles;
}