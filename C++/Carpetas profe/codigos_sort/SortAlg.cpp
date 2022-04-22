#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 20

void insertionSort(int *I, int n);
void insertionSortDesc(int* A, int n);
void quickSort(int *A, int l, int r);

int main(int argc, char **argv){
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./sortAlg n" << endl;
		exit(EXIT_FAILURE);
	}

	int n = atoi(argv[1]);
	int *I = new int[n];
	int *D = new int[n]; // <--> int D[100];
	int *Q = new int[n];
	int i;

	cout << "Elementos a Ordenar = " << endl;
	for (i=0; i<n; i++){
		D[i] = I[i] = Q[i] = rand()%MAX;
		cout << I[i] << " ";
	}
	cout << endl;

	insertionSort(I, n);
	cout << "I[] = " << endl;
	for (i=0; i<n; i++){
		cout << I[i] << " ";
	}
	cout << endl;

	/*insertionSortDesc(D, n);
	cout << "D[] = " << endl;
	for (i=0; i<n; i++){
		cout << D[i] << " ";
	}
	cout << endl;
	
	quickSort(Q, 0, n-1);
	cout << "Q[] = " << endl;
	for (i=0; i<n; i++){
		cout << Q[i] << " ";
	}
	cout << endl;*/

	return EXIT_SUCCESS;
}

// ordena ascendentemente los elementos de A con el algoritmo insertionSort
void insertionSort(int* A, int n){
	
}

// ordena descendentemente los elementos de A con el algoritmo insertionSort
void insertionSortDesc(int* A, int n){

}

// realiza la particion de A[l..r] retornando la posision p de la particion,
// dejando A tal que todo elemento en A[l..t-1] <= A[p] < A[t+1...r]
int partition(int *A, int l, int r){

	return 0;
}

// ordena ascendentemente los elementos de A con el algoritmo quickSort
void quickSort(int *A, int l, int r){

}
