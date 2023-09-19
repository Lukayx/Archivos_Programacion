#include <unordered_map>
#include <filesystem>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>

using mapEnv = std::unordered_map<std::string, std::string>; 
using cola = std::queue<std::string>;
namespace fs = std::filesystem;

cola fileRead(mapEnv env);
void countWords(std::string input, std::string output);
void procesarArchivos(cola& archivos, std::mutex& mtx, std::string output);
bool isSpecialCharacter(unsigned char c);
mapEnv envRead();

int main(){
  mapEnv env = envRead();
  cola colaArchivos = fileRead(env);
  std::mutex queueMutex;
  std::vector<std::thread> hilos;
  for(int i = 0; i<stoi(env["AMOUNT_THREADS"]); i++){
    hilos.emplace_back(procesarArchivos, std::ref(colaArchivos), std::ref(queueMutex), env["PATH_FILES_OUT"]);
  }

  for(std::thread& hilo : hilos){
    hilo.join();
  }

  return 0; 
}

void countWords(std::string input, std::string output) {
  std::string namefile = input.substr(input.find_last_of("/") + 1,input.length());
  std::ifstream file(input);
  std::string linea;
  std::unordered_map<std::string, int> resultado;
  while (getline(file, linea)) {
    linea.erase(std::remove_if(linea.begin(), linea.end(), isSpecialCharacter), linea.end());
    std::string key;
    std::stringstream ss(linea);
    while(getline(ss, key, ' ')){
      if(key.length() == 0 ) continue;
      std::string key_minuscula = "";
      char c; 
      for(int i=0; i<key.length(); i++){
        c = static_cast<char>(tolower(key[i]));
        key_minuscula += c;
      }
      resultado[key_minuscula] += 1;
    }
  }
  file.close();

  std::ofstream outFile(output + "/" + namefile, std::ios::trunc);  

  for(auto& indice: resultado){
    outFile << indice.first << ": " << indice.second << std::endl;
  }
  outFile.close();
  std::cout << "Se contaron las palabras con exito y se creo un archivo con sus frecuencias." << std::endl;
}

mapEnv envRead(){
  std::ifstream env(".env");
  mapEnv map;
  std::string line;
  std::string key;
  if(!env.is_open()){
    std::cout << "No se pudo abrir el archivo .env" << std::endl;
    exit(1);
  }
  while(getline(env, line)){
    int pos = line.find("=");
    key = line.substr(0, pos); //Recorta el nombre de la variable
    map[key] = line.substr(pos+1, line.length()); //Almacena el contenido de la variable del .env al map
    //std::cout << "( Key = " << key << ", Value = " << map[key] << " )" << std::endl; // Para ver contenido del map
  }
  if(map["PATH_FILES_OUT"]==map["PATH_FILES_IN"]){
    std::cout << "Las rutas de PATH_FILES_OUT y PATH_FILES_IN no pueden ser iguales iguales." << std::endl;
    exit(1);
  }
  return map;
}

bool isSpecialCharacter(unsigned char c) {
    if (c == ' ') return false;
    if (c == 225 || c == 233 || c == 237 || c == 243 || c == 250 || c == 193 || c == 201 || c == 205 || c == 211 || c == 218) {
      return false;
    }
    if(isdigit(c)) return true;
    return !isalnum(c);
}

cola fileRead(mapEnv env){
  std::string extension = env["EXTENSION"];
  std::string folderIn = env["PATH_FILES_IN"];
  fs::path folderPath = folderIn;
  int n = extension.length();
  cola queue;
  if(!fs::exists(folderPath) || !fs::is_directory(folderPath)){
    std::cout << "La carpeta no existe o no es un directorio Valido." << std::endl;
    exit(1);
  }
  for(const auto& iterador : fs::directory_iterator(folderPath)){
    if(iterador.is_regular_file()){
      std::string filename = iterador.path().filename().string();
      int f_n = filename.length(); 
      if(f_n > n && filename.find(extension) == (f_n - n)){
        queue.push(folderIn + "/" + filename);
        // std::cout << folderIn + "/" + filename << std::endl;
      }
    }
  }
  return queue;
}

void procesarArchivos(cola& archivos, std::mutex& mtx, std::string output){
  while (true){
    std::string archivo;
    std::lock_guard<std::mutex> lock(mtx);
    if(!archivos.empty()){
      archivo = archivos.front();
      archivos.pop();
    }
    if(archivo.empty()){
      break;
    }
    countWords(archivo, output);
  }
  
}