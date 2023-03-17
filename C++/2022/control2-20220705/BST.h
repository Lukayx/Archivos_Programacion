#include <iostream>
#include <cstdlib>
using namespace std;

struct BinaryNode {
	int clave;
	BinaryNode* izq;
	BinaryNode* der;
};
typedef struct BinaryNode nodoBST;

class BST {
public:
	nodoBST *root;

	BST();
	BST(int num);

	void printPreorder(nodoBST *t);
	bool insert(nodoBST **t, int num);
	
	nodoBST *getLowest(nodoBST *t);
	bool remove(nodoBST **t, int num);
};
