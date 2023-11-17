/*Author: Jared Callero
 *Program: islands.cpp
 */

/*Required Comments:
 *Time efficiency: Inspecting every edge = O(E)
 */

#include <cstring>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class numberGraph
{

    private:
        bool** graph;
        int** visited;
        int rows, columns;

    public:
        numberGraph(bool** newGraph, int newRows, int newColumns){

            rows = newRows;
            columns = newColumns;

            graph = new bool *[rows];

            for (int i = 0; i < rows; i++)
            {
                graph[i] = new bool[columns];
                memset(graph[i], false, columns);
            }
            
            for(int i = 0; i < rows; i++){
                
                for(int j = 0; j < columns; j++){
                    
                    graph[i][j] = newGraph[i][j];
                    
                }
                
            }

            visited = new int *[rows];

            for (int i = 0; i < rows; i++)
            {
                visited[i] = new int[columns];
                memset(visited[i], 0, columns);
            }

        }

        ~numberGraph(){
            
            for(int i = 0; i < rows; i ++){
            
                delete graph[i];
            
            }
        
            delete graph;
            
            for(int i = 0; i < rows; i ++){
            
                delete visited[i];
            
            }
        
            delete visited;
            
        };

        int islandDFS(){

            int result = 0;

            for(int i = 0; i < rows; i++){

                for(int j = 0; j < columns; j++){

                   if((graph[i][j] == 1) && (visited[i][j] == 0)){ 
                        DFSVisit(i, j);
                        result ++;
                   }

                }

            }

            return result;

        }

        void DFSVisit(int x, int y){
            
            //left
            if(x-1 > 0){
                if((graph[x-1][y]) && (visited[x-1][y] == 0)) {
                    visited[x-1][y] = 1;
                    DFSVisit(x-1,y);
                }
            }
            //right
            if(x+1 < columns){
                if((graph[x+1][y]) && (visited[x+1][y] == 0)) {
                    visited[x+1][y] = 1;
                    DFSVisit(x+1,y);
                }
            }
            //up
            if(y-1 > 0){
                if((graph[x][y-1]) && (visited[x][y-1] == 0)){
                    visited[x][y-1] = 1;
                    DFSVisit(x,y-1);
                }
            }
            //down
            if(y+1 < rows){
                if((graph[x][y+1]) && (visited[x][y+1] == 0)) {
                    visited[x][y+1] = 1;
                    DFSVisit(x,y+1);
                }
            }

            visited[x][y] = 2;
        }

        void printGraph(){

            for(int i = 0; i < rows; i++){

                for(int j = 0; j < columns; j++){

                    cout << graph[i][j];

                }

                cout << endl;
            }

        }
};

int main(int argc, char ** argv)
{

    // initialize needed variables

    int columns, rows, loops;
    bool **intGraph;
    char value;
    numberGraph* newGraph;

    // set up test case loop
    cin >> loops;

    for (int currentLoop = 0; currentLoop < loops; currentLoop++)
    {

        // set up graph
        
        cin >> rows >> columns;
        
        intGraph = new bool *[rows];

        for (int i = 0; i < rows; i++)
        {
            intGraph[i] = new bool[columns];
            memset(intGraph[i], false, columns);
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

                if (value == '#')
                {
                    intGraph[i][j] = true;
                }
            }
        }

        newGraph = new numberGraph(intGraph, rows, columns);    

        cout << newGraph->islandDFS() << endl;
        
        
        for(int i = 0; i < rows; i ++){
            
            delete intGraph[i];
            
        }
        
        delete intGraph;
        delete newGraph;
        
    }
}


