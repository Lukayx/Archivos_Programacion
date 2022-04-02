#include <iostream>
using namespace std;
int main(){
    int x;
    x=4;
    cout << "Valor o contenido de x: " << x << endl;
    cout << "Direccion de memoria de x: "<< &x << endl;
    int *p;
    cout << "Se ha creado el puntero p" << endl;
    cout << "Su valor o contenido es: " << p << endl;
    cout << "(localizacion de memoria)" << endl;
    cout << "Direccion de memoria de p: " << &p << endl;
    p = &x;
    cout << "Nuevo contenido de p = " << p << endl;
    cout << "Observe que puntero p ahora señala " << endl;
    cout << "a la direccion donde se encuentra la variable x"<< endl;
    *p = 7;
    cout << "acceso a contenido de x usando puntero p: " << *p << endl;
    
    return 0;
}