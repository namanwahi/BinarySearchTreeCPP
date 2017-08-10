#ifndef BST_H
#define BST_H

#include <memory>
#include <string>
#include <iostream>

//binary search tree class
template <class T>
class BST {
	
private:

	struct treeNode;
	typedef std::unique_ptr<treeNode> pTreeNode;
	
	//nested struct for type for the tree nodes
	struct treeNode {
		T key;
		pTreeNode left;
		pTreeNode right;
		treeNode(T key) : key(key), left(nullptr), right(nullptr) {}
	};

	pTreeNode root;

	//auxiliary method to recursively insert into the BST
	void insertRecursively(pTreeNode&, const T&);

	//auxiliary method to recursively print the tree
	void printTreeRecursively(pTreeNode&, std::ostream&, int depth = 0);

	//auxiliary method to recursively traverse the tree to find an element
	bool contains(pTreeNode&, const T&);

public:
 
	BST();
	BST(const T&);

	//make it unable to copy a BST
	BST(const BST&) = delete;
	BST& operator=(const BST&) = delete;
	~BST() {}
	
	//insert item of type T into the tree if it is not already in the tree
	void insert(const T&);

	//remove item of type T from the tree if it is in the tree
	void remove(const T&);

	//returns true if the tree contains the item of type T
	bool contains(const T&);

	//inserts tree into an output stream for testing
	void printTree(std::ostream&);
	
};

#endif
