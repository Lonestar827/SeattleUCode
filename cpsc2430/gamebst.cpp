//Jared Callero
//GameBST.cpp
//pa3
//11/3/21

//Description
///TODO: make description

//Sources: Lab3.cpp by Jared Callero, Lab3 on canvas.

#include "GameBST.h"

#include <iostream>
using namespace std;


GameBST::GameBST(){ 
    ///default constructor
    head = nullptr;

} 

GameBST::GameBST(const GameBST* oldBST){
    ///copy constructor
    ///TODO:Make Copy Constructor
	head = new TreeNode;
	repopulate(oldBST->head);
} 

GameBST::~GameBST(){
    ///destructor
    ///TODO:Make Destructor, check lab3
	depopulate(head);
	delete head;
	
}

void GameBST::insert(string newName, int newMaxPlayers, int newMinTime){
	///inserts a game into the tree using the inputted parameters (Raw inputs)

	//Make new node
    TreeNode* newNode = new TreeNode;
    newNode->key = newName;
    newNode->maxPlayers = newMaxPlayers;
    newNode->playtime = newMinTime;
    insert(head,newNode);

}


void GameBST::insert(TreeNode*& oldNode, TreeNode* newNode){
    ///inserts a game into the tree using the inputted parameters (Node version)

    //edge case: there is no root

	if (oldNode == nullptr) {

		//set up new root by making a new node and setting the key
		oldNode = newNode;		

	}
	//base case: there are no children
	else if (oldNode->right == nullptr && oldNode->left == nullptr) {

		//compare n key to userInput

		//if userInput is less then current key
		if (oldNode->key > newNode->key) {

			//make a new node with the userInput as key and make it the left
			oldNode->left = newNode;
		}
		//if the userInput is larger then the current key
		else if (oldNode->key < newNode->key) {

			//make a new node with the userInput as key and make it the right
			oldNode->right = newNode;
		}
		//if the key is equal
		else {

			//return a false flag
			cout << "Game already exists, aborting insertion" << endl;

		}

	}
	//reduction case: there are children	
	else {

		//if userInput is less then current key
		if (oldNode->key> newNode->key) {

			//Traverse left in tree
			return insert(oldNode->left, newNode);
			


		}
		//if the userInput is larger then the current key
		else if (oldNode->key < newNode->key) {

			//traverse right in tree
			return insert(oldNode->right, newNode);

		}
		//if the key is equal
		else {

			//return a false flag
			cout << "Game already exists, aborting insertion" << endl;

		}

	}

}

bool GameBST::remove(string name){
    ///removes a game from the tree using the inputted parameter (raw input version)

	TreeNode* ptr = head;
	return remove(name, ptr);

}

bool GameBST::remove(string name, TreeNode* ptr){
	///removes a game from the tree using the inputted parameter (node version)

	//Edge Case: Current node is nullptr
	if(ptr == nullptr){

		//Game does not exist, sending back
		return false;

	}
	//if the name is less then the current key, traverse left
	else if(name < ptr->key){

		return remove(name, ptr->left);

	}
	//if the name is greater then current key, traverse right
	else if(name > ptr->key){

		return remove(name, ptr->right);

	}
	//if it matches
	else{

		//Restructure at the part
		restructure(ptr);

		//return true
		return true;

	}

}

void GameBST::restructure(TreeNode*& ptr){

	//reduction case
	if(ptr->left != nullptr){

		ptr->key = ptr->left->key;
		ptr->maxPlayers = ptr->left->maxPlayers;
		ptr->playtime = ptr->left->playtime;
		restructure(ptr->left);

	}//reduction case: if left is NOT null
	else if(ptr->right != nullptr){

		ptr->key = ptr->right->key;
		ptr->maxPlayers = ptr->right->maxPlayers;
		ptr->playtime = ptr->right->playtime;
		restructure(ptr->right);

	}
	else{

		ptr = nullptr;

	}

}

int GameBST::getHeight(){
	//Gets the height of the tree (Setup function)
    TreeNode* n = head;
    return getHeight(n);

}

int GameBST::getHeight(TreeNode* n){
    ///returns the height of the tree (Recursive function)
    ///TODO: make getHeight(), check lab3
    
    //edge case: n is nullptr
	if (n == nullptr) {

		//return -1 to negate the +1 in the recursive call
		return -1;

	}
	//base case: n is not a nullptr
	else {

		//returns the max of the lft and right
		return max(getHeight(n->left) + 1,getHeight(n->right) + 1);

	}
}

void GameBST::print(){
    ///prints out the tree using inorder traversal (Setup function)
    TreeNode* n = head;
    print(n);
    
} 

void GameBST::print(TreeNode* n){
	///prints out the tree using inorder traversal (Setup function)

	//if theres a node to the left
    if (n->left != nullptr) {
		//traverse left
		print(n->left);
	}
	//node phase
	if (n != nullptr) {
		//print game
		cout << n->key << endl;
	}
	//if theres a node to the right
	if (n->right != nullptr) {
		print(n->right);
	}

}

void GameBST::printGame(string name){
    ///finds and prints out all information of the game inputted by user (setup function)

	TreeNode* ptr = head;
	printGame(name,ptr);

} 

void GameBST::printGame(string name, TreeNode* ptr){
	///finds and prints out all information of the game inputted by user (recursive function)
	
	//base case: node is nullptr
	if(ptr == nullptr){

		cout << "Game is not in tree" << endl;

	}//if the name is less then the key
	else if(name < ptr->key){

		printGame(name,ptr->left);

	}//if the game is more then the key
	else if(name > ptr->key){

		printGame(name,ptr->right);

	}//if the game matches
	else{

		cout << "Game found: " << endl;
		cout << "Game Name: " << ptr->key << endl;
		cout << "Required players: " << ptr->maxPlayers << endl;
		cout << "Required time: " << ptr->playtime << endl << endl;

	}

}

void GameBST::printPlayable(int timeLeft){
    ///finds and prints every game that can be played in the timeLeft using PostOrder traversal
    ///TODO: make printPlayable(), check lab3;
    TreeNode* ptr = head;
	printPlayable(timeLeft, ptr);

}

void GameBST::printPlayable(int timeLeft, TreeNode* ptr){

	//if there is a node to the left
	if(ptr->left != nullptr){

		//traverse left
		printPlayable(timeLeft,ptr->left);

	}

	//if theres a node to the right
	if(ptr->right != nullptr){

		//traverse right
		printPlayable(timeLeft,ptr->right);

	}

	//if the time is equal to or less then the user inputted time
	if(timeLeft <= ptr->playtime){

		//print game
		cout << ptr->key << endl;

	}

}

void GameBST::repopulate(const TreeNode* oldNode){

	//set up variables to insert
	string newKey = oldNode->key;
	int newPlayers = oldNode->maxPlayers;
	int newTime = oldNode->playtime;

	//insert variables
	insert(newKey,newTime,newPlayers);

	//if theres a node to the left
	if(oldNode->left != nullptr){

		//traverse left
		repopulate(oldNode->left);

	}
	//if theres a node to the right
	if(oldNode->right != nullptr){

		//traverse right
		repopulate(oldNode->right);
 
	}

}

void GameBST::depopulate(TreeNode*& ptr){

	//if theres a node to the left
	if(ptr->left != nullptr){

		//traverse left then delete left
		depopulate(ptr->left);
		delete ptr->left;
	}
	//if theres a node to the right
	if(ptr->right != nullptr){

		//traverse right, then delete right
		depopulate(ptr->right);
		delete ptr->right;
	}

}