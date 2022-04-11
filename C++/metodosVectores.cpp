#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void empty_ejemplo();
void push_y_at();

int main(){
    
}

void push_y_at(){
    string nombre = "Fernando";
    int n = 10; // TAMAÑO VECTOR
    vector<int> numeritos(n);
    for(int i=0;i<n;i++) {
        numeritos.at(i)=i+1; //EL AT EN VECTORES TE PERMITE ACCEDER A UN INDICE DEL MISMO
        numeritos.push_back((i+1)*2); // AGREGA OTRO INDICE DESPUES DEL MAXIMO Y AÑADE UN VALOR
    }
    for(int i=0;i<numeritos.size();i++){ // EL SIZE() TE RETORNA EL TAMAÑO REAL DEL VECTOR
        cout << numeritos.at(i) << " ";            
    } 
}
void empty_ejemplo(){
    string nombre = "Fernando";
    int n = 10; // TAMAÑO VECTOR
    vector<int> numeritos(n);
    if(numeritos.empty()){
        cout << "perro" << endl;
        cout << numeritos.empty()<<endl;
    } else {
        cout << "gato" << endl;
        cout << numeritos.empty()<<endl;
    }
}