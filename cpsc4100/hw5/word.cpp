/*Author: Jared Callero
 *Program: word.cpp
 */

/*Required Comments:
 *Time efficiency: Length*Width of graph + searching for entire word = O(Width*Length)
 */

#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;


class wordGraph
{

    private:
        char** graph;
        int** visited;
        int rows, columns, wordLength;
        string searchWord;

    public:
        wordGraph(char** newGraph, int newRows, int newColumns, string newWord){

            rows = newRows;
            columns = newColumns;
            searchWord = newWord;
            wordLength = searchWord.length();

            graph = new char *[rows];

            for (int i = 0; i < rows; i++)
            {
                graph[i] = new char[columns];
                memset(graph[i], 'A', columns);
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

        ~wordGraph(){};

        void printGraph(){

            for(int i = 0; i < rows; i++){

                for(int j = 0; j < columns; j++){

                    cout << graph[i][j];

                }

                cout << endl;
            }

        }

        bool wordSearch(){
            
            bool result = false;
            
            for(int i = 0; i < rows; i++){
                
                for(int j = 0; j < columns; j++){
                    
                    if(result) break;
                    if(graph[i][j] == searchWord[0]) result = probe(i,j,1);
                    
                }
                
            }
            
            return result;
            
        }
        
        bool probe(int x, int y, int letterPosition){//left
            if(x-1 > 0){
                if((graph[x-1][y] == searchWord[letterPosition])) {
                    if(letterPosition == wordLength) return true;
                    else{
                    visited[x-1][y] = 1;
                    return probe(x-1,y,letterPosition+1);
                    }
                }
            }
            //right
            if(x+1 < columns){
                if((graph[x+1][y] == searchWord[letterPosition])) {
                    if(letterPosition == wordLength) return true;
                    else{visited[x+1][y] = 1;
                    return probe(x+1,y,letterPosition+1);
                    }
                }
            }
            //up
            if(y-1 > 0){
                if((graph[x][y-1] == searchWord[letterPosition])) {
                    if(letterPosition == wordLength) return true;
                    else{
                    visited[x][y-1] = 1;
                    return probe(x,y-1,letterPosition+1);
                    }
                        
                }
            }
            //down
            if(y+1 < rows){
                if((graph[x][y+1] == searchWord[letterPosition])) {
                    if(letterPosition == wordLength) return true;
                    else{
                        visited[x][y+1] = 1;
                        return probe(x,y+1,letterPosition+1);
                    }
                }
            }

            return false;}
        
        

};

int main()
{

    // initialize needed variables

    int columns, rows, loops;
    string searchWord;
    char value;
    char** letters;
    

    // set up test case loop
    cin >> loops;

    for (int currentLoop = 0; currentLoop < loops; currentLoop++)
    {

        // set up graph
        cin >> searchWord >> rows >> columns;

        letters = new char*[rows];
        
        for (int i = 0; i < rows; i++){
            letters[i] = new char[columns];
            memset(letters[i], 'A', columns);
        
        }
        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < columns; j++)
            {

                cin >> value;
                letters[i][j] = value;
            }
        }

        wordGraph newGraph = wordGraph(letters,rows, columns, searchWord);
        if(newGraph.wordSearch())cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
}

