#include <iostream>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <time.h>
using namespace std;	// uso del espacio de nombre std

#define N 30		// cantidad de puntos a crear
#define Q 50		// debe crear puntos flotantes en el rango [-Q, Q]
#define REP 30		// Repeticiones

void genPoints(float X[N], float Y[N]);
float euclideanDistance(float X[N], float Y[N], int u, int v);
float manhattanDistance(float X[N], float Y[N], int u, int v);
float porcentajeDiferencia(float X[N], float Y[N]);
void centroide(float X[N], float Y[N]);

int main(){
	srand(time(NULL));
	float *X = new float[N];
	float *Y = new float[N];
	genPoints(X,Y);
	for(unsigned int i=0;i<N;i++) {
		cout << "Punto "<< i+1 <<" (" << X[i] << " , " << Y[i] << ")" << endl;
	}
	cout << "El porcentaje de diferencia es: "<< porcentajeDiferencia(X,Y) << endl;
	return EXIT_SUCCESS;
}

void genPoints(float X[N], float Y[N]){
	for(unsigned int i = 0; i<N; i++){
		X[i] = (Q*-10) + rand()%((Q*20)+1);
		X[i]/=10;
		Y[i] = (Q*-10) + rand()%((Q*20)+1);
		Y[i]/=10;
	}
}

float porcentajeDiferencia(float X[N], float Y[N]){
	float e,m,porDiff=0.0;
	int u,v;
	for(unsigned int i=0;i<REP;i++){
		u = rand()%N;
		do{
			v = rand()%N;
		}while(v==u);
		e = euclideanDistance(X,Y,u,v);
		m = manhattanDistance(X,Y,u,v);
		porDiff +=(m-e)/e;
	}
	return porDiff;
}

float euclideanDistance(float X[N], float Y[N], int u, int v){
	float n = sqrt(pow(X[u]-X[v],2)+pow(Y[u]-Y[v],2)); 
	return n;
}

float manhattanDistance(float X[N], float Y[N], int u, int v){
	float n = abs(X[u]-X[v])+abs(Y[u]-Y[v]);
	return n;
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
