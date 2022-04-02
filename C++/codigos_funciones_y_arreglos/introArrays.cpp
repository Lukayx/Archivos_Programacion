#include <iostream> //Biblioteca donde se encuentra la funcion cout
#include <cstdlib>
using namespace std; //uso del espacio de nombre std

// declaración de funciones:
void menorMayorMedia(int *A, int n, int *min, int *max, float *media);
void menorMayorMedia2(int *A, int n, int &min, int &max, float &media);
int repetidos(int *A, int n, int max, int *masRep, int *cantMRep);

#define MAX 21 // no es ni una variable ni una constante, es solo una expresion

int main(){
	int n = 30; // n es una constante
	int A[n];
	int i, min, max, rep, masRep, cantMRep;
	float media;
	
	
	// llenamos el array de enteros aleatorios < MAX
	for (i=0; i<n; i++)
		A[i] = rand()%MAX; // un calor entre 0 y MAX-1


	// listamos el arreglo
	cout << "A[0,"<< n-1 << "] = " << endl; // cout imprime, endl es salto de linea
	for (i=0; i<n; i++)
		cout << " " << A[i];
	cout << endl;
	
	// obtenemos: menor, mayor y media de A
	//menorMayorMedia(A, n, &min, &max, &media);
	menorMayorMedia2(A, n, min, max, media);
	cout << "Menor: " << min << endl;
	cout << "Mayor: " << max << endl;
	cout << "Media: " << media << endl;
	
	// contamos cuantos tienen al menos una repetición y obtenemos el mas repetido
	rep = repetidos(A, n, max, &masRep, &cantMRep);
	cout << "Hay " << rep << " numeros con repeticiones" << endl;
	cout << "El mas repetido es " << masRep << " con " << cantMRep << " repeticiones " << endl;
	
	return 0;
}

void menorMayorMedia2(int A[], int n, int &min, int &max, float &media){
	float suma=0.0;
	
	min = max = A[0];
	for(int i=0; i<n; i++){
		suma = suma + A[i];
		if (A[i] < min)
			min = A[i];
		if (A[i] > max)
			max = A[i];
	}
	media = suma/n;
}

// Encuentra menor,mayor obtiene el promedio de A[] en un solo recorrido del arreglo
void menorMayorMedia(int *A, int n, int *min, int *max, float *media){
	float suma=0.0;
	
	*min = *max = A[0];
	for(int i=0; i<n; i++){
		suma = suma + A[i];
		if (A[i] < *min)
			*min = A[i];
		if (A[i] > *max)
			*max = A[i];
	}
	*media = suma/n;
}

// TAREA
int repetidos(int *A, int n, int max, int *masRep, int *cantMRep){
	int i,rep=0,Cont[MAX];

	*masRep = A[0];
	*cantMRep = 0;

	for(i=0; i<MAX; Cont[i]=0, i++);

	for(i=1, Cont[A[0]]=0; i<n; i++){
		(Cont[A[i]])++; // contador{0,1,2,3,4,5} A(0) sería el indice
		if(Cont[A[i]]>1){// si el numero se repitio mas de una vez entonces se sumara +1
			rep++;
			if(Cont[A[i]] > *cantMRep){
				*cantMRep = Cont[A[i]];
				*masRep = A[i];
			}
		}
	}
	if(*cantMRep > 0){
		(*cantMRep--);
	}

	cout << "A[0,"<< n-1 << "] = " << endl; // cout imprime, endl es salto de linea
	for (i=0; i<n; i++)
		cout << " " << A[i];
	cout << endl;
	return rep;
}
