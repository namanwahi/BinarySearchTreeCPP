#include "BST.h"
#include <string>

int main() {
	BST<int> bst;
	bst.insert(4);
	bst.insert(2);
	bst.insert(6);
	bst.insert(3);
	bst.insert(10);
	bst.insert(11);
	bst.insert(1);
	bst.insert(7);
	bst.insert(5);
	bst.printTree(std::cout);
	std::cout << std::endl << std::endl;

	BST<std::string> bst_string("Jane");

	bst_string.insert("Bob");
	bst_string.insert("Alan");
	bst_string.insert("Ellen");

	bst_string.insert("Tom");
	bst_string.insert("Nancy");
	bst_string.insert("Wendy");

	bst_string.printTree(std::cout);

	std::cout << "Should all be true: "
						<< bst_string.contains("Jane") << bst_string.contains("Alan") << bst_string.contains("Ellen")
						<< bst_string.contains("Tom") << bst_string.contains("Nancy") << bst_string.contains("Wendy")
						<< std::endl;

	std::cout << "Should all be false: "
						<< bst_string.contains("Andrew") << bst_string.contains("Beatrice") << bst_string.contains("Henry")
						<< bst_string.contains("Naman") << bst_string.contains("Kevin") << bst_string.contains("William")
						<< std::endl;;
	
  return 0;
}
