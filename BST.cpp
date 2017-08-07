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
void BST<T>::insertRecursively(pTreeNode node, const T& new_element) {

	//if the node is null then create a new node
	node = pTreeNode(new treeNode(new_element));

	//TODO:finish implementation
}
