#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 68

struct nodeList {
	int val;
	nodeList* next;
};
typedef struct nodeList nodo;

bool esPrimo(int m);
int computeM(int U, int c);
int search(nodo **T, int m, int val);
int insertInT(nodo **T, int m, int val);
int removeFromT(nodo **T, int m, int val);
void printT(nodo **T, int m);

// creamos una Tabla de Hash largo m y le ingresamos n nodos aleatorios
int main(int argc, char **argv){
	if(argc != 3){
		cout << "Execution Error! call: ./openHashT <n> <c>" << endl;
		exit(EXIT_FAILURE);
	}

	int i, val, val2, n, m, c, j, k;
	n = atoi(argv[1]);
	c = atoi(argv[2]);
	m = computeM(MAX, c);
	
	cout << " m = " << m << endl;exit(0);
	nodo **T = new nodo*[m];		// tabla T de tamaño m
	for (i=0; i<m; i++)
		T[i] = NULL;
	
	// ingresamos n items e imprimimos...
	for (i=0; i<n; i++){
		val = rand()%MAX;
		insertInT(T, m, val);
	}
	printT(T, m);
	
	/*
	// testear busqueda...
	for (i=0; i<10; i++){
		val = rand()%MAX;
		j = search(T, m, val);
		if (j != -1)
			cout << val << " encontrado en T[" << j << "]" << endl;
		else
			cout << " Valor " << val << " no encontrado en T" << endl;
	}

	
	// eliminamos e ingresamos n/2 items aleatorios...
	for (i=0; i<10;){
		val = rand()%MAX;
		k = removeFromT(T, m, val);
		if(k != -1){
			val2 = rand()%MAX;
			cout << "Se elimina " << val << " desde T[" << k << "], y se inserta " << val2 
              << " en T[" << insertInT(T, m, val2) << "]" << endl;
			printT(T, m);
			i++;
		}else
			cout << "nodo con val=" << val << " No existe!" << endl;
	}
	*/
	
	cout << "## Fin del programa ##" << endl;

	return EXIT_SUCCESS;
}

// si lo encuentra retorna la key de donde fue eliminado (el primero que encuentra),
// si no rerorna -1
int removeFromT(nodo **T, int m, int val){
	return -1;

}

// si lo encuentra retorna la key en donde se encuentra,
// si no rerorna -1
int search(nodo **T, int m, int val){
		
	return -1;
}

// inserta un nodo con valor val en la lista correspondiente a su clave (T[key]),
// lo inserta a la cabeza de la lista (por la izq.) y retorna el indice de T en donde se insertó (key)
int insertInT(nodo **T, int m, int val){
	
	return -1;
}

// retorna true si m es primo y false si no lo es
// m = 100
bool esPrimo(int m){
	return false;
}

// Deseamos encontrar el primer primo m tal que U/(m+k) = c. Considere U=MAX
int computeM(int U, int c){
	
	return 0;	
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

