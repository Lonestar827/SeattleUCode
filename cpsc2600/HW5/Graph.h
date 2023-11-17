// NAME: Jared Callero
// FILE: Graph.h
// DESCRIPTION: Definition of the Graph class.

#ifndef GRAPH_H
#define GRAPH_H

#include "QueueInt.h"
#include "StackInt.h"

class Graph {

  public:

    // Constructor: load the graph from a file
    Graph(char *fileName);

    // Destructor
    ~Graph();

    // Display the adjacency matrix
    void display() const;

    // Display the depth first search from the given vertex
    void displayDFS(int vertex) const;

    // Display the breadth first search from the given vertex
    void displayBFS(int vertex) const;

    // Compute the cost of a minimum spanning tree.
    int computeMSTCost() const;

  private:
    // TODO: Complete the private section of the class.
    int size;
    int **matrix;
    

    //Helper function for displayDFS that passes in a boolean array of visited
    void displayDFS(int vertex, bool* visited) const;

    //helper function for displayBFS that basses in boolean array of visted and a queue
    void displayBFS(int vertex, bool* visited, QueueInt* queue) const;

    //checks to see if the graph is connected
    bool isConnected() const;

    //helper function for IsConnected that starts at vertex 0 and passes in a bool array
    void isConnected(int vertex, bool *visited) const;

    
};

#endif
