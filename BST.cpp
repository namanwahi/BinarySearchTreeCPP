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
	//if the depth is 0 then show it is a root
	if (!depth) {
		os << "ROOT:";
	}
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

template <class T>
bool BST<T>::contains(const T& key) {
	return contains(root, key);
}

template <class T>
bool BST<T>::contains(pTreeNode& node, const T& search_key) {
	//if node is null then the search key is not in the tree
	if (!node){
		return false;
	}

	//if node key is equal to the search key then the tree contains the search key
	if (node->key == search_key) {
		return true;
	} else if (search_key < node->key) {
		//search left subtree
		return contains(node->left, search_key);
	} else { //search_key > node->key
		//insert into right subtree
		return contains(node->right, search_key);
	}
}

template <class T>
void BST<T>::remove(const T& key_to_remove) {
	remove(root, key_to_remove);
}

template <class T>
void BST<T>::remove(pTreeNode& node, const T& key_to_remove) {
	//if node is null do nothing
	if (!node) {
		return;
	}

	//if node key is equal to the search key then remove the node from the tree
	if (node->key == key_to_remove) {
		removeNode(node);
	} else if (key_to_remove < node->key) {
		//search left subtree
		remove(node->left, key_to_remove);
	} else { //key_to_remove > node->key
		//search right subtree
		remove(node->right, key_to_remove);
	}
}

template <class T>
void BST<T>::removeNode(pTreeNode& node) {
	
	if (!(node->left) && !(node->right)) {
		//if this node has no children, simply delete it
		node = nullptr;
	} else if (node->left && !(node->right)) {
		//the node has a left child only
		node = node->left;
		
	} else if (node->left && !(node->right)) {
		//the node has a right child only
		node = node->right;
		
	} else {
		//node has 2 children

		//create replacement node
		pTreeNode replacement(findMinNode(node->right));
		replacement->right = removeMinNode(node->right);
 		replacement->left = node->left;
	  node = replacement;
	}
		
}

template <class T>
typename BST<T>::pTreeNode& BST<T>::findMinNode(pTreeNode& node) {
	if (!(node->left)) {
		return node;
	} else {
		return findMinNode(node->left);
	}
}

template <class T>
typename BST<T>::pTreeNode& BST<T>::removeMinNode(pTreeNode& node) {
	if (!(node->left)) {
		return node->right;
	} else {
		node->left = removeMinNode(node->left);
		return node;
	}
}

template <class T>
void BST<T>::clear() {
	while(root) {
		remove(root->key);
	}
}

//explicit instantiation  of the types that the tree will be used for
template class BST<std::string>;
template class BST<int>;
