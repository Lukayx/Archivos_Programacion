#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <time.h>
using namespace std;

#define MAX_INC 10

struct myStruct {
	int prim;
	int seg;
	myStruct *prox;
};typedef struct myStruct dupla;


vector<dupla*> creaIntermedio(dupla *l, int n);
int buscaDosPasos(vector<dupla*> &M, int x);
void appendToListR(dupla **l, int num, int indices);

// MÉTODOS YA CODIFICADOS Y LISTOS PARA UTILIZAR
int binarySearchSampling(vector<dupla*> &M, int x);
void printLista(dupla *l);
void printArray(vector<dupla *> &M);

int main(int argc, char **argv){
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./problema n" << endl;
		exit(EXIT_FAILURE);
	}
    int n = atoi(argv[1]),num, aux = 0;
    srand(time(NULL));
	dupla *l = NULL;
    for(int i = 0; i < n; i++){
        num = aux + (1 + rand()%MAX_INC);
        appendToListR(&l,num,i);
        aux = num;
    }
    printLista(l);
    vector<dupla*> M = creaIntermedio(l,n);
    printArray(M);
    int x;
        cout << "Ingrese entero a buscar (negativo para finalizar)" << endl;
    while(true){
        cout << "x = ";
        cin >> x;
        if(x < 0) break;
        x = buscaDosPasos(M,x);
    }
	cout << "### Fin Control 1 ###" << endl;
	return EXIT_SUCCESS;
}

void appendToListR(dupla **l, int num, int indice){
	dupla *nuevo = new dupla;
    nuevo->prim = indice;
	nuevo->seg = num;
	nuevo->prox = NULL;
    if(*l == nullptr){
        *l = nuevo;
    } else {
        dupla *p = *l;
        while(p->prox != nullptr) p = p->prox;
        p->prox = nuevo;
    }
}

vector<dupla*> creaIntermedio(dupla *l, int n){
    dupla *p = l;
    vector<dupla*> M(0);
    int c = 0;
    while(p != nullptr){
        if(c%4==0){
            M.push_back(p);
        }
        c++;
        p = p->prox;
    }
    return M;
}

// devuelve el primelativo del nodo cuyo seg es x, o -1 si no existe
int buscaDosPasos(vector<dupla*> &M, int x){
    int m = binarySearchSampling(M,x);
	if(m != -1){
	    dupla *p = M[m];
		cout << "... comenzando en dupla M["<<m<<"] con (prim,seg) = ("<<p->prim<<","<<p->seg<<") --> ";
		while(p!= nullptr && p->seg < x) p = p->prox;
		if(p != nullptr && p->seg==x){
			cout << "Encontrado con prim = " << p->prim << endl;
			return p->prim;
		}
	}
	cout << "No encontrado" << endl;
	return -1;

}

// ===========================================================================================
// MÉTODOS LISTOS PARA UTILIZAR

// Búsqueda binaria de x en M[0...M.size()-1], tal que todos los elementos de M son distintos:
// 	return -1, Si x < M[0]->seg
// 	return M.size()-1, Si M[M.size()-1]->seg <= x
// 	return m, Si M[m]->seg <= x < M[m+1]->seg
int binarySearchSampling(vector<dupla*> &M, int x){
	int l, r, m, u=M.size();
	if (x < M[0]->seg)
		return -1;
	if (M[u-1]->seg <= x)
		return u-1;	
	l=0, r=u-1, m=r/2;
	while(l<=r){
		if (M[m]->seg <= x && x < M[m+1]->seg)
			return m;
		else{
			if (x < M[m]->seg)
				r=m-1;
			else
				l=m+1;
		}
		m=(l+r)/2;
	}
	return m;
}


void printArray(vector <dupla*> &M){
	cout << "Vector M = " << endl;
	for(unsigned int i=0; i<M.size(); i++)
		cout << "(" << M[i]->prim << ", " << M[i]->seg << ") ";
	cout << endl;
}

void printLista(dupla* l){
	dupla *p = l;
	cout << "Lista :" << endl;
	while (p != nullptr){
		cout << "(" << p->prim << ", " << p->seg << ") ";
		p = p->prox;
	}
	cout << endl;
}

/*
================================
MÉTODOS DESARROLLADOS EN CLASES
================================

// añade un nodo al inicio de la lista
void appendToListL(nodo **l, int num){
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = *l;
	*l = nuevo;
}

// añade un nodo al final de la lista
void appendToListR(nodo **l, int num){
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = NULL;

	cout << "Aniadiendo a la cola el nodo con val = " << num << endl;
	if (*l == nullptr)
		*l = nuevo;
	else{
		nodo *p = *l;
		while (p->next != nullptr)
			p = p->next;

		p->next = nuevo;
	}
}
*/