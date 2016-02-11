// bintree.cpp
// Function definitions for the BinTree class
// Author: Blong Thao

#include "bintree.h"

//-----------------------------------------------------------------------------
// Default Constructor
// Creates an empty binary tree

BinTree::BinTree() {
	root = NULL;
}

//-----------------------------------------------------------------------------
// Destructor
// Frees all memory allocations

BinTree::~BinTree() {
	// frees all memory allocation if the tree is not empty
	if (!isEmpty())
		makeEmpty();
	// else tree is empty and nothing needs to happen
	root = NULL;
}

//-----------------------------------------------------------------------------
// makeEmpty
// Uses a recursive helper: destroyTree to traverse through both sides of the
// tree and free the memory allocations for data and node.

void BinTree::makeEmpty() {
	destroyTree(root);
}

void BinTree::destroyTree(Node*& subtree) {
	// free memory allocation when subtree is not NULL
	if (subtree != NULL) {
		// recursively traverse the left and right subtree until it hits NULL
		destroyTree(subtree->left);
		destroyTree(subtree->right);
		
		// free the data and set the pointer to null 
		delete subtree->data;
		subtree->data = NULL;

		// free the subtree node and set the pointer to null
		delete subtree;
		subtree = NULL;
	}
}

//-----------------------------------------------------------------------------
// isEmpty
// Checks to see if the tree is empty. If root is equal to NULL, then return
// true, otherwise, return false.

bool BinTree::isEmpty() const {
	return root == NULL;
}

//-----------------------------------------------------------------------------
// insert
// Fills the tree with data values, does not let duplicates into the tree
// Thanks goes to Zander for this insert, few changes were made to incorporate
// data that were equal. (Iterative Implementation)

bool BinTree::insert(Product* dataptr, const int totalCopies) {
    // create a new node to insert into the tree
	Node* ptr = new Node;
    if (ptr == NULL) return false;
	ptr->data = dataptr;
	ptr->data->setMaxCopy(totalCopies);
    ptr->left = ptr->right = NULL;
    
	// insert at the root of the tree
	if (isEmpty()) {
		root = ptr;
	}
	else {
		Node* current = root;
		bool inserted = false;

		// accounts for duplicates; inserts either right or left of tree
		while (!inserted) {
			// does not get inserted into tree b/c its a duplicate
			if (*ptr->data == *current->data) {
				delete ptr;
				ptr = NULL;
				return false;
			}
			// insert to the left, otherwise move left one
			else if (*ptr->data < *current->data) {
				if (current->left == NULL) {
					current->left = ptr;
					inserted = true;
				}
				else
					current = current->left;
			}
			// insert to the right, otherwise move right one
			else {
				if (current->right == NULL) {
					current->right = ptr;
					inserted = true;
				}
				else
					current = current->right;
			}
		}
	}
    return true;
}

//-----------------------------------------------------------------------------
// retrieve
// Searches for a given target and when it is found then the object parameter
// is assigned to the data at the found location. (Iterative implementation)

bool BinTree::retrieve(const Product& target, Product*& object) const {
	// empty tree, cannot find target
	if (isEmpty()) {
		object = NULL;
		return false;
	}
	else {
		// tree walker, will traverse the tree to find target
		Node* current = root;

		// traverse the tree until target is found or end of tree
		while (current != NULL) {
			// target was found, return true and object gets assigned the value
			if (target == *current->data) {
				object = current->data;
				return true;
			}
			// target is on the left side or not in tree
			else if (target < *current->data) {
				if (current->left != NULL)
					current = current->left;
				else
					break;
			}
			// target is on the right side or not in tree
			else {
				if (current->right != NULL)
					current = current->right;
				else
					break;
			}
		}
		// target was not in tree
		return false;
	}
}

//-----------------------------------------------------------------------------
// operator<<
// Uses a inorderHelper to get the data from the tree and print it out.
// Recursively traverses both sides of the tree and print out 
// the data in order from smallest to greatest, or inorder from 
// the farthest left node to the farthest right node (all of tree).

ostream& operator<<(ostream& output, const BinTree& tree) {
	// assigns all the data in the tree to the output, inorder
	tree.inorderHelper(tree.root, output);
	output << endl;
	return output;
}

void BinTree::inorderHelper(const Node* subtree, ostream& output) const {
	
	if (subtree == root && subtree != NULL)
		subtree->data->displayHeader();

	// traverse left and right, printing out all the data in order
	if (subtree != NULL) {
		inorderHelper(subtree->left, output);
		output << right << setw(2) << subtree->data->getAmountIn() <<
			setw(4) << subtree->data->getAmountOut() << "   ";
		subtree->data->display();
		inorderHelper(subtree->right, output);
	}
}
