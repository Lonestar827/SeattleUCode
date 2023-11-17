//Jared Callero
//GameHeap.cpp for pa4

#include "gameheap.h"

#include <iostream>
using namespace std;

GameHeap::GameHeap()
{
    ///default Constructor
    gameList = new game[4];
    size = 0;
    maxSize = 4;
}

GameHeap::GameHeap(const GameHeap* oldHeap)
{
    ///copy constructor
    gameList = new game[oldHeap->maxSize];

    for (int i = 0; i < oldHeap->size - 1; i++)
    {

        gameList[i].name = oldHeap->gameList[i].name;
        gameList[i].maxPlayers = oldHeap->gameList[i].maxPlayers;
        gameList[i].playtime = oldHeap->gameList[i].playtime;

    }
    size = oldHeap->size;
    maxSize = oldHeap->maxSize;
}

GameHeap::~GameHeap()
{

    delete[] gameList;
}

void GameHeap::insert(string newTitle, int newPlayers, int newTime)
{
    ///insert: inserts a new game based on the user inputted variables

    game newGame;
    newGame.name = newTitle;
    newGame.maxPlayers = newPlayers;
    newGame.playtime = newTime;
    bool needToAdd = true;

    //Look through the array first to see if its in first
    for (int i = 1; i < size; i++)
    {
        //if the names match:
        if (gameList[i].name == newTitle)
        {

            //no need to add
            needToAdd = false;
            cout << "Game already in heap, updating players from " << gameList[i].maxPlayers<< " to " << newPlayers << endl;
            cout << "And playtime from " << gameList[i].playtime << " to " << newTime << endl;
            gameList[i].maxPlayers = newGame.maxPlayers;
            gameList[i].playtime = newGame.playtime;
            

        }
    }

    //if the game wasnt in the heap already.
    if (needToAdd)
    {
        //check the size to see if it exceeds it
        if (size + 1 > maxSize)
        {
            //resize current heap
            cout << "Resizing!" << endl;

            game *newList = new game[maxSize * 2];
            for (int i = 0; i < getSize(); i++)
            {
                newList[i].name = gameList[i].name;
                newList[i].maxPlayers = gameList[i].maxPlayers;
                newList[i].playtime = gameList[i].playtime;
            }
            gameList = newList;
            maxSize = maxSize * 2;
        }

        int hole = size++;

        gameList[0] = newGame;

        while (newGame.name > gameList[hole / 2].name)
        {

            gameList[hole] = gameList[hole / 2];
            hole /= 2;
        }
        gameList[hole] = gameList[0];
    }
}

string GameHeap::deleteMax()
{
    ///deleteMax:deletes the max from the array and percolates up
    string result = gameList[1].name;
    gameList[1] = gameList[size--];
    percolateDown(1);
    return result;
}

void GameHeap::percolateDown(int hole)
{

    int child;
    game tmp = gameList[hole];
    bool bubbleDown = true;
    while (bubbleDown && hole * 2 <= size)
    {

        child = hole * 2;
        if (child != size && gameList[child + 1].name > gameList[child].name)
            ++child;
        if (gameList[child].name > tmp.name)
        {
            //cout << gameList[child].name << " goin up!" << endl;
            gameList[hole] = gameList[child];
        }
        else
            bubbleDown = false;

        if (bubbleDown)
            hole = child;
    }
    gameList[hole] = tmp;
}

void GameHeap::print()
{
    ///print: prints the entire array
    for (int i = 1; i < size; i++)
    {

        //Print out game contents
        cout << "Arr[" << i << "] = " << gameList[i].name <<endl;
        
    }
    
}

void GameHeap::printGame(string gameName)
{
    ///printGame: searches the heap for the game listed by navigating through the array
    bool gameFound = false;
    int index = 1;

    while(!gameFound && index < size){

        if(gameList[index].name == gameName){

            gameFound = true;

        }
        index++;

    }

    //decrement index
    index--;

    if(gameFound){

        cout << "Game found!" << endl;
        cout << "Name: " << gameList[index].name << endl;
        cout << "Maximum players: " << gameList[index].maxPlayers << endl;
        cout << "Playtime: " << gameList[index].playtime << endl;

    }else{

        cout << gameName << " was not found on the heap." << endl;

    }

}

int GameHeap::getSize()
{

    return size;
}