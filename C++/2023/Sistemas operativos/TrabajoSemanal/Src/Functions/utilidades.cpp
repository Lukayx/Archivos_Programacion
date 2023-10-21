// utilidades.cpp
#include "../../Include/utilidades.h"

std::string isSpecialCharacter(const char* c) {
    const char current = *c;  // Obtener el carácter actual
    // Comprueba si es un espacio o un dígito
    const char* letras[] = {
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
        "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
        "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
    };
    std::string d(1, current); // Convierte el carácter actual en std::string
    for (int i = 0; i < 52; i++) {
        if (d == letras[i]) return letras[i];
    }
    if (std::isspace(current)) return " ";
    if (std::isdigit(current)) return "";
    // Verifica si es una letra acentuada en mayúsculas
    unsigned char current2 = static_cast<unsigned char>(*c);
    if (current2 == 0xC3) {
        c++; // Avanza al siguiente byte
        unsigned char next = static_cast<unsigned char>(*c);
        switch (next) {
            case 0x81: return "Á";
            case 0x89: return "É";
            case 0x8D: return "Í";
            case 0x93: return "Ó";
            case 0x9A: return "Ú";
            case 0x91: return "Ñ";
            case 0xB1: return "ñ";
            case 0xA1: return "á";
            case 0xA9: return "é";
            case 0xAD: return "í";
            case 0xB3: return "ó";
            case 0xBA: return "ú";
            case 0xBC: return "ü";
            case 0x9C: return "Ü";
        }
    }
    return ""; // Si no coincide con nada, se considera un carácter especial
}