#include "BST.h"
using namespace std;

int main(int argc, char **argv) {
/*  1- Crearemos el BST con las siguientes claves y forma:
         50
       /    \
     30     70
    /  \   /  \
  20  40  60   80 
*/

	BST t;	// crea un BST vacío
	int val;

	val = 50;
	if (t.insert(&(t.root), val))
		cout << "clave " <<val<< " insertada" << endl;
	else cout << "clave " <<val<< " No se pudo insertar" << endl;
	val = 30;
	if (t.insert(&(t.root), val))
		cout << "clave " <<val<< " insertada" << endl;
	else cout << "clave " <<val<< " No se pudo insertar" << endl;
	val = 20;
	if (t.insert(&(t.root), val))
		cout << "clave " <<val<< " insertada" << endl;
	else cout << "clave " <<val<< " No se pudo insertar" << endl;
	val = 40;
	if (t.insert(&(t.root), val))
		cout << "clave " <<val<< " insertada" << endl;
	else cout << "clave " <<val<< " No se pudo insertar" << endl;
	val = 70;
	if (t.insert(&(t.root), val))
		cout << "clave " <<val<< " insertada" << endl;
	else cout << "clave " <<val<< " No se pudo insertar" << endl;
	val = 60;
	if (t.insert(&(t.root), val))
		cout << "clave " <<val<< " insertada" << endl;
	else cout << "clave " <<val<< " No se pudo insertar" << endl;
	val = 60;
	if (t.insert(&(t.root), val))
		cout << "clave " <<val<< " insertada" << endl;
	else cout << "clave " <<val<< " No se pudo insertar" << endl;
	val = 80;
	if (t.insert(&(t.root), val))
		cout << "clave " <<val<< " insertada" << endl;
	else cout << "clave " <<val<< " No se pudo insertar" << endl;
	
	cout << "sizeBST = " << t.sizeBST(t.root) << endl;

	
	//cout << "sizeBST = " << t.sizeBST(t.root) << ", highTree = " << t.highTree(t.root) << endl;
	
	// 2- Recorriendo el BST en preorder...
	/* codifique antes los metodos: BST::preorder y BST::printPreorder
	int i=1;
	t.preorder(t.root, &i);		// asignamos (en el campo pos) los preorders
	t.printPreorder(t.root);	// imprimimos las laves en preorder
	
	//t.inorder(t.root, &i);	// asignamos los inorders
	//t.printInorder(t.root);	// imprimimos en inorder	
	cout << endl; 		

	// 3- Buscando en el BST
	// codifique los antes lo métodos: BST::search y BST::searchNR
	cout << endl;
	nodoBST *q;
	for (i=0; i<10; i++){
		int x = (rand()%10)*10;
		q = t.search(t.root, x);
		if (q == nullptr)
			cout << "Clave x = " << x  << " no encontrada en t" << endl;
		else
			cout << "Clave x = " << x  << " encontrada en t con pos = " << q->pos << endl;
		
		// test de ambas búsquedas. Deben de retornan lo mismo...
		//nodoBST *p = t.searchNR(t.root, x);
		//if (q!=p){
		//	cout << endl << "ERROR. p = " << p << " != q = " << q << endl;
		//	exit(-1);
		//}
	}
	
	// Codifique antes: BST::remove(), BST::sizeBST(), BST::highTree() y BST::isABalancedBST()	
	i=40;
	cout << "Eliminando key = " << i << endl;
	if (t.remove(&(t.root), i))
		cout << "Clave " << i << " eliminada !!" << endl;
	else
		cout << "Clave " << i << " no encontrada" << endl;

	q = t.search(t.root, i);
	if (q == nullptr)
		cout << "Clave x = " << i  << " no encontrada en t" << endl;
	else
		cout << "Clave x = " << i  << " encontrada en t con pos = " << q->pos << endl;

	i=65;
	cout << "Eliminando key = " << i << endl;
	if (t.remove(&(t.root), i))
		cout << "Clave " << i << " eliminada !!" << endl;
	else
		cout << "Clave " << i << " no encontrada" << endl;
	i=50;
	cout << "Eliminando key = " << i << endl;
	if (t.remove(&(t.root), i))
		cout << "Clave " << i << " eliminada !!" << endl;
	else
		cout << "Clave " << i << " no encontrada" << endl;
	
	i=1;
	t.preorder(t.root, &i);		// asignamos los preorders
	cout << "printPreorder():" << endl;
	t.printPreorder(t.root);
	cout << endl;
	
	cout << "sizeBST = " << t.sizeBST(t.root) << endl;
	cout << "high Izq = " << t->highTree(t->root->izq) << ", high Der = " << t->highTree(t->root->der) << endl;
	cout << "isABalancedBST = " << t->isABalancedBST(t->root) << endl << endl;
	*/

	cout << endl << "##################" << endl;
}
