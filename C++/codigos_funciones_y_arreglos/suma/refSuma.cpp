#include <iostream>
using namespace std;

// suma local:
void suma(int p);

// usando punteros:
void suma10(int* p);

// usando referencias:
void sumaDenuevo(int& p);

int main(){
	int x = 10;
	cout << "Valor original de x = " << x << endl ;

	suma(x);     		// damos una copia de x como argumento
	cout << "Despues de llamar a suma(x): x = " << x << endl; 

	suma10(&x);     		// damos la direccion de memoria de x como argumento
	cout << "Despues de llamar a suma10(&x): x = " << x << endl;
	
	sumaDenuevo(x);		// damos una copia del valor de x como argumento
	cout << "Despues de llamar a sumaDenuevo(x): x = " << x << endl;
	
	sumaDenuevo(x);
	cout << "Volvemos a llamar a sumaDenuevo(x): x = " << x << endl;
}

// suma local y sin sentida ya que no delovemos su valor
void suma(int p){
	p = p + 999999; // este nuevo valor se perderá
}

// recibe un punero a un alocalidad de memoria int
void suma10(int* p){
    *p = *p + 10;	// con *p acedo al valor de p
}

// al recibir la variable int, trabaja con su direccion de memoria
void sumaDenuevo(int& p){
    p = p + 10; // aquí no se usa *p
}


