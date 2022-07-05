#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

struct Sequence{
	char *seq; 	//una combinacion de m letras del diccionario DNA
	struct Sequence *next;
};
typedef struct Sequence ADNSEQ;

#define N_SEQ 4
char DNA[] = "ACGT";
char MOTIF[] = "AG"; // "AG" o "GA" es el motif a buscar en cada secuencia para determinar su key en T

int insertInT(ADNSEQ **T, int m, char *st);
void printT(ADNSEQ **T, int m);

int main(int argc, char **argv){
	int i, j;
	if(argc != 3){
		cout << "Error. Debe ejecutarse como ./problemaB2 n m" << endl;
		exit(EXIT_FAILURE);
	}


	cout << "Fin Problema B2" << endl;

	return EXIT_SUCCESS;
}

// Inserta s y retorna su clave en T
int insertInT(ADNSEQ **T, int m, char *s){
	return -1;
}

void printT(ADNSEQ **T, int m){
	int i;
	ADNSEQ *p;

	cout << "Tabla T... " << endl;
	for(i=0; i<m; i++){
		cout << "T[" << i << "]:";
		if (T[i] != nullptr){
			p = T[i];
			while (p!=nullptr){
				cout << p->seq << " ";
				p = p->next;
			}
		}
		cout << endl;
	}
}
