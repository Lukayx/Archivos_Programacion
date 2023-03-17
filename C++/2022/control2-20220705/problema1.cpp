#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>
using namespace std;

#define M 100
void makeMaxHeap(int *X, int n);
void intercambiaHijos(int *X, int n, int p);
void printHeap(int *X , int n);

int main(int argc, char **argv){
	int n, i, p;
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./problema1 n" << endl;
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));
	n = atoi(argv[1]);
	int *X = new int[n+1];
	for (i = 1; i <= n; i++){
		X[i] = rand()%M;
	}
	makeMaxHeap(X,n);
	printHeap(X,n);
	do{
		cout << "Ingrese posicion del arreglo (p): ";
		cin >> p;
	}while(p <= 0 || p > n);
	intercambiaHijos(X,n,p);
	printHeap(X,n);

	cout << "### Fin Problema 1 ###" << endl;
	return EXIT_SUCCESS;
}


void intercambiaHijos(int *X, int n, int p){
	int hijo = p*2, aux, padre, h,x;
	if(hijo+1<=n){
		aux = X[hijo];
		X[hijo] = X[hijo+1];
		X[hijo+1] = aux;
		makeMaxHeap(X,n);
		aux = hijo;
		
		padre = hijo;
		x = X[padre*2];
		h = padre*2;
		while(padre>0 && x>X[padre]){ // se intercambia si mi padre X[p] es menor
			X[h] = X[padre];
			h = padre;
			padre = padre/2;
		}
		X[h] = x;
		
		padre = aux+1;
		x = X[padre*2];
		h = padre*2;
		while(padre>0 && x>X[padre]){ // se intercambia si mi padre X[p] es menor
			X[h] = X[padre];
			h = padre;
			padre = padre/2;
		}
		X[h] = x;
	}
}

// cada valor X[i], i=2,3,4....,n, sube hasta su posición correcta
void makeMaxHeap(int *X, int n){
	int x, i, p, h; // p:padre actual y h:su hijo
	for(i=2; i<=n; i++){
		x = X[i];
		p = i/2;
		h = i;
		while(p>0 && x>X[p]){ // se intercambia si mi padre X[p] es menor
			X[h] = X[p];
			h = p;
			p = p/2;
		}
		X[h] = x;
	}
}


void printHeap(int *X , int n){
	cout << "heap X[] =" << endl;
	for (int i=1; i<=n; i++)
		cout << ""<<i<<"[" << X[i] <<"] " ;
	cout << endl << endl;
}
