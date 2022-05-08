/*
Completar para listas doblemente enlazadas !!
*/

#include <iostream>
#include <cstdlib>
using namespace std;

struct nodeDoubleList {
	int val;
	nodeDoubleList* prev;
	nodeDoubleList* next;
};
typedef struct nodeDoubleList nodoD;

# define MAX 40

void appendToListL(nodoD **l, int num);
void insertInList(nodoD **l, int num);
bool removeFromList(nodoD **l, int num);
void printList(nodoD *l);

int main(int argc, char **argv){
	int i, x;
	//int min, max;
	//float med;
	nodoD *L = NULL; // creamos una lista vacía L

	// agregamos 10 nuevos nodos a L...
	for (i=1; i<=10; i++){
		x = 110-i*10;
		appendToListL(&L, x); // agregamos x por la izquierda
	}
	cout << "L = ";
	printList(L);	

	x=75;
	insertInList(&L, x);
	printList(L);
	
	x=5;
	insertInList(&L, x);
	printList(L);

	x=120;
	insertInList(&L, x);
	printList(L);
	
	/*i=30;
	if(removeFromList(&L, i)){
		cout << "Nodo i = " << i << " Eliminado" << endl;
		printList(L);		
	}else
		cout << "Nodo i = " << i << " No encontrado" << endl;

	i=21;
	if(removeFromList(&L, i)){
		cout << "Nodo i = " << i << " Eliminado" << endl;
		printList(L);		
	}else
		cout << "Nodo i = " << i << " No encontrado" << endl;

	i=5;
	if(removeFromList(&L, i)){
		cout << "Nodo i = " << i << " Eliminado" << endl;
		printList(L);		
	}else
		cout << "Nodo i = " << i << " No encontrado" << endl;

	i=120;
	if(removeFromList(&L, i)){
		cout << "Nodo i = " << i << " Eliminado" << endl;
		printList(L);		
	}else
		cout << "Nodo i = " << i << " No encontrado" << endl;*/

	return EXIT_SUCCESS;
}

// aniade un nodo al inicio de la lista --> Costo Constante = O(1)
void appendToListL(nodoD **l, int num){

}


// inserta el nodo en su posicion correcta (ascendente)
// Mi lista enlazada es *l y **l es la dirección de memoria de mi lista
// ASUME QUE LA LISTA ESTA ORDENADA CRECIENTEMENTE
void insertInList(nodoD **l, int num){

}


// elimina el primer nodo de la lista con valor num que encuentra y retorna true
// (de izquierda a derecha). Si no lo encuentra retorna false
bool removeFromList(nodoD **l, int num){
	return false;
}


// Costo lineal : O(n
void printList(nodoD *l){
	nodoD *p = l;
	//cout << "Lista :" << endl;
	while (p != nullptr){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
