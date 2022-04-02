#include <iostream>
#include <string>
using namespace std;

string mezcla(string txt1,string txt2){
    string abc = "abcdefghijklmnopqrstuvwxyz"; // Abecedario que servirá como puntero
    string txt; // Texto en el que se ordenaran las letras
    for(int i=0;i<abc.size();i++){ // se repetirá según el largo del abecedario
        if(txt1.find(abc[i])!=txt1.npos)// Busca letra del abecedario en Texto 1
            txt+=abc[i];
        if(txt2.find(abc[i])!=txt2.npos)// Busca letra del abecedario en Texto 2
            txt+=abc[i];
    }
    return txt; // Devuelve el texto ya ordenado
}

int main(){
    cout << mezcla("abdfglnop","bcehijkmqrs") << endl;
    return 0;
}