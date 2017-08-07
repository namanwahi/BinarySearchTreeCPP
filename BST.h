#ifndef BST_H
#define BST_H

#include <memory>
#include <string>

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

public:

	//insert item of type T into the tree if it is not already in the tree
	void insert(const T&);

	//remove item of type T from the tree if it is in the tree
	void remove(const T&);

	//returns true if the tree contains the item of type T
	bool contains(const T&);

	//converts tree into string form for testing
	std::string toString();
};

#endif
