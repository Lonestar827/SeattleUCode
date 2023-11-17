//Jared Callero
//PA3
//GameBST.h
//11/1/21

#include <string>

#include <iostream>
using namespace std;

#ifndef GAMEBST_H
#define GAMEBST_H

struct TreeNode{
    //node for every part of the tree

    string key;
    int maxPlayers;
    int playtime;
    TreeNode* left;
    TreeNode* right;

};

class GameBST{

    public:
        GameBST(); //default constructor

        GameBST(const GameBST* oldBST); // copy constructor

        ~GameBST();//destructor

        void insert(string name, int maxPlayers, int minTime);//inserts a game into the tree using the inputted parameters

        bool remove(string name);//removes a game from the tree using the inputted parameter
   
        int getHeight();//returns the height of the tree

        void print(); // prints out the tree using inorder traversal

        void printGame(string name); //finds and prints out all information of the game inputted by user

        void printPlayable(int timeLeft); // finds and prints every game that can be played in the timeLeft using PostOrder traversal

    private:

        TreeNode* head;
        
        void insert(TreeNode*& oldNode, TreeNode* newNode); // helper function for insert

        int getHeight(TreeNode* ptr); //helper function for getHeight

        bool remove(string name, TreeNode* ptr); // helper function for Remove

        void print(TreeNode* ptr); //helper function for print;

        void restructure(TreeNode*& ptr); // restructures the tree after removal

        void printGame(string name, TreeNode* ptr); //helper function for printGame

        void printPlayable(int playTime, TreeNode* ptr); //helper function for printGame

        void repopulate(const TreeNode* oldNode); // copies over node info using postorder traversal

        void depopulate(TreeNode*& ptr); //deletes node information using postorder traversal

};
#endif //GAMEBST_H