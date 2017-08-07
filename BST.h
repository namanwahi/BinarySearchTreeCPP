#ifndef BST_H
#define BST_H

#include <memory>

//binary search tree class
template <class T>
class BST {
	
private:

	struct treeNode;
	typedef std::unique_ptr<treeNode> pTreeNode;
	
	//nested struct for type for the tree nodes
	struct treeNode {
		T data;
		pTreeNode left;
		pTreeNode right;
		treeNode(T data) : data(data), left(nullptr), right(nullptr) {}
	};

	pTreeNode root;
	
	
};

#endif
