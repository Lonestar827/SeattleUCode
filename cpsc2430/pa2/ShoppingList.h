//Callero Jared
//PA2: Shopping List
//10/25/2021

//Description: Header File for the ShoppingList Class.
//Keeps a shopping list using a dynamic array.

#include <iostream> 
using namespace std;

#include <string>

#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

class ShoppingList
{

public:

	ShoppingList();
	//default constructor

	ShoppingList(string newItem);
	//parameterized constructor, taking in the item as a string

	ShoppingList(const ShoppingList* oldList);
	//copy constructor

	~ShoppingList();
	//destructor

	void insert(string s, int index);
	//inserts the new string s at the index

	string remove(int index);
	//removes the item at the chosen index and returns the item at that index

	int getSize();
	//returns the size of the array using the size attribute

	void printList();
	//prints out the list

	int findItem(string item);
	//find the item in the list

private:

	string* arr = new string[4];
	int size = 0;
	int maxSize = 0;

	void printList(string* arr[], int index);
	//prints out the list (to be called in the public function)

	string remove(string* arr[], int index);
	//removes the item at the index

	int findItem(string* arr[], string item, int index);
	//find the item in the list (to be called in the public function)

	void rightShift(string* shopArr[], int userIndex, int currentIndex);
	//shifts every element from the index one to the right

	void leftShift(string* shopArr[], int index);
	//shifts every element from the index one to the left

};

#endif // COUNTER_H
