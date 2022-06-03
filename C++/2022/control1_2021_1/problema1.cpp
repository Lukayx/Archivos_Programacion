// Problema1.cpp
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <random>
#include <time.h>

#define MAX 99

using namespace std;


struct nodeList {
	int val;
	nodeList* next;
}; typedef struct nodeList nodo;

struct celdaS {
	int val;
	nodeList* p;
}; typedef struct celdaS celda;

void inserInList(nodo **L, int num);
void printList(nodo *L);
void printMuestras(celda *M, int m);
bool buscaEntero(nodo *L, celda *M, int n, int k, int x);

//=================================main===================================
int main(int argc, char **argv){
	if(argc != 3){
		cout << "Error. Debe ejecutarse como ./problema1 n k" << endl;
		exit(EXIT_FAILURE);
	}
	int n = atoi(argv[1]), k = atoi(argv[2]);
	srand(time(NULL));
	nodo *L = NULL;
	for (int i = 0; i < n; i++){
		inserInList(&L,(1 + rand()%(MAX-1)));
	}
	celdaS M[n/k];
	nodo *aux = L;
	int cont = 0, indice = 0;
	while(aux!=nullptr && indice < n/k){
		if(cont%k == 0){
			M[indice].val = aux->val;
			M[indice].p = aux;
			indice++;
		}
		cont++;
		aux = aux->next;
	}
	int num;
	while(num != 0){
		cout << "Ingrese valor a buscar, x: ";
		cin >> num;
		if(buscaEntero(L,M,n,k,x);){
			cout << 
		}
	}
	printList(L);
	printMuestras(M,n/k);
	cout << "### Fin Problema 1 ###" << endl;
	return EXIT_SUCCESS;
}
//=================================funciones===================================
// inserta el entero en su posicion correcta (ascendente)
void inserInList(nodo **L, int num){
	nodo *nuevo = new nodo;
	nuevo->val = num;

	if(*L == nullptr || (*L)->val >= num){
		nuevo->next = *L;
		*L = nuevo;
	}
	else{
		nodo *p = *L;
		while(p->next != nullptr && p->next->val < num){
			p = p->next;
		}
		nuevo->next = p->next;
		p->next = nuevo;
	}
}

// imprime la lista L
void printList(nodo *L){
	nodo *p = L;
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

// imprime el arreglo de muestras M 
void printMuestras(celda *M, int m){
	cout << "M[0.." << m-1 << "] = ";
	for (int i=0; i<m; i++){
		cout << M[i].val << " ";
	}
	cout << endl;
}

bool buscaEntero(nodo *L, celda *M, int n, int k, int x){
	return false;
}
