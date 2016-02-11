// graphl.cpp
// Function definitions for the GraphL class
// Author: Blong Thao

#include "graphl.h"

//-----------------------------------------------------------------------------
// Default Constructor
// Creates the Graph object and initializes the edgeHead and visited variables

GraphL::GraphL() {
	size = 0;
	for (int i = 1; i < MAXNODES; i++) {
		adjList[i].edgeHead = NULL;
		adjList[i].visited = false;
	}
}

//-----------------------------------------------------------------------------
// Destructor
// Calls makeEmpty function to free all memory allocations

GraphL::~GraphL() {
	makeEmpty();
}

//-----------------------------------------------------------------------------
// buildGraph
// Fills the graph with nodes from the text file of data, stops reading the
// file if the size, fromNode, and toNode is zero or negative; descriptions
// should always be included to name each location.

void GraphL::buildGraph(ifstream& infile) {
	// variables that hold the from and to node and their edge
	int fromNode, toNode;

	// empties the current graph, since there could be another graph
	makeEmpty();

	// initializes the size of graph
	infile >> size;
	
	// guards against empty text files and invalid sizes
	if (infile.eof() || size < 1)
		return;
	
	// the description of the location
	string s;
	getline(infile,s);

	// read graph node information,
	for (int i = 1; i <= size; i++) {
		adjList[i].data.setData(infile);
	}

	// goes on infinitely until the infile file hits the break case
	for (;;) {
		// read in the first node and its edge to the second node
		infile >> fromNode >> toNode;

		// break case: line consisted of a zero
		if (fromNode == 0 && toNode == 0) return;

		if (fromNode > 0 && toNode > 0 && fromNode <= size && toNode <= size) {
			// puts the edge into the adjacency matrix
			insertEdge(fromNode, toNode);
		}
	}
}

//-----------------------------------------------------------------------------
// insertEdge
// Used to insert the edge into the adjacency list, always inserts in the
// front of the list regardless of the values.

void GraphL::insertEdge(const int fromN, const int toN) {
	// creats a new edge node and plugs in the to node number inside it 
	EdgeNode* ptr = new EdgeNode;
	ptr->adjGraphNode = toN;
	ptr->nextEdge = NULL;

	// connects the new edge node to the adjacency list, always adding to front
	EdgeNode* next = adjList[fromN].edgeHead;
	adjList[fromN].edgeHead = ptr;
	ptr->nextEdge = next;
}

//-----------------------------------------------------------------------------
// displayGraph
// Shows the graph's node and its descriptions and the edges per node

void GraphL::displayGraph() const {
	// must contain at least a node to display
	if (size > 0) {
		cout << "Graph:\n";

		// loop controls which of the graph node it traverses
		for (int i = 1; i <= size; i++) {
			// prints out the node and its description

			cout << "Node " << i << "       " << adjList[i].data << endl; 
		
			// pointer to the current head of the adjacency list
			EdgeNode* current = adjList[i].edgeHead;
		
			// traverse the list and prints out each of its edges
			while (current != NULL) {
				cout << "   edge " << i << " " << current->adjGraphNode << endl;
				current = current->nextEdge;
			}
		}
	}
	cout << endl;
}

//-----------------------------------------------------------------------------
// depthFirstSearch
// Visits every node and prints out the nodes that it first traverses, does not
// revisit nodes if its visited already.

void GraphL::depthFirstSearch() {
	// there has to be nodes to do depth first search 
	if ( size > 0 ) {
		cout << "Depth-first ordering: ";

		// does a depth first search through all the adjacency list
		for (int v = 1; v <= size; v++) {
			// only visits each list in the array once
			if (!adjList[v].visited)
				dfsHelper(v);
		}
	}
	cout << endl;
}

//-----------------------------------------------------------------------------
// dfsHelper
// Visits the adjacent nodes in the graph and prints out the which one was
// first visited, but does not revisit nodes.

void GraphL::dfsHelper(const int v) {
	// node has been visited
	adjList[v].visited = true;
	cout << " " << v;
	
	// the adjacent node to v
	int w = 0;
	EdgeNode* current = adjList[v].edgeHead;

	// only traverses the list if the list contains nodes
	while (current != NULL) {
		w = current->adjGraphNode;
		if (!adjList[w].visited)
			dfsHelper(w);
		current = current->nextEdge;
	}
}

//-----------------------------------------------------------------------------
// makeEmpty
// Frees all memory allocations in the graph, sets the head to NULL and visited
// to false, and the size back to zero. Completely resets the graph.

void GraphL::makeEmpty() {
	// frees memory when there are nodes to delete
	if (size > 0) {
		// traverses the entire graph array up to the size of the graph
		for (int i = 1; i <= size; i++) {
			// the head of the list
			EdgeNode* current = adjList[i].edgeHead;

			// deletes each node in the list
			while (current != NULL) {
				// makes sure to keep connection after deleting current node
				EdgeNode* next = current->nextEdge;
				delete current;
				current = next;
			}
			adjList[i].edgeHead = NULL;
			adjList[i].visited = false;
		}
		size = 0;
	}
}
