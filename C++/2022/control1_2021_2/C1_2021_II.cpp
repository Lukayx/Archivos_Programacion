#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h> 
#include <queue>
#include <cmath>
using namespace std;

#define M 10

// Cree aquí su estructura...
struct myStruct {
	float dist;	// distancia entre 'val' y la media de A
	int val;	// valor a buscar en A con distancia 'dist' de la media
	int pos;	// posición del valor 'val' encontrado en A con esta distancia 'dist'
};typedef struct myStruct dato;

float generaEnteros(int* A, int n);
void insertionSortMed(int* A, int n, float med);
void binarySearchMed(int *A, int n, float med, queue<dato> &q);
void printArray(int* A, int n);

int main(int argc, char **argv){
	if(argc != 3){
		cout << "Error. Debe ejecutarse como ./problema n k" << endl;
		exit(EXIT_FAILURE);
	}
	// 1 punto
	srand(time(NULL));
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);

	int *A = new int[n];
	float med = generaEnteros(A,n);
	printArray(A,n);
	cout << "La media aritmetica es: " << med << endl;
	insertionSortMed(A,n,med);
	printArray(A,n);
	queue<dato> q;
	dato aux;
	for (int i = 0; i < k; i++){
		cout << "Ingrese distancia N°" << i+1 << ": ";
		cin >> aux.dist;
		aux.val = M + 1;
		aux.pos = -1;
		q.push(aux); // EL PUSH ES POR EL FINAL DE LA COLA POR LO QUE NO LA RECORRE PARA AGREGAR Y ES O(1) 
	}

	cout << "### Fin Control 1 ###" << endl;
	return EXIT_SUCCESS;
}

// 0.5 puntos
float generaEnteros(int* A, int n){
	float med = 0;
	for (int i = 0; i < n; i++){
		A[i] = rand()%21 - M;
		med+=A[i];
	}
	med /= n; 
	return med;
}

// Ordena A descendentemente por la distancia a la media 
// 2.0 puntos
void insertionSortMed(int* A, int n, float med){
		int i,j,key;
		float dist;
	for(i=1; i<n; i++){
		key = A[i];
		dist = abs(A[i] - med);
		j = i-1;
		while (j>=0 && abs(A[j]-med)<dist){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}	
}



// Búsqueda binaria de cada valor de q en el arreglo A[0...n-1] que ha sido ordenado con insertionSortMed().
// 2.5 ountos
void binarySearchMed(int *A, int n, float med, queue<dato> &q){
	
}

void printArray(int* A, int n){
	cout << "A = ";
	for(int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
}



// ========================================================================
// ALGORITMOS DESARROLLADOS EN CLASES QUE LE SERVIRÁN COMO GUÍA...
//
// ordena ascendentemente los elementos de A con el algoritmo insertionSort
void insertionSort(int* A, int n){
	int i,j,key;

	for(i=1; i<n; i++){
		key = A[i];
		j = i-1;
		while (j>=0 && A[j]<key){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}

// Búsqueda binaria de x en un arreglo A[0...n-1].
// Si existe, devuelva la posicion de x en A[], sino devuelva -1
int binarySearch(int *A, int n, int x){
	int l,m,r;

	l=0;
	r=n-1;
	m=r/2;
	while(l<=r){
		if (x<A[m])
			r=m-1;
		else{
			if (x==A[m])
				return m;
			else
				l=m+1;
		}
		m=(l+r)/2;
	}
	return -1;
}


