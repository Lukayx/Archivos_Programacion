#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <random>
#include <algorithm> 	// para que podamos usar el argoritmo de ordenamiento sort()
#include <vector>
#include <time.h>

using namespace std;

#define PRINT 1
#define TEST 1
#define MAX 100
#define INC 3
int REPET = 6;

int busquedaSecuencial(int *v, int x,int n);
int binarySearch(int *v, int x,int n);
void runExperiments(int *v,int n);
void testBusqueda(int *v,int n);

int main(int argc, char **argv){
	srand(time(NULL));
	int i;
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./binarySearch n" << endl;
		exit(EXIT_FAILURE);
	}

	int n = atoi(argv[1]);

	// creamos un vector de largo n, inicializando sus celdas con 0
	int *v = new int[n];
	cout << "Largo del arreglo: : " << n << endl;

	v[0] = rand()%INC;
	for (i=1; i<n; i++)
		v[i] = v[i-1] + rand()%INC;

	if (PRINT){
		cout << "Arreglo original v[] = ";
		for (i=0; i<n; i++)
			cout << v[i] << " ";
		cout << endl;
	}
	if (PRINT){
		cout << "Arreglo ordenado X[] = ";
		for (i=0; i<n; i++)
			cout << v[i] << " ";
		cout << endl;
	}

	if(TEST)
		testBusqueda(v,n); 
	runExperiments(v,n);

	return EXIT_SUCCESS;
}

void runExperiments(int *v,int n){
	int k, nOcc1, nOcc2;
	double avgT1, avgT2;
	clock_t t;

	cout << "_________________________________________________" << endl;
	cout << "  Executing Binary Search on v[] " << endl;

	// creamos numeros aleatorios en el intervalo [0, MAX] y los almacenamos en ALEATORIO
	int *ALEATORIO = new int[REPET];
	for (k=0; k<REPET; k++)
		ALEATORIO[k] = rand()%MAX;

	t = clock();
	for (k=nOcc1=0; k<REPET; k++){
		if (binarySearch(v, ALEATORIO[k],n) > -1)
			nOcc1++;
	}
	t = clock() - t;
	avgT1 = (double)t/CLOCKS_PER_SEC;
	avgT1 = (avgT1*1000000.0)/REPET;
	cout << "Búsqueda binaria..." << endl;
	cout << "Tiempo promedio de CPU: " << avgT1 << " ms" << endl;
	cout << nOcc1 << " ocurrencias en REP = " << k << " búsquedas" << endl;

	t = clock();
	for (k=nOcc2=0; k<int(REPET); k++){
		if (busquedaSecuencial(v, ALEATORIO[k],n) > -1)
			nOcc2++;
	}
	t = clock() - t;
	avgT2 = (double)t/CLOCKS_PER_SEC;
	avgT2 = (avgT2*1000000.0)/REPET;
	cout << "Búsqueda secuencial..." << endl;
	cout << "Tiempo promedio de CPU: " << avgT2 << " ms" << endl;
	cout << nOcc2 << " ocurrencias en REP = " << k << " búsquedas" << endl;
}

// Busque scuencialmente el elemento x en v[]
// Si existe, devuelva la posicion de x en v[], sino devuelva -1
int busquedaSecuencial(int *v, int x, int n){
	for(int i = 0; i < n ; i++)
		if(v[i]==x) return i;
	return -1;
}

// Implemente la búsqueda binaria de x en un vector v[0...n-1].
// Si existe, devuelva la posicion de x en v[], sino devuelva -1
int binarySearch(int *v, int x, int n){
	int l,m,r;
	l=0;
	r=n-1;
	m=r/2;
	while(l<=r){
		if (x==v[m])
			return m;
		else{
			if (x<v[m])
				r=m-1;
			else
				l=m+1;
		}
		m=(l+r)/2;
	}
	return -1;
}

void testBusqueda(int *v, int n){
	int k, x, pos1, pos2;

	cout << "_________________________________________________" << endl;
	cout << "  Executing Test " << endl;

	// creamos numeros aleatorios en el intervalo [0, MAX]
	for (k=0; k<100; k++){
		x = rand()%MAX;
		pos1 = binarySearch(v, x, n);
		pos2 = busquedaSecuencial(v,x,n);
		if (v[pos1] != v[pos2] ){
			cout << "ERROR ! para x=" << x << endl;
			cout << "binarySearch(v, x) = " << pos1 << endl;
			cout << "busquedaSecuencial(v, x) = " << pos2 << endl;
			exit(-1);
		}
	}
	cout << "TEST OX !!" << endl;
}

/*
            1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6
X[1...16] = 7 5 6 9 8 5 3 2 0 8 6 5 4 2 5 1
sort(X)   = 0 1 2 2 3 4 5 5 5 5 6 6 7 8 8 9	buscar x=7
            l             m               r ... m=(l+r)/2
					¿X[m]=5 == x=7?
                            l     m       r
                            5 5 6 6 7 8 8 9
						¿X[m]=6 == x=7?  
                                    7 8 8 9
                                    l m   r
							¿X[m]=8 == x=7?
                                    l
                                    7
                                    r
                                    m
							¿X[m]=7 == x=7?                                     

¿x=7 esta en X y en que posición?
*/

