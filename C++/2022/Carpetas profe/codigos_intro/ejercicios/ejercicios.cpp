
#include <iostream>	// Biblioteca donde se encuentran las funciones "cin" y "cout"
#include <cstring>	// usaremos la función "strcpy()" que se encuantra en string.h
using namespace std;	// uso del espacio de nombres std (es el lugar donde buscar los recursos que estemos utilizando en este programa)

void imprimeEnOrden(int a, int b, int c){
	if(a<=b){
		if(a<=c){ //a<b
			if(b<=c){
				cout << a << "<" << b << "<" << c << endl;
			} else {
				cout << a << "<" << c << "<" << b << endl;
			}
		}else {
			cout << c << "<" << a << "<" << b << endl;
		}
	} else if (c<=b){
		cout << c << "<" << b << "<" << a << endl;
	} else if(c<=a){
		cout << b << "<" << c << "<" << a << endl;
	} else {
		cout << b << "<" << a << "<" << c << endl;
	}
} 

int main(int argc, char **argv){
	int a, b, c;
	cout << "ingrese 3 numeros" << endl;
	cout << "Numero 1: ";
	cin >> a;
	cout << "Numero 2: ";
	cin >> b;
	cout << "Numero 3: ";
	cin >> c;

	imprimeEnOrden(a, b, c);

	cout << "Programa terminado exitosamente !!" << endl;
	return EXIT_SUCCESS;
}


/* 			            a <= b
                        S/       \N
                      a<=c   
                    /    \  
                 b<=c
                /    \        
              a,b,c  a,c,b          
                        
*/
