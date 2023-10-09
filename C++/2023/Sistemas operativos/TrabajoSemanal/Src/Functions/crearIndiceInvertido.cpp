#include "../../Include/crearIndiceInvertido.h"

int pid = getpid();

int main(int argc, char **argv){
  std::string INVERTED_INDEX_FILE = argv[1];
  std::string PATH_FILES_OUT = argv[2];
  vector files = fileRead(PATH_FILES_OUT);
  IndexFile(files, INVERTED_INDEX_FILE);

  return 0;
}

vector fileRead(std::string PATH_FILES_OUT){
  std::string extension = "txt";
  fs::path folderPath = PATH_FILES_OUT;
  size_t n = extension.length(); // Cambiar int a size_t
  vector vectorfiles;
  if(!fs::exists(folderPath) || !fs::is_directory(folderPath)){
    std::cout << "La carpeta en " << PATH_FILES_OUT << " no existe o no es un directorio válido." << std::endl;
    exit(1);
  }
  for(const auto& iterador : fs::directory_iterator(folderPath)){
    if(iterador.is_regular_file()){
      std::string filename = iterador.path().filename().string();
      size_t f_n = filename.length(); // Cambiar int a size_t
      size_t extensionPos = filename.find(extension);
      if(extensionPos != std::string::npos && extensionPos == (f_n - n)){
        vectorfiles.push_back(PATH_FILES_OUT + "/" + filename);
      }
    }
  }
  return vectorfiles;
}


void IndexFile(vector files, std::string INVERTED_INDEX_FILE){
  wordCount_files palabras;
  for(const auto& file : files){
    agregaPalabrasMapa(palabras,file);
  }
  crearIndexFile(palabras, INVERTED_INDEX_FILE);
}

void agregaPalabrasMapa(wordCount_files& map, std::string filePath){
  std::ifstream file(filePath);
  std::string name = filePath.substr(filePath.find_last_of("/")+1,filePath.length());
  std::string linea;
  while(getline(file, linea)){
    if(linea == "") std::cout << "Perro" << std::endl;
    else{
      std::string word = linea.substr(0,linea.find(";"));
      int count = stoi(linea.substr(linea.find(";")+1,linea.length()));
      map[word][name] = count;
      // std::cout << word << ";(" << name << "," << count << ")" << std::endl;
    }
  }
  file.close();
}

void crearIndexFile(wordCount_files& map, std::string INVERTED_INDEX_FILE){
  std::ofstream outFile(INVERTED_INDEX_FILE, std::ios::trunc);    
  for(auto& i: map){
    std::string palabra = i.first;
    outFile << palabra << ":";
    bool primerElemento = true;
    for(auto& j: i.second){
      std::string nameFile = j.first;
      int count = j.second;
      if (primerElemento){
        outFile << "(" << nameFile << "," << count << ")";
        primerElemento = false;
      } else {
        outFile << ";(" << nameFile << "," << count << ")";
      }
    }
    outFile << std::endl;
  }
  outFile.close();
  std::cout << "El proceso pid = " << pid << " - generó el archivo = " << INVERTED_INDEX_FILE << std::endl;
}