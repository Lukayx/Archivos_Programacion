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
int REPET = 10;

int busquedaSecuencial(vector<int> &v, int x);
int binarySearch(vector<int> &v, int x);
int recursiveBinarySearch(vector<int> &v, int x, int l, int r);
void runExperiments(vector<int> &v);
void testBusqueda(vector<int> v);

int main(int argc, char **argv){
	int i;
	srand(time(NULL));
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./binarySearch n" << endl;
		exit(EXIT_FAILURE);
	}

	int n = atoi(argv[1]);

	// creamos un vector de largo n, inicializando sus celdas con 0
	vector<int> v(n, 0);
	cout << "v.size(): " << v.size() << endl;

	for (i=0; i<n; i++)
		v[i] = rand()%MAX;

	if (PRINT){
		cout << "Arreglo original v[] = ";
		for (i=0; i<n; i++)
			cout << v[i] << " ";
		cout << endl;
	}

	sort(v.begin(), v.end()); //ordena un vector de menor a mayor

	if (PRINT){
		cout << "Arreglo ordenado X[] = ";
		for (i=0; i<n; i++)
			cout << v[i] << " ";
		cout << endl;
	}

	if(TEST)
		testBusqueda(v); 

	runExperiments(v);

	return EXIT_SUCCESS;
}

void runExperiments(vector<int> &v){
	int k, nOcc1, nOcc2, nOcc3, pos;
	float avgT1, avgT2, avgT3;
	clock_t t;

	cout << "_________________________________________________" << endl;
	cout << "  Executing Binary Search on v[] " << endl;
	// creamos numeros aleatorios en el intervalo [0, MAX] y los almacenamos en ALEATORIO
	int *ALEATORIO = new int[REPET];

	cout << "Buscando numeros: ";
	for (k=0; k<REPET; k++){
		ALEATORIO[k] = rand()%MAX;
		cout << ALEATORIO[k] << " ";
	}
	cout << endl;

	cout << "Búsqueda binaria..." << endl;
	cout << "Posiciones: ";
	t = clock();
	for (k=nOcc1=0; k<REPET; k++){
		pos = binarySearch(v, ALEATORIO[k]);
		if (pos > -1)
			nOcc1++;
		cout << pos << " ";
	}
	t = clock() - t;
	avgT1 = (float)t/CLOCKS_PER_SEC;
	avgT1 = (avgT1*1000000.0)/REPET;
	cout << endl;
	cout << "Tiempo promedio de CPU: " << avgT1 << " μs" << endl;
	cout << nOcc1 << " ocurrencias en REP = " << k << " búsquedas" << endl << endl;

	cout << "Búsqueda secuencial..." << endl;
	cout << "Posiciones: ";
	t = clock();
	for (k=nOcc2=0; k<int(REPET); k++){
		pos = busquedaSecuencial(v, ALEATORIO[k]);
		if (pos > -1)
			nOcc2++;
		cout << pos << " ";
	}
	t = clock() - t;
	avgT2 = (float)t/CLOCKS_PER_SEC;
	avgT2 = (avgT2*1000000.0)/REPET;
	cout << endl;
	cout << "Tiempo promedio de CPU: " << avgT2 << " μs" << endl;
	cout << nOcc2 << " ocurrencias en REP = " << k << " búsquedas" << endl << endl;

	cout << "Búsqueda binaria recursiva..." << endl;
	cout << "Posiciones: ";
	t = clock();
	for (k=nOcc3=0; k<int(REPET); k++){
		pos = recursiveBinarySearch(v, ALEATORIO[k], 0, (int)v.size()-1);
		if (pos > -1)
			nOcc3++;
		cout << pos << " ";
	}
	t = clock() - t;
	avgT3 = (float)t/CLOCKS_PER_SEC;
	avgT3 = (avgT3*1000000.0)/REPET;
	cout << endl;
	cout << "Tiempo promedio de CPU: " << avgT3 << " μs" << endl;
	cout << nOcc3 << " ocurrencias en REP = " << k << " búsquedas" << endl << endl;
}

// Busque scuencialmente el elemento x en v[]
// Si existe, devuelva la posicion de x en v[], sino devuelva -1
int busquedaSecuencial(vector<int> &v, int x){
	int p = 0;
	while(v[p++] != x && p < (int)v.size());
	if(p < (int)v.size()){
		return p-1;
	}
	return -1;
}

// Implemente la búsqueda binaria de x en un vector v[0...n-1].
// Si existe, devuelva la posicion de x en v[], sino devuelva -1
int binarySearch(vector<int> &v, int x){
	int l,m,r;
	l=0;
	r=v.size()-1;
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

int recursiveBinarySearch(vector<int> &v, int x, int l, int r){
	int m = (l+r)/2;
	if(l<=r){
		if(x==v[m])
			return m;
		if(x<v[m])
			return recursiveBinarySearch(v,x,l,m-1);
		return recursiveBinarySearch(v,x,m+1,r);
	}
	return -1;
}

int particion(vector<int> &v, int l, int r){
	for (int i = l+1; i < r; i++){
		if(v[i]<v[l]){
			swap(v[i],v[l]);
			l=i;
		}
	}
	return l;
}

void quickSort(vector<int> &v, int l, int r){
	if(l<=r){
		int m = particion(v,l,r);
		quickSort(v,l,m-1);
		quickSort(v,m+1,r);
	}
}

void testBusqueda(vector<int> v){
	int k, x, pos1, pos2;

	cout << "_________________________________________________" << endl;
	cout << "  Executing Test " << endl;

	// creamos numeros aleatorios en el intervalo [0, MAX]
	for (k=0; k<100; k++){
		x = rand()%MAX;
		pos1 = binarySearch(v, x);
		pos2 = busquedaSecuencial(v,x);
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

