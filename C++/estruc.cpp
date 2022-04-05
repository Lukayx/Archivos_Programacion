#include <iostream>
#include <cstdlib>

using namespace std;

struct Persona {
    char nombre[50]; //1 byte por char
    int edad; // 4 bytes
    float sueldo; // 4 bytes 
};

int main(){
    Persona p1;
    cout << "Ingrese el nombre completo: ";
    cin.get(p1.nombre, 50);
    cout << "Ingrese la edad: ";
    cin >> p1.edad;
    cout << "Ingrese el sueldo: ";
    cin >> p1.sueldo;
    //ESCRIBIRÁ EN PANTALLA LOS DATOS GUARDADOS
    cout << "\nInformacion guardada en el struct Persona p1 " << endl;
    cout << "p1.nombre: " << p1.nombre << endl;
    cout << "p1.edad: "<< p1.edad << endl;
    cout << "p1.sueldo: "<< p1.sueldo << endl;

    return 0;
}