#include <iostream>   //Biblioteca donde se encuentra la función cout y cin
// I(input) O(Output) STREAM(Flujo de datos)
#include <string>
using namespace std;  //uso del espacio de nombre std

int main() {
	int x = 2;         		// un entero usa 4 bytes _______ numeros0 - 2^32-1
	long int y = 100;		// un entero largo usa 8 bytes ________ 2^64-1
	float pi = 3.1416; 		// un real
	double w = 0.0;		    //flotante de 8 bytes 2^64-1
	char c = 'a';      		// un caracter singular
	char curso[10] = "INFO088";	// un arreglo de char’s
	string s;          		// un string, este posee gran soporte en <string> para 
					// varias funciones típicas con cadenas de caracteres

	cout << "x = " << x << ", y  = " << y << endl;	
	cout << "curso[0] = " << curso[0] << endl;	
	cout << "curso[1] = " << curso[1] << endl;
	cout << "curso[2] = " << curso[2] << endl;
	cout << "curso[9] = " << curso[9] << endl;	
	{
		int x = 0;
		x = 77;	
		cout << "(Dentro de las llaves) x = " << x << endl;	
	}
	cout << "(Fuera de las llaves) x = " << x << endl;	

	cout << "Holas !! Estamos comenzando el curso " << curso << endl; //Imprime
	cout << "Ahora leemos algo desde la entrada estándar (teclado)." << endl;
	cout << "Ingrese un Número entero: ";
	cin >> x;			// lee desde el teclado

	cout << "Ingrese una palabra: ";
	cin >> s;
	cout << "Has ingresado x = " << x << ", s = " << s << endl;

	return 0;
}



