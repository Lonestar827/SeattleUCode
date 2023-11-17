//Jared Callero
//GameHeap.h for pa4

#include<iostream>
using namespace std;

#ifndef GAMEHEAP_H
#define GAMEHEAP_H

struct game{

    string name = "";
    int maxPlayers = 0;
    int playtime = 0;

};

class GameHeap{

    private:
        //dynamic array keeping a list of games
        game* gameList;
        int size;
        int maxSize;

    public:

        GameHeap();//default constructor

        GameHeap(const GameHeap* oldHeap);//copy constructor

        //copy assignment

        ~GameHeap();//destructor

        void insert(string newTitle, int newPlayers, int newTime);//insert()

        string deleteMax();//deleteMax

        void percolateDown(int hole);

        void printGame(string gameName);//printGame

        void print();//print

        int getSize();

};

#endif //GAMEHEAP_H