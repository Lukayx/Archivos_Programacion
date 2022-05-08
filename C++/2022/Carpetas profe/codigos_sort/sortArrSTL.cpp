#include <iostream>
#include <cstdlib>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;

#define MAX_VAL 100
#define PRINT 0

// retorna true si a<b y falso en otro caso
bool myfunction (int a, int b) { 
	return (a<b); 
}

void insertionSort(int *I, int n);

int main(int argc, char **argv){
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./sortSTL n" << endl;
		exit(EXIT_FAILURE);
	}
	int i, n=atoi(argv[1]);
	int *A = new int[n];
	int *DupA = new int[n];
	clock_t begin, end;	// variables mara medir los tiempos de ejecución
	double time_spent;

	// generamos enteros aleatorios
	for(i=0; i<n; i++)
		A[i] = DupA[i] = rand()%MAX_VAL;
	
	// duplicamos A en un vector...
	//vector<int> myvector(A, A+n);

	if (PRINT){
		cout << "Arreglo original A[] = ";
		for (i=0; i<n; i++)
			cout << A[i] << " ";
		cout << endl;
	}

	begin = clock();
	insertionSort(A,n);
	end = clock();

	if (PRINT){
		cout << "Arreglo ordenado A[] = ";
		for (i=0; i<n; i++)
			cout << A[i] << " ";
		cout << endl;
	}

	// calculate time taken by C qsort function
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	// tiempo en milisegundos
	cout << "Tiempo de insertionSort(): " << time_spent*1000.0 << " ms" << endl;

	time_spent = 0.0;
	begin = clock();
	//sort(myvector.begin(), myvector.end(), myfunction); // sort con vector
	sort(DupA, DupA + n, myfunction);		 // sort con arreglos clasicos
	// DupA actua como un puntero a la primera celda, y DupA + n como un puntero a la última celda (REF: http://www.cplusplus.com/reference/algorithm/sort/)
	end = clock();

	if (PRINT){
		cout << "Arreglo ordenado myvector[] = ";
		for (i=0; i<n; i++)
			cout << DupA[i] << " ";
		cout << endl;
	}
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	cout << "Tiempo de sort(): " << time_spent*1000.0 << " ms" << endl;

	return EXIT_SUCCESS;
}

// ordena los elementos de A con el algoritmo de la bubrbuja
void insertionSort(int* A, int n){

}

