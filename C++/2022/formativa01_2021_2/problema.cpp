#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>
using namespace std;

void llenaArray(int *A, int n);
void quickInsert(int *A, int l, int r, int umbral);
void insertionSort(int* A, int l, int r);
void listaArray(int* A, int l, int r);

// 1 Punto
int main(int argc, char **argv){	
	if(argc != 2 && atoi(argv[1])>1){
		cout << "Error. Debe ejecutarse como ./problema n" << endl;
		exit(EXIT_FAILURE);
	}
	int umbral,n;
	srand(time(NULL));
	cout << argv[1] << endl;
	n = atoi(argv[1]);
	int *A = new int[n];
	llenaArray(A,n);
	listaArray(A,0,n-1);

	cout << "Ingrese el umbral: ";
	cin >> umbral;

	quickInsert(A,0,n-1,umbral);
	listaArray(A,0,n-1);

	cout << "### Fin Problema ###" << endl;
	return EXIT_SUCCESS;
}

// 1 Punto
void llenaArray(int *A, int n){
	int minVal,maxVal;
	do{
		cout << "Ingrese el minimo: ";
		cin >> minVal;
		cout << "Ingrese el maximo: ";
		cin >> maxVal;
	}while(minVal>maxVal);
	for (int i = 0; i < n; i++){
		A[i]=minVal + rand()%(maxVal-minVal+1);// si fuese hasta el 100 generaria  de 0 a 99 por lo que se le suma 1
	}
}

// 1.5 Puntos
// Adapte el insertionSort() original para que ordene ascendentemente A[l..r] con el algoritmo insertionSort.
// No olvide poner los parámetros l y r en la declaración de la función 
/*
	7 42 71 34 17 38 13 49
*/

void insertionSort(int* A, int l, int r){
	int i, j, key;
    for(i = l+1; i <= r; i++){
		key = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > key){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}   
}

// Realiza la particion de A[l..r] retornando la posición p del pivote,
// dejando A tal que: A[l..p-1] <= A[p] < A[p+1...r]
int partition(int *A, int l, int r){
	int p, pv, i;
	p = l;
	pv = A[p];
	for(i = l+1; i<=r; i++){
		if (A[i] <= pv){
			p++;
			swap(A[i], A[p]);
		}
	}
	swap(A[l], A[p]);
	return p;
}

// 2.5 Puntos
// ordena ascendentemente los elementos de A[l..r] con su algoritmo híbrido y recursivo quickInsert
void quickInsert(int *A, int l, int r, int umbral){
	if(l < r){
		int p = partition(A, l, r);
		if((r-l+1)<=umbral) {
			insertionSort(A,l,r);
		} else {
			quickInsert(A, l, p - 1, umbral);
			quickInsert(A, p + 1, r, umbral);
		}
	}
}

// imprime el subarreglo A[l..r]
void listaArray(int* A, int l, int r){
	for (int i=l; i<=r; i++)
		cout << A[i] << " ";
	cout << endl;
}