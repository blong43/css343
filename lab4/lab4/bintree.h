//  file bintree.h
//  Will be the BST that holds the product tables
//  Authors: Blong Thao

#pragma once

#include "product.h"

class BinTree {
	friend ostream& operator<<(ostream&, const BinTree&);
	
public:
	// starts root at NULL, empty tree
	BinTree();

	// frees all memory allocations that are Node and Product
	~BinTree();

	// fills the tree with nodes and product objects, if there is a
	// duplicate increment that node instead of making a new node
	bool insert(Product*, const int);

	// has a target, if found assign it to a Product pointer;
	// otherwise, do nothing, and make that pointer NULL
	bool retrieve(const Product&, Product*&) const;

	// empties the tree if it has Nodes and Product objects
	// otherwise, does nothing because tree is empty
	void makeEmpty();

	// checks if the tree is empty, if so, return true, otherwise, false
	bool isEmpty() const;

struct Node {
	Product* data; // a pointer to the Product object
	Node* left;    // a pointer to the left Node object
	Node* right;   // a pointer to the right Node object
};
Node* root;

	// Helper to: operator<<
	// prints data in order
	void inorderHelper(const Node*, ostream&) const;

	// Helper to: Destructor
	// frees all memory allocations recursively
	void destroyTree(Node*&);

};
