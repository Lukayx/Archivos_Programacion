#include <iostream>
#include <cstdlib>
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
		cout << "Error. Debe ejecutarse como ./problema1B n" << endl;
		exit(EXIT_FAILURE);
	}

	n = atoi(argv[1]);
	VAL *X = new VAL[n];
	for (i=0; i<=n; i++){
		X[i].val1 = -1*M + rand()%(2*M+1);
		if (X[i].val1 < 0)
			X[i].val2 = M + rand()%(M+1);
		else
			X[i].val2 = -M + rand()%(2*M+1);
	}

	cout << "Arreglo original A[] = " << endl;
	for (i=1; i<=n; i++)
		cout << "(" << X[i].val1 << "+" << X[i].val2 << "=" <<X[i].val1+X[i].val2 << ") ";
	cout << endl << endl;

	makeMaxHeapVAL(X, n);

	cout << "maxHeap A[] = " << endl;
	for (i=1; i<=n; i++){
		if ((X[i].val1+X[i].val2) > 0)
			cout << "(" << X[i].val1+X[i].val2 << ") ";
		else
			cout << "(" << -1*(X[i].val1+X[i].val2) << ") ";
	}
	cout << endl << endl;

	// TEST PARA EL PROFESOR...
	int x, j, p;
	for (i=n; i>1; i--){
		x = X[i].val1+X[i].val2;
		if (x<0)
			x *= -1;
		j=i/2;
		p = X[j].val1+X[j].val2;
		if (p<0)
			p *= -1;
		if (p < x){
			cout << "Error. No es un MAXHEAP. i=" << i << endl;
			exit(EXIT_FAILURE);
		}
	}

	cout << "### Fin Problema B1 ###" << endl;
	return EXIT_SUCCESS;
}

void makeMaxHeapVAL(VAL *X, int n){
	int i, j, k, valX, valK;
	VAL x;

	for (i=2; i<=n; i++){
		x = X[i];
		valX = X[i].val1+X[i].val2;
		if (valX<0)
			valX *= -1;
		k=i/2;
		valK = X[k].val1+X[k].val2;
		if (valK<0)
			valK *= -1;
		j=i;

		while(k && valX>valK){
			X[j]=X[k];
			j=k;
			k=k/2;
			valK = X[k].val1+X[k].val2;
			if (valK<0)
				valK *= -1;
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
