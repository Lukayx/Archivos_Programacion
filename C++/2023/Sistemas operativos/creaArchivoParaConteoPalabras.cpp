#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outputFile("large_file.txt");

    if (!outputFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
        return 1;
    }

    const int fileSizeMB = 1024;  // Tamaño deseado en MB
    const int bufferSize = 1024;  // Tamaño del buffer en bytes (1 KB)

    // Generar un buffer lleno de contenido repetitivo
    std::string buffer;
    for (int i = 0; i < bufferSize; ++i) {
        buffer += "a";
    }

    // Escribir el buffer repetido en el archivo para alcanzar el tamaño deseado
    for (int i = 0; i < fileSizeMB * (1024 / bufferSize); ++i) {
        outputFile << buffer;
    }

    outputFile.close();
    std::cout << "Archivo generado exitosamente." << std::endl;

    return 0;
}
