#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 1000

struct nodeList {
	int val;
	nodeList* next;
};
typedef struct nodeList nodo;

int nextPrime(int m);
int keyUnivHash(int a, int b, int p, int m, int val);
int search(nodo **T, int a, int b, int p, int m, int val);
int insertInT(nodo **T, int a, int b, int p, int m, int val);
int removeFromT(nodo **T, int a, int b, int p, int m, int val);
void printT(nodo **T, int m);

int main(int argc, char **argv){
	if(argc != 3){
		cout << "Execution Error! call: ./openHashT <n> <m>" << endl;
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));
	int i, val, val2, n, m, j, k, ro, a, b;
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	
	ro = nextPrime(m);
	a = 1 + rand()%(ro-1);
	b = rand()%ro;
	
	cout << " m = " << m << ", ro = " << ro << endl;
	cout << " a = " << a << ", b = " << b << endl;
	nodo **T = new nodo*[m];		// tabla T de tamaño m
	for (i=0; i<m; i++)
		T[i] = NULL;
	
	// ingresamos n items e imprimimos...
	for (i=0; i<n; i++){
		val = rand()%MAX;
		insertInT(T, a, b, ro, m, val);
	}
	printT(T, m);
	
	/*
	// testear busqueda...
	for (i=0; i<10; i++){
		val = rand()%MAX;
		j = search(T, a, b, ro, m, val);
		if (j != -1)
			cout << val << " encontrado en T[" << j << "]" << endl;
		else
			cout << " Valor " << val << " no encontrado en T" << endl;
	}

	
	// eliminamos e ingresamos n/2 items aleatorios...
	for (i=0; i<10;){
		val = rand()%MAX;
		k = removeFromT(T, a, b, ro, m, val);
		if(k != -1){
			val2 = rand()%MAX;
			cout << "Se elimina " << val << " desde T[" << k << "], y se inserta " << val2 
              << " en T[" << insertInT(T, a, b, ro, m, val2) << "]" << endl;
			printT(T, m);
			i++;
		}else
			cout << "nodo con val=" << val << " No existe!" << endl;
	}
	*/
	cout << "## Fin del programa ##" << endl;

	return EXIT_SUCCESS;
}

int nextPrime(int m){
	return m+1;
}

// retorna la clave del item val
// ((ak + b) mod ρ) mod m
int keyUnivHash(int a, int b, int ro, int m, int val){
	return 0;
}


// Si val esta en en T, retorna la el índice donde se encontro: T[key]. -1 si no esta en T
int search(nodo **T, int a, int b, int ro, int m, int val){

		
	return -1;
}

// inserta un nodo con valor val en la lista correspondiente a su clave
int insertInT(nodo **T, int a, int b, int ro, int m, int val){
	
	return -1;
}

int removeFromT(nodo **T, int a, int b, int ro, int m, int val){
	return -1;

}

void printT(nodo **T, int m){
	int i;
	nodo *p;
	
	cout << "Tabla T... " << endl;
	for(i=0; i<m; i++){
		if (T[i] != nullptr){
			cout << "T[" << i << "]:";
			p = T[i];
			while (p!=nullptr){
				cout << p->val << " ";
				p = p->next;
			}
			cout << endl;
		}
	}
}
