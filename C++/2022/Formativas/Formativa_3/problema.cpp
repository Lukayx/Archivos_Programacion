#include "BST.h"
using namespace std;

#define LEN 12
const int KEY[LEN] = {10,7,3,8,9,17,12,37,27,40,1,28};

/*
Si inserta las claves de KEY[] en orden, debe quedar un BST con la sgte. forma:

                10
             /      \
           7         17
        /   \      /    \
      3      8    12    37
              \        /   \
              9      27    40
*/

int main(int argc, char **argv){
	BST tree;
  int pos = 0;
  for (int i = 0; i < LEN; i++){
    tree.insert(&(tree.root),KEY[i]);
    cout << "Clave " << KEY[i] << " INSERTADA!!" << endl;
  }
  tree.preorder(tree.root, &pos);
  tree.printPreorder(tree.root);
  cout << "\n\n";
  tree.findNodesRightRoot(tree.root->der);
	
	cout << endl << "### Fin Problema ###" << endl;
	return EXIT_SUCCESS;
}