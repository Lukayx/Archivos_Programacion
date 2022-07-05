#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

#define MIN 10
#define MAX 99
#define MINP 1
#define MAXP 5

struct Par{
	int primero;	// aleatorio perteneciente a [MINP..MAXP]
	int segundo;	// aleatorio perteneciente a [MIN..MAX]
};

// crea y devuelve un vector de largo n de tipo <Par> Totalmente aleatorio.
vector<Par> createVector(int n);

void insertionSortDoble(vector<Par> &v);
void imprimeVector(const vector<Par> &v);

int main(int argc, char **argv){	
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./problema n" << endl;
		exit(EXIT_FAILURE);
	}
    srand(time(NULL));
    int n = atoi(argv[1]);
	vector<Par> v = createVector(n);
    imprimeVector(v);
    insertionSortDoble(v);
    imprimeVector(v);

	cout << "### Fin Problema ###" << endl;
	return EXIT_SUCCESS;
}

vector<Par> createVector(int n){
    vector<Par> x(n); 
    for (int i = 0; i < n; i++){
        x[i].primero = MINP + rand()%(MAXP-MINP+1);
        x[i].segundo = MIN + rand()%(MAX-MIN+1);
    }
    return x;
}


void insertionSortDoble(vector<Par> &v){
    int i,j,key;

	for(i=1; i<v.size(); i++){
        key = v[i].primero;
        j = i - 1;
        while(j>=0 && v[j].primero>key){
            swap(v[j+1],v[j]);
            j--;
        }
	}
    int aux = v[0].primero, l=0,r;
    for (i = 1; i < v.size(); i++){
        if(v[l].primero != v[i].primero){
            if(i-l != 1){
                for(int k=l+1; k<i; k++){
                    key = v[k].segundo;
                    j = k - 1;
                    while(j>=l && v[j].segundo>key){
                        swap(v[j+1],v[j]);
                        j--;
                    }
                }
            }
            l=i;
        }
    }
}


void imprimeVector(const vector<Par> &v){
	for (unsigned int i=0; i<v.size(); i++){
			cout << "(" << v[i].primero;
			cout << "," << v[i].segundo << ") ";
	}
	cout << endl;
}


// insertionsort visto en clases: ordena los elementos de A con el algoritmo de la insertionSort
void insertionSort(int* A, int n){
	int i,j,key;

	for(i=1; i<n; i++){
		key = A[i];
		j = i-1;
		while (j>=0 && A[j]>key){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}