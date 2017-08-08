#include "BST.h"

int main() {
	BST<int> bst;
	bst.printTree(std::cout);
	bst.insert(4);
	bst.insert(2);
	bst.insert(6);
	bst.printTree(std::cout);
	bst.insert(3);
	bst.insert(10);
	bst.insert(11);
	bst.insert(1);
	bst.printTree(std::cout);
  return 0;
}
