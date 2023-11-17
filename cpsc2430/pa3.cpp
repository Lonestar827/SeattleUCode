//Jared Callero
//PA3
//11/3/2021
#include "gamebst.h"

#include <iostream>
using namespace std;
#include <fstream>
#include<string>

int main(){

    ifstream file;
    file.open("boardgames.csv");
    
    string name, maxPlayers, minTime;

    gamebst ATree = gamebst();

    getline(file,name); 

    //Insert and File Test

    while(getline(file,name,',')){

        getline(file,maxPlayers,',');
        
        getline(file,minTime);
        
        ATree.insert(name,stoi(maxPlayers),stoi(minTime));

    }
    file.close();

    //print test

    ATree.print();

    //Height Test

    cout << "Tree height: " << ATree.getHeight() << endl;

    //printGame test, should be successfull

    cout << "Searching for Monopoly: ";

    ATree.printGame("Monopoly");

    //printGame test, should fail

    cout << "Searching for Carcasone: ";

    ATree.printGame("Carcasone");

    //playtime test

    cout << endl << "Looking for game to play in 60 minutes: "<< endl;

    ATree.printPlayable(60);

    cout << endl;

    //copy constructor test

    gamebst BTree = new gamebst(ATree);

    BTree.insert("Carcasone", 5, 30);

    cout << "ATree: " << endl;

    ATree.print();

    cout << endl <<  "BTree: " << endl;

    BTree.print();

    return 0;
}