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
	virtual ~BST();
	
	bool insert(nodoBST **t, int num);
	void preorder(nodoBST *t, int *pos);
	void printPreorder(nodoBST *t);
	
	int sumAllKey(nodoBST *t);
	void findNodesRightRoot(nodoBST *t);
	nodoBST *encuentraSubArboles(nodoBST *t, int num);
};
