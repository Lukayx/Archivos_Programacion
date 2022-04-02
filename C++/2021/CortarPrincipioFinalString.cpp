#include <iostream>
#include <string>
using namespace std;

// ESTE CODIGO LO QUE HACE ES RECORTAR TODA LA CANTIDAD DE UN CARACTER EN EL PRINCIPIO Y FINAL DE UN STRING //

string strip(string txt, char c){
    int pos = 0;// posiciona el puntero al principio del string
    while(txt[pos] == c)// cuando salga del bucle devolverá el indice donde termina la búsqueda del caracter (principio)
        pos++;
    txt = txt.substr(pos,txt.size()-pos); // almacenara el nuevo texto recortado en el principio
    cout << "Resultado Strip izq: " << txt << endl;
    pos = txt.size()-1;// posiciona el puntero al final del string
    while(txt[pos] == c)// cuando salga del bucle devolverá el indice donde termina la búsqueda del caracter (final)
        pos--;
    txt = txt.substr(0,pos+1);  // almacenara el nuevo texto recortado en el final
    cout << "Resultado Strip der: " << txt << endl;
    return txt; // devuelve texto recortado al principio y al final
}

int main() {
    cout << strip("..............PERROPEEROO .... PERRO.....",'.') << endl;
    return 0;
}

