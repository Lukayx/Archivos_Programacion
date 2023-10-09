// utilidades.cpp
#include "../../Include/utilidades.h"

bool isSpecialCharacter(unsigned char c) {
    if (c == ' ') return false;
    if (c == 225 || c == 233 || c == 237 || c == 243 || c == 250 || c == 193 || c == 201 || c == 205 || c == 211 || c == 218) {
        return false;
    }
    if (isdigit(c)) return true;
    return !isalnum(c);
}
