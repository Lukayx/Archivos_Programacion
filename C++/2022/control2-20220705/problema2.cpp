#include "BST.h"
#include <vector>
#include <time.h>
#include <random>
using namespace std;
#define M 100

void encuentraHojas(nodoBST *tree, vector<int> &v, int &pre);
void listaEliminando(BST *t, vector<int> &v);

int main(int argc, char **argv) {
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./hojasBST n" << endl;
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));
	int x;
	int n = atoi(argv[1]);
	BST T;
	for (int i = 0; i < n; i++){
		x = rand()%(M+1);
		T.insert(&(T.root),x);
	}
	
	vector<int> v(0);
	int pre = 1;
	
	cout << "t en preorder..." << endl;
	T.printPreorder(T.root);
	cout << "\n\n";

	encuentraHojas(T.root, v, pre);
	listaEliminando(&T,v);
	T.printPreorder(T.root);

	cout << endl << "### Fin Problema2 ###" << endl;
	return EXIT_SUCCESS;
}

void encuentraHojas(nodoBST *tree, vector<int> &v, int &pre){
	if(tree != nullptr){
		if(tree->izq == nullptr && tree->der == nullptr && pre%2!=0){
			v.push_back(tree->clave);
		}
		pre++;
		encuentraHojas(tree->izq,v,pre);
		encuentraHojas(tree->der,v,pre);
	}
}

// imprime el stack en orden reverso, eliminando todos su contenido
void listaEliminando(BST *t, vector<int> &v){
	cout << "Eliminando las claves en v del BST: ";
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " "; 
		t->remove(&t->root,v[i]);
	}
	cout << "\n\n";
}


