#include <iostream>
#include <string.h>
#include <cstdlib>
#include <math.h>
using namespace std;	// uso del espacio de nombre std

#define N 30		// cantidad de puntos a crear
#define Q 50		// debe crear puntos flotantes en el rango [-Q, Q]
#define REP 30		// Repeticiones

void genPoints(float X[N], float Y[N]);
float euclideanDistance(float X[N], float Y[N], int u, int v);
int manhattanDistance(float X[N], float Y[N], int u, int v);
float porcentajeDiferencia(float X[N], float Y[N]);
void centroide(float X[N], float Y[N]);

int main(){
	float X[N];
	float Y[N];
	genPoints(X,Y);
	for(int i=0;i<N;i++) {
		cout << "Punto (" << X[i] << "," << Y[i] << ")" << endl;
	}

	return EXIT_SUCCESS;
}

void genPoints(float X[N], float Y[N]){
	for(int i = 0; i<REP; i++){
		X[i] = Q - rand()%((Q*2)+1);
		Y[i] = Q - rand()%((Q*2)+1);
		if(X[i] == -50 or Y[i] == -50) cout << "perro";
	}
}


float porcentajeDiferencia(float X[N], float Y[N]){
	return 0;
}

float euclideanDistance(float X[N], float Y[N], int u, int v){
	return 0;
}

int manhattanDistance(float X[N], float Y[N], int u, int v){
	return 0;
}

/*
SI DESEA PROFUNDIZAR, RESUELVA:
===============================

Cree el procedimiento void losMasCercanos(float X[N], float Y[N], int q, int *p_manh, int *p_real)
que encuentra, utilizando la distancia de Manhattan, cuales son los indices p_manh y p_eucl de los 
puntos más cercanos a (X[q],Y[q]), según la distancia euclideana y de manhattan respectivamente.
*/

// calcula e imprime el centroide correspondientes a los N puntos
void centroide(float X[N], float Y[N]){

}
