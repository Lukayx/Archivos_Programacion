#include <iostream>
using namespace std;

template <typename T>
T maximo(T a, T b, T c){ // Soporta solamente 3: INT - FLOAT - CHAR | TIENEN QUE SER LAS 3 VARIABLES DEL MISMO TIPO
    T x = a>b?a:b; // SI 'a' es mayor que 'b' entonces retorna 'a', SINO entonces retorna 'b' (a:b)=(true:false)
    return c>x?c:x; // Aqui lo mismo que lo de arriba
}

int main(){
    int a = 5, b = 8, c = 2;
    cout << maximo(a, b, c) << endl;
    float x = 5.5, y = 8.8, z = 2.2;
    cout << maximo(x, y, z) << endl;
    char u = 'W', t = 'T', w = 'F';
    cout << maximo(u, t, w) << endl;
    return 0;
}