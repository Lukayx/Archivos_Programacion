#include <iostream>
#include <cstdlib>
using namespace std;

#define M 50

void makeMaxHeap(int *X, int n);
void maxHeapify(int *X, int n);
void makeMinHeap(int *X, int n);
void minHeapify(int *X, int n);
void printArray(int *X , int n);
void heapSort(int *X , int n);

int main(int argc, char **argv){
	int n, i;
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./heaps n" << endl;
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));
	n = atoi(argv[1]);
	int *X = new int[n+1];
	for (i=1; i<=n; i++)
		X[i] = 1 + rand()%M;

	cout << "Arreglo original X[] =" << endl;
	printArray(X, n);
	
	makeMaxHeap(X, n);

	cout << "Ejecutando test maxheap..." << endl;
	for (i=n; i>1; i--){
		if (X[i] > X[i/2]){
			cout << "ERROR. X["<<i<<"]=" << X[i] <<" > X[" << i/2 <<"]=" << X[i/2] << endl;
			exit(1);
		}
	}
	cout << "Test maxheap OK" << endl;

	cout << "heap X[] =" << endl;
	for (i=1; i<=n; i++)
		cout << ""<<i<<"[" << X[i] <<"] " ;
	cout << endl << endl;
	
	/*
	// extraer e imprimir...
	for (i=1; i<=n; i++){
		cout << X[1] << " ";
		X[1] = X[n-i+1];
		maxHeapify(X, n-i);
	}
	cout << endl;
	*/
	

// vamos a utilizar un maxheap en X para iterativamente extraer el mayor (X[1]) y lo vamos a poner al final del heap.
// En cada iteración debemos hacer heapify para dejar el heap en orden. 
// Ejemplo. Sea X el siguiente maxheap
// X = [18,15,9,14,11,2,7,6,12,3],     extraemos X[1]=18 y lo dejamos al final:
// --> [3, 15,9,14,11,2,7,6,12,    18] heapify [15,14,9,12,11,2,7,6,3,      18]
// --> [3, 14,9,12,11,2,7,6,    15,18] heapify [14,12,9,6,11,2,7,3,      15,18]
// --> [3,12,9,6,11,2,7,     14,15,18] heapify [12,11,9,6,3,2,7,       14,15,18]
//     repetir este proceso hasta ordenar todo X
	
	//heapSort(X, n);
	//cout << endl << "X = " << endl;
	//printArray(X, n);
	
	return EXIT_SUCCESS;
}  
	
// cada valor X[i], i=2,3,4....,n, sube hasta su posición correcta
void makeMaxHeap(int *X, int n){
	int i, j, hijo, padre, k;
	for(i = 2; i <= n; i++){
		hijo = X[i];
		k = i/2;
		padre = X[k]; 
		j = i;
		while(k && hijo > padre){
			X[j] = X[k];
			j = k;
			k = k/2;
			padre = X[k];
		}
		X[j] = hijo;
	}
}

// busca y deja key = X[1] en su posicion correcta en X[1..n], bajando desde la raíz
void maxHeapify(int *X, int n){
	int hijo = 2, key = X[1], padre = 1;
	while(i<=n){
		key = X[i];
		if(i*2 <= n && X[hijo*2] < X[hijo*2+1])
			hijo++;
		
		if(key < X[hijo]){
			X[padre] = X[hijo];
			padre = hijo;
			hijo *= 2;
		} else 
			break;
		X[padre] = key;
	}
}


// cada valor X[i], i=2,3,4....,n, sube hasta su posición correcta
void makeMinHeap(int *X, int n){
	int i, j, hijo, padre, k;
	for(i = 2; i <= n; i++){
		hijo = X[i];
		k = i/2;
		padre = X[k]; 
		j = i;
		while(k && hijo < padre){
			X[j] = X[k];
			j = k;
			k = k/2;
			padre = X[k];
		}
		X[j] = hijo;
	}
}

// busca y deja key = X[1] en su posicion correcta en X[1..n], bajando desde la raíz
void minHeapify(int *X, int n){
	int hijo = 2, key = X[1], padre = 1;
	while(i<=n){
		key = X[i];
		if(hijo+1 <= n && X[hijo] > X[hijo+1])
			hijo++;
		if(key > X[hijo]){
			X[padre] = X[hijo];
			padre = hijo;
			hijo *= 2;
		} else 
			break;
		X[padre] = key;
	}
}

// método de ordenamiento ascendente en base a un maxheap
void heapSort(int *X , int n){

}

void printArray(int *X , int n){
	for (int i=1; i<=n; i++)
		cout << X[i] <<" " ;
	cout << endl << endl;
}

