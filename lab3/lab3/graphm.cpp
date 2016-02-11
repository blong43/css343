// graphm.cpp
// Function definitions for the GraphM class
// Author: Blong Thao

#include "graphm.h"

//-----------------------------------------------------------------------------
// Default Constructor
// Initailizes all the TableType variables: visited = false, dist = inf,
// path = 0; and size to zero. Meaning this function only creates the graph.

GraphM::GraphM() {
	// initializes all the variables in the graph, since its empty
	makeEmpty();
}

//-----------------------------------------------------------------------------
// makeEmpty
// Resets all variables to their initial values when the graph was empty

void GraphM::makeEmpty() {
	size = 0;
	// sets the nodes to a default value, of which the graph would be empty
	for (int source = 1; source < MAXNODES; source++) {
		// distance is initialize to the max number, 2^31-1
		for (int x = 1; x < MAXNODES; x++) {
			T[source][x].visited = false;
			T[source][x].dist = INF;
			T[source][x].path = 0;
			removeEdge(source, x);
		}
	}
}

//-----------------------------------------------------------------------------
// buildGraph
// Fills the graph with data and also makes sure that the graph is empty before
// filling more data on top of it. The data in the graph is filled with a size,
// descriptions, node 1 and 2, and an edge.

void GraphM::buildGraph(ifstream& infile) {
	// variables that hold the from and to node and their edge
	int fromNode, toNode, edge;

	// empties the current graph, since there could be another graph
	makeEmpty();

	// initializes the size of graph
	infile >> size;
	
	// guards against empty text files
	if (infile.eof())
		return;

	// the description of the location , should not exceed 50 characters
	if (size > 0) {
		string s;
		getline(infile,s);

		// read graph node information,
		for (int i = 1; i <= size; i++)
			adjList[i].setData(infile);

		// goes on infinitely until the infile file hits the break case
		for (;;) {
			// read in the first node and its edge to the second node
			infile >> fromNode >> toNode >> edge;

			// break case: line consisted of a zero
			if (fromNode == 0 && toNode == 0 && edge == 0) return;

			// puts the edge into the adjacency matrix
			insertEdge(fromNode, toNode, edge);
		}
	}
}

//-----------------------------------------------------------------------------
// insertEdge
// To insert the edge, set the location in the cost matrix to the edge value
// with exta checks to ensure that the location is with the graph.

void GraphM::insertEdge(const int fromN, const int toN, const int cost) {
	// fromN and toN cannot zero or negative and not larger than size
	if (fromN > 0 && toN > 0 && cost > 0 && fromN <= size && toN <= size) {
		C[fromN][toN] = cost;
	}
}

//-----------------------------------------------------------------------------
// removeEdge
// To remove the edge, set the location in the cost matrix to infinity
// with checks to make sure the edge is being removed within the cost matrix

void GraphM::removeEdge(const int fromN, const int toN) {
	// cannot remove from the cost matrix any of the parameters exceed the max
	if (fromN < MAXNODES && toN < MAXNODES)
		C[fromN][toN] = INF;
}

//-----------------------------------------------------------------------------
// findShortestPath
// Uses Dijkstra's alogrithm to find the shortest path between two nodes

void GraphM::findShortestPath() {
	if ( size < 1)
		return;
	// v always hold the smallest path, w is the current path
	int v = 0, w = 0;

	// finds the shortest pathway from and to each node
	for (int source = 1; source <= size; source++) 
	{
		// each source to itself is always zero
		T[source][source].dist = 0;
		
		// v always reinitialize to zero after each iteration
		v = 0;

		// if v is -1 stop the loop and start the next iteration
		while (v != -1)
		{
			// finds the shortest current path and give it to v,
			// returns -1 if the shortest path was not found
			findV(source, v);

			// marks the location of the shortest path
			T[source][v].visited = true;
			 
			// shortest path was found, now set the pathways
			if (v != -1) 
			{
				// traverse the T 2D array and updates the shortest paths
				for (w = 1; w <= size; w++)
				{
					// makes checks if there is a shorter path from the v node
					if (!T[source][w].visited && C[v][w] != INF &&
						!(T[source][w].dist < T[source][v].dist + C[v][w]))
					{
						// sets the path to the shortest route
						T[source][w].path = v;
						T[source][w].dist = min(T[source][w].dist,
											(T[source][v].dist + C[v][w]));
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------------------------
// findV
// Finds the smallest value in the current T[source][x] and sets v to x,
// x being the compare variable. If not found, sets v to -1.

void GraphM::findV(const int source, int& v) {
	// v is not yet found, lowest value starts at infinity
	bool foundV = false;
	int lowestVal = INF;
	
	// compares every number in the T array to find v
	for (int compare = 1; compare <= size; compare++)
	{	
		// does not check visited nodes
		if (!T[source][compare].visited)
		{
			// compares the T array to the lowest value
			if (T[source][compare].dist < lowestVal) {
				// replaces with the lower value and v is found
				lowestVal = T[source][compare].dist;
				v = compare;
				foundV = true;
			}
		}
	}
	// v is not found, so make v = -1
	if (!foundV)
		v = -1;
}

//-----------------------------------------------------------------------------
// displayAll
// Shows a table of data: description, from and to node, dijkstra's
// and the path. 

void GraphM::displayAll() {
	if (size > 0) {
		cout << "Description     "
			 << "From node To node Dijkstra's Path\n";

		// prints out all the nodes and the needed data
		for (int row = 1; row <= size; row++) 
		{
			// prints description, which is the source
			cout << adjList[row] << endl;

			// prints out the node number, distance, and paths
			for (int col = 1; col <= size; col++)
			{
				// distance will not print if its zero
				if (T[row][col].dist != 0) {
					// prints the from and to nodes
					cout << setw(20) << row << setw(9) << col;

					// when distance is infinity
					if (T[row][col].dist == INF)	 
						cout << setw(11) << "----" << endl; 

					// print in the correct alignment to the description, etc.
					else {
						cout << setw(9) << T[row][col].dist << setw(10);
						getPath(row, col);
						cout << endl;
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------------------------
// getPath
// Gets the entire path from the node to the node recursively as long as they
// are not equal and the path is not smaller than 1.

void GraphM::getPath(const int fromN, const int toN) const {
	if (fromN != toN && T[fromN][toN].path > 0)
		getPath(fromN, T[fromN][toN].path);
	
	// prints out the pathway
	cout << " " << toN;
}

//-----------------------------------------------------------------------------
// display
// Shows just one path from and to a node and displays the locations
// the path goes through after the data is printed.

void GraphM::display(const int fromN, const int toN) {
	if (size < 1)
		return;
	// from and to nodes cannot be zero or lower, and not bigger than size
	if (fromN > 0 && toN > 0 && fromN <= size && toN <= size)
	{
		// prints the data when distance is not infinity
		if (T[fromN][toN].dist != INF) 
		{
			cout << setw(5) << fromN
				 << setw(7) << toN
				 << setw(10) << T[fromN][toN].dist << setw(10);
			getPath(fromN, toN);
			cout << endl;
			getPathData(fromN, toN);
		}
		// otherwise, prints an error line
		else 
		{
			cout << "There is no path from node " << fromN
				 << " to node " << toN << endl;
		}
	}
	// prints an error line when parameters are invalid
	else 
		cout << "Invalid input, parameter values must be within the size\n"
		     << "and larger than zero\n";
	cout << endl;
}

//-----------------------------------------------------------------------------
// getPathData
// Recursively outputs the descriptions of each location the path goes through.

void GraphM::getPathData(const int fromN, const int toN) const {
	// from and to nodes cannot be equal and path cannot be smaller than one.
	if (fromN != toN && T[fromN][toN].path > 0)
		getPathData(fromN, T[fromN][toN].path);
	
	// prints the descriptions
	cout << adjList[toN] << endl;
}
