#include "BST.h"

BST::BST() {
	this->root = NULL;
}

BST::BST(int num) {
	this->root = new nodoBST();
	this->root->key = num;
	this->root->izq = this->root->der = NULL;
}

BST::~BST() {

}

//============================================
// No acepta claves repetidas
bool BST::insert(nodoBST **t, int num){
	nodoBST *q;
	if (*t == nullptr){
		*t = q = new nodoBST();
		q->key = num;
		q->izq = q->der = NULL;
		return true;
	}

	q = *t;
	if (num < q->key)
		return (insert(&(q->izq), num));

	if (num > q->key)
		return (insert(&(q->der), num));

	return false;
}

// asigna los identificadores en preorder: R - I - D
void BST::preorder(nodoBST *t, int *pos){
	if (t != nullptr){
		t->pos = *pos;
		(*pos)++;
		preorder(t->izq, pos);
		preorder(t->der, pos);
	}
}

void BST::printPreorder(nodoBST *t){
	if (t != nullptr){
		cout << t->key << "(" << t->pos << ") ";
		printPreorder(t->izq);
		printPreorder(t->der);
	}
}


// retorna la suma de las claves del subárbol actual
int BST::sumAllKey(nodoBST *t){
	if(t != nullptr){
		return t->key + sumAllKey(t->izq) + sumAllKey(t->der); 
	}
	return 0;
}

nodoBST BST::encuentraSubArboles(nodoBST *t, int num){
	if(t != nullptr){
		if(sumAllKey(t) == num) return *t;
		nodoBST *p = *encuentraSubArboles(t->der, num);
		if(p!=nullptr) return p;
		p = *encuentraSubArboles(t->izq, num);
		if(p!=nullptr) return p;
	}
	return *t;
}

// Para todo nodo 't' a la derecha del root, si exite subárbol a la izquierda del root cuya suma == t->key, debe imprimir un match 
// Al comienzo, 't' debe ser el hijo derecho del root
void BST::findNodesRightRoot(nodoBST *t){
	if(t != nullptr){
		nodoBST *p = t;
		*t = encuentraSubArboles(root->izq,t->key);
		if(t != nullptr && t->key == p->key) {
			cout << "**Match encontrado: suma = " << p->key << " en el subarbol(key="<<t->key<<",pos="<<t->pos<<") == nodo clave "<<p->key<<endl;
		}
		*t = *p; 
		findNodesRightRoot(t->izq);
		findNodesRightRoot(t->der);
	}
}

