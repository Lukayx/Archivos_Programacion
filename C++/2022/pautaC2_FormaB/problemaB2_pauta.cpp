#include <iostream>
#include <cstdlib>
#include <math.h>
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
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	cout << "n = " << n << ", m" << m << endl;

	ADNSEQ **T = new ADNSEQ*[m];		// tabla T de tamaño m
	for (i=0; i<m; i++)
		T[i] = NULL;

	// generamos n palabras de largo m, invocamos a insert e imprimimos al final...
	char *seq = new char[m];
	i=0;
	for(i=0;i<n;i++){
		for(j=0; j<m; j++)
			seq[j] = DNA[rand()%N_SEQ];
		insertInT(T, m, seq);
	}
	printT(T, m);

	cout << "Fin Problema B2" << endl;

	return EXIT_SUCCESS;
}

// cuenta cuantos motif encuentra en s[0..m-1]
int lookingForMotif(char *s, int m){
	int i,c;

	for(c=i=0; i<m-1; i++)
		if((s[i]==MOTIF[0] && s[i+1]==MOTIF[1]) || (s[i+1]==MOTIF[0] && s[i]==MOTIF[1]))
			c++;

	return c;
}

// Inserta s y retorna su clave en T
int insertInT(ADNSEQ **T, int m, char *s){
	int key = lookingForMotif(s,m);

	ADNSEQ *nuevo = new ADNSEQ;
	nuevo->seq = new char[m];
	for(int i=0; i<m; i++)
		nuevo->seq[i] = s[i];
	nuevo->next = T[key];
	T[key] = nuevo;

	return key;
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
