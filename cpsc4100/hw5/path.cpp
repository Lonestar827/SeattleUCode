/*Author: Jared Callero
 *Program: path.cpp
 */

/*Required Comments:
 *Time efficiency: breath first search of entire graph = O(Length*Width)
 */

#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class pathGraph
{

private:
  int **graph;
  int **visited;
  int **distance;
  int rows, columns;
  pair<int, int> start, end;

public:
  pathGraph(int **newGraph, int newRows, int newColumns, pair<int, int> newStart, pair<int, int> newEnd)
  {

    rows = newRows;
    columns = newColumns;

    graph = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
      graph[i] = new int[columns];
      memset(graph[i], 0, columns);
    }

    for (int i = 0; i < rows; i++)
    {

      for (int j = 0; j < columns; j++)
      {

        graph[i][j] = newGraph[i][j];
      }
    }

    visited = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
      visited[i] = new int[columns];
      memset(visited[i], 0, columns);
    }

    distance = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
      distance[i] = new int[columns];
      memset(distance[i], -1, columns);
    }

    start = newStart;
    end = newEnd;
  }

  ~pathGraph() {
      
      for(int i = 0; i < rows; i ++){
            
                delete graph[i];
            
            }
        
            delete graph;
            
            for(int i = 0; i < rows; i ++){
            
                delete visited[i];
            
            }
        
            delete visited;
            
            for(int i = 0; i < rows; i ++){
            
                delete distance[i];
            
            }
        
            delete distance;
      
  }

  int pathBFS()
  {

    queue<pair<int, int>> pathQueue;
    pair<int, int> currentNode, newNode;

    visited[start.first][start.second] = 1;
    distance[start.first][start.second] = 0;
    pathQueue.push(start);

    while (!pathQueue.empty())
    {

      currentNode = pathQueue.front();
      pathQueue.pop();

      // left
      if (currentNode.first - 1 > 0)
      {
        if ((graph[currentNode.first - 1][currentNode.second] == 1) && (visited[currentNode.first - 1][currentNode.second] == 0))
        {

          visited[currentNode.first - 1][currentNode.second] = 1;

          distance[currentNode.first - 1][currentNode.second] = distance[currentNode.first][currentNode.second] + 1;

          pathQueue.push(make_pair(currentNode.first - 1, currentNode.second));
        }
      }
      // right
      if (currentNode.first + 1 < columns)
      {
        if ((graph[currentNode.first + 1][currentNode.second] == 1) && (visited[currentNode.first + 1][currentNode.second] == 0))
        {

          visited[currentNode.first + 1][currentNode.second] = 1;

          distance[currentNode.first + 1][currentNode.second] = distance[currentNode.first][currentNode.second] + 1;

          pathQueue.push(make_pair(currentNode.first + 1, currentNode.second));
        }
      }
      // up
      if (currentNode.second - 1 > 0)
      {
        if ((graph[currentNode.first][currentNode.second - 1] == 1) && (visited[currentNode.first][currentNode.second - 1] == 0))
        {

          visited[currentNode.first][currentNode.second - 1] = 1;

          distance[currentNode.first][currentNode.second - 1] = distance[currentNode.first][currentNode.second] + 1;

          pathQueue.push(make_pair(currentNode.first, currentNode.second - 1));
        }
      }
      // down
      if (currentNode.second + 1 < rows)
      {
        if ((graph[currentNode.first][currentNode.second + 1] == 1) && (visited[currentNode.first][currentNode.second + 1] == 0))
        {

          visited[currentNode.first][currentNode.second + 1] = 1;

          distance[currentNode.first][currentNode.second + 1] = distance[currentNode.first][currentNode.second] + 1;

          pathQueue.push(make_pair(currentNode.first, currentNode.second + 1));
        }
      }

      visited[currentNode.first][currentNode.second] = 2;
    }

    return distance[end.first][end.second];
  }
};

int main()
{

  // initialize needed variables

  // initialize needed variables

  int columns, rows, loops;
  int **intGraph;
  char value;
  pair<int, int> start, end;

  // set up test case loop
  cin >> loops;

  for (int currentLoop = 0; currentLoop < loops; currentLoop++)
  {

    // set up graph
    cin >> rows >> columns;

    intGraph = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
      intGraph[i] = new int[columns];
      memset(intGraph[i], 0, columns);
    }
    // if cin is #:
    // Mark on graph as 1
    // add i * columns + j to visited graph
    // otherwise mark 0

    for (int i = 0; i < rows; i++)
    {

      for (int j = 0; j < columns; j++)
      {

        cin >> value;

        if (value == '.')
        {
          intGraph[i][j] = 1;
        }
        if (value == 'S')
        {

          intGraph[i][j] = 1;
          start = make_pair(i, j);
        }
        if (value == 'E')
        {

          intGraph[i][j] = 1;
          end = make_pair(i, j);
        }
      }
    }

    pathGraph newGraph = pathGraph(intGraph, rows, columns, start, end);

    cout << newGraph.pathBFS() << endl;

  }
}


