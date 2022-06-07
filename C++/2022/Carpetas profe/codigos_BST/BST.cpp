#include "BST.h"

BST::BST() {
	this->root = NULL;
}

BST::BST(int num) {
	this->root = new nodoBST();
	this->root->key = num;
	this->root->izq = this->root->der = NULL;
}

void BST::eliminarNodos(nodoBST *t){
	if (t != nullptr){
		eliminarNodos(t->izq);
		eliminarNodos(t->der);
		delete t;
	}
}

BST::~BST() {
	eliminarNodos(root);
}
//====================================================

// No acepta claves repetidas
bool BST::insert(nodoBST **t, int num){
	nodoBST *q = *t;

	if(*t == nullptr){
		*t = q = new nodoBST();
		q->izq = q->der = NULL;
		q->key = num;
		return true;
	}
	if (num < q->key)
		return insert(&(q->izq), num);	
	if (num > q->key)
		return insert(&(q->der), num);

	return false; // quiere decir que la clave num ya existe en el BST
}

/*  preorder: ra�z - izq - der
pos = 4, 2, 1, 3, 6, 5, 7
           50:4
         /      \
     30:2        70:6
    /    \      /    \
 20:1   40:3  60:5   80:7
*/

void BST::printPreorder(nodoBST *t){
	if (t!=nullptr){
		cout << "(" << t->key << ":" << t->pos << ") ";
		printPreorder(t->izq);
		printPreorder(t->der);
	}
}

// asigna los identificadores (a pos) en preorder: R - I - D
void BST::preorder(nodoBST *t, int *pos){
	if (t!=nullptr){
		t->pos = *pos;
		(*pos)++;
		preorder(t->izq, pos);
		preorder(t->der, pos);
	}
}

/*  inorder: izq - ra�z - der
pos = 1, 2, 3, 4, 5, 6, 7
          50:4
         /     \
     30:2       70:6
    /   \      /    \
 20:1   40:3  60:5   80:7
*/

// asigna los identificadores en inorder: I - R - D
void BST::inorder(nodoBST *t, int *pos){
	if(t != nullptr){
		inorder(t->izq,pos);
		t->pos = *pos;
		(*pos)++;
		inorder(t->der,pos);
	}
}

void BST::printInorder(nodoBST *t){
	if(t != nullptr){
		printInorder(t->izq);
		cout << "(" << t->key << ":" << t->pos << ") ";
		printInorder(t->der);
	}
}

// busca recursivamente al nodo con clave num y lo devuelve
nodoBST* BST::search(nodoBST *t, int num){
	if(t!=nullptr){
		if(t->key == num) return t;
		if(t->key < num) return search(t->der,num);
		else return search(t->izq,num);
	}
	return NULL;
}

// busca, sin usar recursividad, al nodo con clave num y lo devuelve
// TAREA
nodoBST* BST::searchNR(nodoBST *t, int num){
	nodoBST *p = t;
	while(p!=nullptr && p->key != num){
		if(p->key < num) p = p->der;
		else p = p->izq;
	}
	if(p!=nullptr) return p;
	return NULL;
}

// asigna los identificadores en posorder: I - D - R
void BST::postorder(nodoBST *t, int *pos){ 
	if(t != nullptr){
		postorder(t->izq,pos);
		postorder(t->der,pos);
		t->pos = *pos;
		(*pos)++;
	}
}

void BST::printPostorder(nodoBST *t){
	if(t != nullptr){
		printPostorder(t->izq);
		printPostorder(t->der);
		cout << "(" << t->key << ":" << t->pos << ") ";
	}
}

// retorna el menor nodo del arbol t sin usar recursividad
nodoBST* BST::getLowestNR(nodoBST *t){
	nodoBST *p = t;
	if(p == nullptr) return NULL;
	while(p->izq!=nullptr) p = p->izq;
	return p;
}

// retorna el menor nodo del arbol t (CONDICI�N: t not NULL)
nodoBST *BST::getLowest(nodoBST *t){

	return NULL;
}

bool BST::remove(nodoBST **t, int num){

return false;
}

int BST::sizeBST(nodoBST* t){
return 0;
}

// Retorna la altura: n�mero de arcos desde t a la hoja m�s profunda. 
// Recuerde que la altura de un �rbol vacio es -1
// La altura de un �rbol con un nodo es 0
int BST::highTree(nodoBST *t){
	if(t == nullptr) return -1;
	return 1+max(highTree(t->izq),highTree(t->der));
}

bool BST::isABalancedBST(nodoBST *t){
return true;
}