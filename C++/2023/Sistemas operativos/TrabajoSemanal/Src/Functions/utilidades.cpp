// utilidades.cpp
#include "../../Include/utilidades.h"

std::string isSpecialCharacter(const char* c) {
    const char current = *c;  // Obtener el carácter actual
    unsigned char current2 = static_cast<unsigned char>(*c);
    // Comprueba si es un espacio o un dígito
    if (std::isdigit(current)) return "";
    if (std::isspace(current)) return " ";
    // Verifica si es una letra acentuada en mayúsculas
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
    const char* letrasMayusculas[] = {
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
        "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
    };

    const char* letrasMinusculas[] = {
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
        "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
    };

    std::string d(1, current); // Convierte el carácter actual en std::string

    for (int i = 0; i < 26; i++) {
        if (d == letrasMayusculas[i]) return letrasMayusculas[i];
        if(d == letrasMinusculas[i]) return letrasMinusculas[i];
    }

    return ""; // Si no coincide con nada, se considera un carácter especial
}