// problema2.cpp
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

#define MAX 10000000
#define MIN 1000000

struct nodeDoubleList{
	int val;
	nodeDoubleList *prev;
	nodeDoubleList *next;
};

typedef struct nodeDoubleList nodo;

// Los encabezados de las funciones a implementar:
// PUEDEN AÑADIR ARGUMENTOS A LAS FUNCIONES (aunque no es necesario)
void creaVectorV(vector<int> &V);
void creaVectorX(vector<int> &V, vector<int> &X);
int reduceRecursivo(int num);
void insertBeforeDoubleList(nodo **H, int b, int num);

void printVector(vector<int> &V); // Código entregado
void appendToDoubleListR(nodo **H, int num); // Código entregado
void printDoubleList(nodo *H); // Código entregado

// 0.5 ptos
int main(int argc, char **argv){
	if(argc != 3){
		cout << "Error. Debe ejecutarse como ./problema2 n b" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "### Fin Problema 2 ###" << endl;
	return EXIT_SUCCESS;
}

// 0.3 ptos.
void creaVectorV(vector<int> &V){
	// Se crean n elementos aleatorios entre MIN y MAX-1 que se agregan
	// al vector 
}

// 0.3 ptos
void creaVectorX(vector<int> &V, vector<int> &X){
	// A partir del vector V, se crea el vector X, el cual ha de usar la
	// función recursiva reduceRecursiva() para sumar, para cada V[i], todos
	// sus dígitos impares, obteniendo X[i]. Por ejemplo, si V[i] = 8692777,
	// X[i] será (9+7+7+7) = 30
}

// 0.7 ptos.
int reduceRecursivo(int n){
	// función recursiva que retorna la suma de los dígitos impares de num,
}

// 0.7 ptos.
void insertBeforeDoubleList(nodo **H, int b, int num){
	// Inserta, antes de b (dado como argumento del programa), el entero ni.
	// Si no encuentra b, imprime un mensaje de error
}



// Funciones implementadas
void printVector(vector<int> &V){
	int n = V.size();
	for(int i = 0; i < n; i++){
		cout << V[i] << " ";
	}
	cout << endl;
}

void appendToDoubleListR(nodo **H, int num){
	nodo *nuevo = new nodo;
	nuevo->val = num;
	if(*H == nullptr){
		nuevo->next = *H;
		nuevo->prev = NULL;
		*H = nuevo;
	}
	else{
		nodo *p = *H;
		while(p->next != nullptr){
			p = p->next;
		}
		p->next = nuevo;
		nuevo->next = NULL;
		nuevo->prev = p;
	}
}

void printDoubleList(nodo *H){
	nodo *p = H;
	while(p != nullptr){
		cout << p->val;
		p = p->next;
		if(p != nullptr)
			cout << " - ";
	}
	cout << endl;
}
