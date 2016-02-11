// graphm.h
// This graph does Dikjstra's Algorithm for any data files with correct format
// Author: Blong Thao

//-----------------------------------------------------------------------------
// Dikjstra's Algorithm Graph ADT:   Finds the shortest route to a node when
//    there are more than one node that have edges to one another. First, the
//    algorithm chooses its source, usually the first node, and finds the 'v'
//    for that source, which would be the smallest edge value, and uses that
//    to compare with a 'w', which is the current shortest distance to between
//    two nodes. If the source through v to w is shorter than the current
//    source to w, then it'll update the source to w with the source through v
//    to w, that would then be the shortest path and so on, until all nodes
//    have been visited and their shortest paths have been found.
//
// Assumptions:
//    -- The input text file should be formatted correctly i.e.
//           <size>
//           <descriptions>
//           <int> <int> <int>
//    -- Will exit buildGraph when there is a size of zero / empty file and
//           when all three integers are zeros.
//    -- Displays a table showing all data from and to nodes, and their
//           shortest paths
//    -- Edges will only be inserted into the graph if their values are within
//           the value of size
//    -- buildGraph can be called sequentially, replacing each of the previous
//           graphs, and making the last buildGraph call the current graph
//    -- Size should not exceed 100 and descriotions may not exceed 50 character
//    -- Variable INF represents the max integer in climits library. (INT_MAX)

#ifndef GRAPHM_H
#define GRAPHM_H

#include "nodedata.h"
#include <iostream>
#include <climits>
#include <iomanip>
#define MAXNODES 101
#define INF INT_MAX
using namespace std;

class GraphM {

public:
	// default constructor: sets all the data sets in: C and T arrays
	GraphM();

	// fills the graph with data
	void buildGraph(ifstream&);

	// assigns the edge of two Nodes
	void insertEdge(const int, const int, const int);

	 // removes the edge of two Nodes
	void removeEdge(const int, const int);
	
	// uses Diktstras algorithm
	void findShortestPath();

	// shows a table of data: description, from node, to node,
	// Dijkstra's, and the path
	void displayAll();

	// shows path from Node to Node and the descriptions of each
	// of the paths it took to get there
	void display(const int, const int);

private:
	struct TableType {
	bool visited;         // whether node has been visited
	int dist;             // currently known shortest distance from source
	int path;             // previous node in path of min dist
};

	NodeData adjList[MAXNODES];             // data for graph nodes information
	int C[MAXNODES][MAXNODES];              // Cost array, the adjacency matrix 
	int size;                               // number of nodes in the graph
	TableType T[MAXNODES][MAXNODES];        // stores visited, distance, path

	// helper functions
	void makeEmpty();
	void findV(const int, int&);
	void getPath(const int, const int) const;
	void getPathData(const int, const int) const;
};

#endif
