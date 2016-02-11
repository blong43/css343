// graphl.h
// This graph does a depth first search for any data files with correct format
// Author: Blong Thao

//-----------------------------------------------------------------------------
// Depth-First Search with a Graph ADT: This ADT uses the depth-first search to 
//    find the ordering of the graph where it starts at the node 1 and traverse
//    the forward edges until the nodes do not contain anymore forward edges.
//    Thus, creating a depth-first spanning forest. As it traverses the nodes,
//    each node number is printed in the order it was traversed. Afterwards,
//    it finds the next node in the forest to traverse the forward edges and 
//    so on until there are no more nodes in the forest to traverse and print.
//
// Assumptions:
//    -- The input text file should be formatted correctly i.e.
//           <size>
//           <descriptions>
//           <int> <int>
//    -- Will exit buildGraph when there is a size of zero,
//           if there are no descriptions and ints are zero. 
//    -- Display shows the node and its description plus its edges
//    -- Depth-first search prints each node it traverses, always
//           traverses the smaller edge and then the next edges
//    -- There shall be the same amount of descriptions as the value of size;
//           cannot have size zero and still have descriptions, etc.
//    -- Edges will only be inserted into the graph if their values are within
//           the value of size, and always inserted at the head.
//    -- buildGraph can be called sequentially, replacing each of the previous
//           graphs, and making the last buildGraph call the current graph
//    -- Size should not exceed 100 and descriptions may not exceed 50 character

#ifndef GRAPHL_H
#define GRAPHL_H

#include "nodedata.h"
#include <iostream>
#define MAXNODES 101
using namespace std;

class GraphL {

public:
	// constructor: makes an empty graph and initializes all the
	// edge heads to null and visited to false within the adjacency list
	GraphL();

	// destructor: frees all memory allocations from building the graph
	~GraphL();

	// takes in a file and builds the graph with the data inside it;
	// when a zero is read then this function stops executing.
	void buildGraph(ifstream&);

	// shows the node and its description and the edges in that adjacency list
	void displayGraph() const;

	// traverses the list and goes through the smaller forward edges, then the
	// next edges, this happens recursively. If a node does not connect, it
	// will traverse it after its done with that iteration until all nodes
	// have been visited and printed
	void depthFirstSearch();

private:
struct EdgeNode;			// forward reference for the compiler
struct GraphNode {			// structs used for simplicity, use classes if desired
	bool visited;			// checks if node was visited or not
	EdgeNode* edgeHead;		// head of the list of edges
	NodeData data;          // contains the descriptions of each location
};
struct EdgeNode {
	int adjGraphNode;		// subscript of the adjacent graph node
	EdgeNode* nextEdge;
};
	// an array of lists, creates the graph
	GraphNode adjList[MAXNODES];
	int size;

	// helper functions
	void dfsHelper(const int);
	void makeEmpty();
	void insertEdge(const int, const int);

};

#endif
