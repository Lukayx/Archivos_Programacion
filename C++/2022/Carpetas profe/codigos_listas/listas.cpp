#include <iostream>
#include <cstdlib>
using namespace std;

struct nodeList {
	int val;
	nodeList* next;
};
typedef struct nodeList nodo;

# define MAX 40

void appendToListL(nodo **l, int num);
void appendToListR(nodo **l, int num);
void insertInList(nodo **l, int num);
bool removeFromList(nodo **l, int num);
void printList(nodo *l);

float mediaList(nodo *l);
int minList(nodo *l);
int maxList(nodo *l);
void minMaxMedia(nodo *l, int *min, int *max, float *media);

void appendList(nodo **l, nodo *q);
void addPrevVal(nodo *l);
void insertList(nodo **l, nodo *q);

int main(int argc, char **argv){
	int i, x;
	//int min, max;
	//float med;
	nodo *L = NULL; // creamos una lista vacía L

	// agregamos 10 nuevos nodos a L...
	for (i=1; i<=10; i++){
		x = i*10;
		appendToListL(&L, x); // agregamos x por la izquierda
		//appendToListR(&L, x); // agregamos x por la derecha
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

	/*cout << " minino = " << minList(L) << endl;
	cout << " maximo = " << maxList(L) << endl;
	cout << " media = " << mediaList(L) << endl;
	
	minMaxMedia(L, &min, &max, &med);
	cout << " min = " << min << endl;
	cout << " max = " << max << endl;
	cout << " med = " << med << endl;	
	
	i=30;
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
void appendToListL(nodo **l, int num){

}

// aniade un nodo al final de la lista --> Costo lineal = O(n)
void appendToListR(nodo **l, int num){

}

// inserta el nodo en su posicion correcta (ascendente)
// Mi lista enlazada es *l y **l es la dirección de memoria de mi lista
// ASUME QUE LA LISTA ESTA ORDENADA CRECIENTEMENTE
void insertInList(nodo **l, int num){
	/*
		nodo *nuevo_nodo = new nodo();
	nuevo_nodo->val = num;
	nodo *p = *l;
	if(num < p->val){
		nuevo_nodo->next = *l;
		*l = nuevo_nodo;
	} else {
		p = p->next;
		while (num > p->val){
			p = p->next;
		}
		
	}
	*/
}

void appendList(nodo **l, nodo *q){

}

// elimina el primer nodo de la lista con valor num que encuentra y retorna true
// (de izquierda a derecha). Si no lo encuentra retorna false
bool removeFromList(nodo **l, int num){

	return false;
}


// Costo lineal : O(n)
int minList(nodo *l){
	nodo *p = l;
	float men = p->val;
	while(p->next!=nullptr){
		p = p->next;
		if(men > p->val){
			men = p->val;
		}
	}
	return men;
}

// Costo lineal : O(n)
int maxList(nodo *l){
	nodo *p = l;
	float may = p->val;
	while(p->next!=nullptr){
		p = p->next;
		if(may < p->val){
			may = p->val;
		}
	}
	return may;
}

// Costo lineal : O(n)
float mediaList(nodo *l){
	nodo *p = l;
	if(p = nullptr){
		return 0;
	}
	float sum = 0, cont = 0;
	while(p->next != nullptr){
		c+=1;
		sum += p->val;
		p = p->next; 
	}

	return 0;
}

// Costo lineal : O(n
void minMaxMedia(nodo *l, int *min, int *max, float *media){

}

// Costo lineal : O(n
void printList(nodo *l){
	nodo *p = l;
	//cout << "Lista :" << endl;
	while (p != nullptr){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
