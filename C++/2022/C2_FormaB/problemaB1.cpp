#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#define M 10

struct valores {
	int val1;	// un entero aleatorio en el intervalo [-M,M]
	int val2;	// Si val1<0: un entero aleatorio en el intervalo [M,2M].
				// Sino un entero aleatorio en el intervalo [-M,M].
};
typedef struct valores VAL;

void makeMaxHeapVAL(VAL *X, int n);
void makeMaxHeap(int *X, int n);

int main(int argc, char **argv){
	int n, i;
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./problemaB1 n" << endl;
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));
	
	n = atoi(argv[1]);
	
	VAL *arreglo = new VAL[n];
	for(i = 0; i < n; i++){
		arreglo[i].val1 = rand()%(3*M+1);
		if(arreglo[i].val1<0){
			arreglo[i].val2 = M + rand()%(2*M+1);
		} else {
			arreglo[i].val2 = rand()%(M+1) - M;
		}
	}

	makeMaxHeapVAL(arreglo,n);

	cout << "### Fin Problema B1 ###" << endl;
	return EXIT_SUCCESS;
}

void makeMaxHeapVAL(VAL *X, int n){
	int i, j, k;
	VAL x;
	for (i=2; i<=n; i++){
		x = X[i];
		k=i/2;
		j=i;
		while(k && abs(x.val1+ x.val2) > abs(X[k].val1 + X[k].val2)){
			X[j]=X[k];
			j=k;
			k=k/2;
		}
		X[j]=x;
	}
}

// forma un maxheap en el arreglo X[1..n]. ESTO ES EL QUE ESTUDIAMOS EN CLASES Y LE SERVIRA PARA CODIFICAR makeMaxHeapVAL
void makeMaxHeap(int *X, int n){
	int x, i, j, k;

	for (i=2; i<=n; i++){
		x = X[i];
		k=i/2;
		j=i;
		while(k && x>X[k]){
			X[j]=X[k];
			j=k;
			k=k/2;
		}
		X[j]=x;
	}
}
