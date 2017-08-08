#include "BST.h"
#include <memory>
#include <string>

template <class T>
BST<T>::BST() : root(nullptr) {}

template <class T>
BST<T>::BST(const T& key) : root(new treeNode(key)) {}

template <class T>
void BST<T>::insert(const T& new_element) {
	insertRecursively(root, new_element);
}

template <class T>
void BST<T>::insertRecursively(pTreeNode& node, const T& new_element) {

	//if the node is null then create a new node
	if (!node) {
		node = pTreeNode(new treeNode(new_element));
		return;
	}

	if (node->key == new_element) {
		//if element is in the tree, do nothing
		return;
	} else if (new_element < node->key) {
		//insert into left subtree
		insertRecursively(node->left, new_element);
	} else { //new_element > node->key
		//insert into right subtree
		insertRecursively(node->right, new_element);
	}
}

template <class T>
void BST<T>::printTree(std::ostream& os) {
	if (!root) {
		os << "<empty>" << std::endl;
		return;
	}
	
	//is tree is not empty
	printTreeRecursively(root, os);
}

template <class T>
void BST<T>::printTreeRecursively(pTreeNode& node, std::ostream& os, int depth) {
	os << node->key  << std::endl;

	depth++;

	
 	if (node->right) {
		for (int i = 0 ; i < depth ; i++)
			os << "\t";

		os << "R:";
		printTreeRecursively(node->right, os, depth);
	}
	
	if (node->left) {
		for (int i = 0 ; i < depth ; i++)
			os << "\t";

		os << "L:";
		printTreeRecursively(node->left, os, depth);
	}

}

//explicit instantiation  of the types that the tree will be used for
template class BST<std::string>;
template class BST<int>;
