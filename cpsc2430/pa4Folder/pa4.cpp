//Jared Callero
//PA4
//11/19/2021
#include "gameheap.h"

#include <iostream>
using namespace std;
#include <fstream>
#include<string>

int main(){

    ifstream file;
    file.open("boardgames-PA4.csv");
    
    string name, maxPlayers, minTime;

    GameHeap ATree = GameHeap();

    getline(file,name); 

    //Insert and File Test

    while(getline(file,name,',')){

        getline(file,maxPlayers,',');
        
        getline(file,minTime);

        ATree.insert(name,stoi(maxPlayers),stoi(minTime));
    }

    file.close();

    cout<< endl;

    //printGame test, should return true
    cout << "Searching for 'Codenames': "<<endl;
    ATree.printGame("Codenames");
    cout << endl;

    //printGame test, should return false
    cout << "Searching for 'Carcasone': "<<endl;
    ATree.printGame("Carcasone");
    cout << endl;

    //Print Test
    ATree.print();
    cout << endl;

    //insert test, should update Love Letter
    ATree.insert("Love Letter", 30, 50);
    cout << endl;

    //Copy Assignment Test
    GameHeap BTree = new GameHeap(ATree);

    //deleteMax Test
    cout << BTree.deleteMax() << " has been removed from the tree"<< endl;

    //Print Test to make sure it worked with both for comparison
    cout<< "Tree A Contains:" << endl;
    ATree.print();
    cout << endl;

    cout<< "Tree B Contains:" << endl;
    BTree.print();
    cout << endl;

}