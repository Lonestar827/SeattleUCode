//Callero Jared
//Lab 3
// 10/22/2021

//description: Keeps an ordered list 

//inclusions
#include <iostream>
using namespace std;
#include <string>

//typedef
typedef string Object;

struct BSTNode {

	Object key;
	BSTNode* left = nullptr;
	BSTNode* right = nullptr;

};

//function prototypes:
bool insertNode(BSTNode*& n, Object userInput);
void printTree(BSTNode*& n);
void wordSearch(BSTNode*& n, Object k);
int getTreeSize(BSTNode*& n);
void deleteTree(BSTNode*& n);


int main() {

	BSTNode* root = nullptr;
	int userIndex;
	Object nodeInput;

	//introduce program 
	cout << endl << endl << endl;
	cout << "Welcome to the Lab 3 program by Jared Callero" << endl;

	//ask user for number of elements to add
	cout << "How many keys do you want to add to the BST? :";
	cin >> userIndex;
	cout << endl;

	//for loop for how many elements they want to add.
	for (int i = 0; i < userIndex; i++) {

		cout << "Enter the key you want to insert:";
		cin >> nodeInput;
		cout << endl;
		while (!insertNode(root, nodeInput)) {

			cout << "That key already exists, please insert a new key:";
			cin >> nodeInput;
			cout << endl;

		}

	}

	//print tree one at a time
	printTree(root);

	//ask user for a word return words with the same amount of letters
	cout << "Please enter a word:";
	cin >> nodeInput;
	cout << endl;
	cout << "The words with the same length are:";
	wordSearch(root, nodeInput);

	//return the size of the tree
	cout << "The size of the tree is " << getTreeSize(root) << endl;

	//delete tree
	deleteTree(root);
	cout << "The tree is empty now." << endl;
	delete root;

	//announce end of program
	cout << "Thank you for using this program!" << endl << endl << endl;

	return 0;
}

bool insertNode(BSTNode*& n, Object userInput) {

	//edge case: there is no root

	if (n == nullptr) {

		//set up new root by making a new node and setting the key
		BSTNode* newNode = new BSTNode;
		newNode->key = userInput;
		n = newNode;
		return true;

	}
	//base case: there are no children
	else if (n->right == nullptr && n->left == nullptr) {

		//compare n key to userInput

		//if userInput is less then current key
		if (n->key > userInput) {

			//make a new node with the userInput as key and make it the left
			BSTNode* newNode = new BSTNode;
			newNode->key = userInput;
			n->left = newNode;
			return true;
		}
		//if the userInput is larger then the current key
		else if (n->key < userInput) {

			//make a new node with the userInput as key and make it the right
			BSTNode* newNode = new BSTNode;
			newNode->key = userInput;
			n->right = newNode;
			return true;
		}
		//if the key is equal
		else {

			//return a false flag
			return false;

		}

	}
	//reduction case: there are children	
	else {

		//if userInput is less then current key
		if (n->key > userInput) {

			//Traverse left in tree
			return insertNode(n->left, userInput);
			


		}
		//if the userInput is larger then the current key
		else if (n->key < userInput) {

			//traverse right in tree
			return insertNode(n->right, userInput);

		}
		//if the key is equal
		else {

			//return a false flag
			return false;

		}

	}

}

void printTree(BSTNode*& n) {

	//prints the tree using preorder traversal
	if (n->left != nullptr) {
		printTree(n->left);
	}
	if (n != nullptr) {
		cout << n->key << endl;
	}
	if (n->right != nullptr) {
		printTree(n->right);
	}

}

void wordSearch(BSTNode*& n, Object k) {
	//searches the tree for words the same length as the user inputted word using preorder traversal

	//check if its a nullptr
	if (n != nullptr) {

		//node
		if (k.size() == n->key.size()) {

			cout << n->key << endl;

		}
		//left
		if (n->left != nullptr) {

			wordSearch(n->left, k);

		}
		//right
		if (n->right != nullptr) {

			wordSearch(n->right, k);

		}
	}
}

int getTreeSize(BSTNode*& n) {
	//gets the tree size using postOrder traversal

	//edge case: n is nullptr
	if (n == nullptr) {

		return 0;

	}
	//base case: n is not a nullptr
	else {

		return getTreeSize(n->left) + getTreeSize(n->right) + 1;

	}

}

void deleteTree(BSTNode*& n) {
	//deletes the node tree using postOrder Traversal

	if (n != nullptr) {

		//left
		if (n->left != nullptr) {

			deleteTree(n->left);
            delete n->left;
		}
		//right
		if (n->right != nullptr) {

			deleteTree(n->right);
            delete n->right;
		}

	}

}
