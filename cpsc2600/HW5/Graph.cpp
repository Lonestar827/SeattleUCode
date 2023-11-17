// NAME: Jared Callero
// FILE: Graph.cpp
// DESCRIPTION: Implementation of the Graph class.

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "Graph.h"
#include "QueueInt.h"
#include "StackInt.h"

// Constructor: load the graph from a file
Graph::Graph(char *filename)
{

  string sizeInput, firstInput, secondInput, weightInput;
  int first, second, weight;

  //set up file
  ifstream file;
  file.open(filename);

  //first line = number of verticies -1
  //size = verticies - 1

  file >> sizeInput;

  //convert back to int
  size = stoi(sizeInput);

  matrix = new int *[size];

  //set up matrix[vertNumber-1][vertNumber-1]
  for (int i = 0; i < size; ++i)
  {

    matrix[i] = new int[size];

    for (int k = 0; k < size; k++)
    {

      matrix[i][k] = -1;
    }
  }

  //while the next line isnt null:
  while (!file.eof())
  {
    //get first and second vertice and weight number
    file >> firstInput;
    first = stoi(firstInput);

    file >> secondInput;
    second = stoi(secondInput);

    file >> weightInput;
    weight = stoi(weightInput);

    //put it onto the matrix
    matrix[first][second] = weight;
    matrix[second][first] = weight;
  }
}

// Destructor
Graph::~Graph()
{

  for (int i = 0; i < size; ++i)
  {

    delete[] matrix[i];
    matrix[i] = nullptr;
  }
  delete[] matrix;
  matrix = nullptr;
}

// Display the adjacency matrix
void Graph::display() const
{
  for (int i = 0; i < size; i++)
  {

    cout << endl;

    for (int j = 0; j < size; j++)
    {

      if (i == j)
      {

        cout << 0 << " ";
      }
      else if (matrix[i][j] == -1)
      {

        cout << "x ";
      }
      else
      {

        cout << matrix[i][j] << " ";
      }
    }
  }

  cout << endl;
}

// Displays the depth first search starting at the given vertex
void Graph::displayDFS(int vertex) const
{
  //set up visited boolean array
  bool *visited = new bool[size];

  cout << "DFS at vertex " << vertex << ":";

  displayDFS(vertex, visited);

  cout << endl;
}

void Graph::displayDFS(int vertex, bool *visited) const
{

  //add current vertex to visited array
  visited[vertex] = true;

  //print current vertex
  cout << vertex << " ";

  //for each unvisited vertex w that is adjacent to v
  for (int i = 0; i < size; i++)
  {
    if ((matrix[vertex][i] > 0) && !visited[i])
    {
      displayDFS(i, visited);
    }
  }
}

// Perform breadth first search starting at the given vertex
void Graph::displayBFS(int vertex) const
{
  //set up visited boolean array
  bool *visited = new bool[size];

  QueueInt *queue = new QueueInt();

  cout << "BFS at vertex " << vertex << ":";

  displayBFS(vertex, visited, queue);

  cout << endl;
}

void Graph::displayBFS(int vertex, bool *visited, QueueInt *queue) const
{

  //add current vertex to visited
  visited[vertex] = true;

  //print vertex

  cout << vertex << " ";

  //put vertex into queue

  queue->enqueue(vertex);

  while (!queue->isEmpty())
  {

    vertex = queue->dequeue();

    for (int i = 0; i < size; i++)
    {

      if (matrix[vertex][i] > 0 && !visited[i])
      {

        visited[i] = true;
        cout << i << " ";
        queue->enqueue(i);
      }
    }
  }
}

// Compute the cost of a minimum spanning tree.

int Graph::computeMSTCost() const
{

  bool visited [size]; 
  for(int i = 0; i< size; i++){

    visited[i] = false;

  }
  int result = 0;
  int smallest = 0;
  int smallestOutside = 0;
  int smallestInside = 0;

  //check to see if the graph is connected
  if (!isConnected())
  {

    return -1;
  }
  
  visited[0] = true;

  //Find the minimum edge and add it to the result by looking through the entire edgeset
  for (int k = 0; k < size; k++)
  {
    smallest = 100;
    smallestInside= 0;
    smallestOutside = 0;
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        if (visited[i] && !visited[j]){
          if(matrix[i][j] < smallest && matrix[i][j] > 0){

            smallest = matrix[i][j];
            smallestOutside = j;
          }
        }
      }
    }
    if(smallest != 100){
    result += smallest;
    }
    visited[smallestOutside] = true;
  }

  return result;
}

bool Graph::isConnected() const
{
  //set up visited boolean array
  bool *visited = new bool[size];
  int index = 0;
  bool visitedAll = true;

  isConnected(0, visited);

  while (index < size && visitedAll)
  {

    if (!visited[index])
    {

      visitedAll = false;
    }
    index++;
  }

  return visitedAll;
}

void Graph::isConnected(int vertex, bool *visited) const
{

  //add current vertex to visited array
  visited[vertex] = true;

  //for each unvisited vertex w that is adjacent to v
  for (int i = 0; i < size; i++)
  {
    if ((matrix[vertex][i] > 0) && !visited[i])
    {
      isConnected(i, visited);
    }
  }
}