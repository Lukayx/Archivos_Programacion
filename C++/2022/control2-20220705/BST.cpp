#include "BST.h"

BST::BST() {
	this->root = NULL;
}

BST::BST(int num) {
	this->root = new nodoBST();
	this->root->clave = num;
	this->root->izq = this->root->der = NULL;
}

void BST::printPreorder(nodoBST *t){
	if (t != nullptr){
		cout << t->clave << " ";
		printPreorder(t->izq);
		printPreorder(t->der);
	}
}

// No acepta claves repetidas
bool BST::insert(nodoBST **root, int num){
	nodoBST *q;
	if (*root == nullptr){
		*root = q = new nodoBST();
		q->clave = num;
		q->izq = q->der = NULL;
		return true;
	}

	q = *root;
	if (num < q->clave)
		return (insert(&(q->izq), num));

	if (num > q->clave)
		return (insert(&(q->der), num));

	return false;
}


// retorna el menor nodo del arbol t (t not NULL)
nodoBST *BST::getLowest(nodoBST *t){
	if (t->izq != nullptr)
		return getLowest(t->izq);
	
	return t;
}

bool BST::remove(nodoBST **t, int num){
	if (*t == nullptr)
		return false;

	nodoBST *p = *t;
	if (p->clave == num){				// se elimina el nodo actual: p
		if (p->izq == nullptr){			// si el izquierdo es NULL subimos el derecho
			*t = p->der;
			delete p;
			return true;
		}
		if(p->der == nullptr){			// si el derecho es NULL subimos el izquierdo
			*t = p->izq;
			delete p;
			return true;
		}

		nodoBST *q = getLowest(p->der);		// encontramos el menor en la rama derecha (p->der != NULL)
		p->clave = q->clave;
		return remove(&(p->der), q->clave);	// eliminamos el menor ya encontrado
	}

	if (num < p->clave)
		return remove(&(p->izq), num);

	return remove(&(p->der), num);
}
