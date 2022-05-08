#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv){
	int var;
	int *p = &var ; // p apunta a la posicion de memoria de var
	
	*p = 20;
	// asigna un valor en la posicion de memoria.
	cout << "Direccion de var: " << &var << " y var = " << var << endl;
	
	if (p != nullptr)
		cout << "p apunta a " << p << " y guarda ∗p = " << *p << endl;
	p = NULL;
	if (p == nullptr)
		cout << "p apunta a nada !! " << endl;

	cout << "Direccion de p: " << &p << endl;

	return EXIT_SUCCESS;
}


