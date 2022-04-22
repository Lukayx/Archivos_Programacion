#include <iostream>
#include <cstdlib>
using namespace std;

void listaMisDigitos(int x);
void listaMisDigitosLR(int x);
void listaMatriz(int **M,int n,int m);

int main(int argc, char **argv){
	int n,m,f,c; 
	int **M;
	cout << "Ingrese entero positivo: ";
	cin >> n;
	while (n<=0){
		cout << "Error, debe ser positivo: ";
		cin >> n;
	}
	cout << "Ingrese entero positivo: ";
	cin >> m;
	while (n<=0){
		cout << "Error, debe ser positivo: ";
		cin >> m;
	}

	M = new int*[n];
	for(f=0;f<n;f++){
		M[f] = new int[m];
		for(c=0;c<m;c++){
			M[f][c] = 100 + rand()%900; 
		}
	}
	listaMatriz(M,n,m);
	cout << "Programa terminado exitosamente !!" << endl;
	return EXIT_SUCCESS;
}

void listaMatriz(int **M, int n, int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}

// Función que lista los dígitos de x de izquierda a derecha.
// Ejemplo si x=12345 --> debe imprimir 12345
void listaMisDigitosLR(int x){
	// TAREA
}

// Función que lista los dígitos de x de derecha a izquierda.
// Ejemplo si x=12345 --> debe imprimir 54321
void listaMisDigitos(int x){
	// TAREA
}

