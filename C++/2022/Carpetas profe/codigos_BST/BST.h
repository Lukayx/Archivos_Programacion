#include <iostream>
#include <cstdlib>
using namespace std;

struct BinaryNode {
	int key; // es al campo por el cual se identifica, y se busca, un nodo
	int pos; // depende de la forma de recorrer su BST
	BinaryNode* izq;
	BinaryNode* der;
};
typedef struct BinaryNode nodoBST;

class BST {
public:
	nodoBST *root;

	BST();
	BST(int num);
	void eliminarNodos(nodoBST *t);
	virtual ~BST();

	bool insert(nodoBST **t, int num);
	nodoBST *search(nodoBST *t, int num);
	nodoBST *searchNR(nodoBST *t, int num);

	void inorder(nodoBST *t, int *pos);
	void printInorder(nodoBST *t);
	void preorder(nodoBST *t, int *pos);
	void printPreorder(nodoBST *t);
	void postorder(nodoBST *t, int *pos);
	void printPostorder(nodoBST *t);

	nodoBST *getLowest(nodoBST *t);
	nodoBST *getLowestNR(nodoBST *t);
	bool remove(nodoBST **t, int num);

	int sizeBST(nodoBST *t);
	int highTree(nodoBST *t);
	bool isABalancedBST(nodoBST *t);
};
