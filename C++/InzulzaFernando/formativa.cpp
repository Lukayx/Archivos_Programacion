#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>

using namespace std;

void generaDatos(float *T, int  n);
void clasificaDatos(float *T, float *B, float *M, float *A, int n, int  lim1, int lim2);

// 1 Pt.
int main(int argc, char **argv){	
	srand(time(NULL));
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./formativa n" << endl;
		exit(EXIT_FAILURE);
	}
	int n,lim1,lim2;
	float *T,*B,*M,*A; 
	cout << "Ingrese el largo del array: ";
	cin >> n;
	if(n < 10){ exit(EXIT_FAILURE); }
	do{
		cout << "Ingrese el primer limite: ";
		cin>>lim1;
	}while(lim1 > 40 or lim1 < 0);
	do{
		cout << "Ingrese el segundo limite: ";
		cin >> lim2;		
	}while(lim2 < lim1 or lim2 >= 40);
	T = new float[n];
	B = new float[n];
	M = new float[n];
	A = new float[n];
	generaDatos(T,n);
	clasificaDatos(T,B,M,A,n,lim1,lim2);
	cout << "### Fin Problema ###" << endl;
	return EXIT_SUCCESS;
}

// 2 Pts.
void generaDatos(float *T, int  n){
	for(int i = 0;i<n;i++){
		T[i] = rand()%401;
		T[i] /=10;
	}
	for(int i = 0;i<n;i++){
		cout << T[i] << " ";
	}
	float min = T[0],max=T[0];
	for(int i = 1;i<n;i++){
		if(min > T[i]){min = T[i];}
		if(max < T[i]){max = T[i];}
	}
	cout << "La variacion es: " << abs(min-max) << ", obtenida entre " << min << " y " << max << endl;
}

// 3 Pts.
void clasificaDatos(float *T, float *B, float *M, float *A, int n,  int  lim1, int lim2){
	int b=0,m=0,a=0;
	for(int i=0;i<n;i++){
		if(T[i] >= 0 && T[i] < lim1){
			B[b] = T[i];
			b++;
		} else if (T[i] >= lim1 && T[i] < lim2){
			M[m] = T[i];
			m++;
		} else {
			A[a]=T[i];
			a++;
		
	}
	cout << "temperaturas bajas: " << endl;
	for(int i=0;i<b;i++){
		cout << B[i] << " ";
	}
	cout <<endl;
	cout << "temperaturas medias: " << endl;
	for(int i=0;i<m;i++){
		cout << M[i] << " ";
	}
	cout <<endl;
	cout << "temperaturas altas: " << endl;
	for(int i=0;i<a;i++){
		cout << A[i] << " ";
	}
}


