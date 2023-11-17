//Callero Jared
//PA2: Shopping List
//10/25/2021

//Description: Header File for the ShoppingList Class.
//Keeps a shopping list using a dynamic array.

#include <string>
#include "ShoppingList.h"
#include <iostream>
using namespace std;

ShoppingList::ShoppingList()
{
	//default constructor
	size = 0;
	arr = new string[4];
	maxSize = 4;
}

ShoppingList::ShoppingList(string newItem)
{
	//parameterized constructor, taking in the item as a string
	arr = new string[4];
	size = 1;
	maxSize = 4;

	this->insert(newItem, 0);
}

ShoppingList::ShoppingList(const ShoppingList *oldList)
{
	//copy constructor
	size = oldList->size;
	arr = new string[oldList->size];
	maxSize = oldList->maxSize;

	for (int i = 0; i < size; i++)
	{

		this->insert(oldList->arr[i], i);
	}
}

ShoppingList::~ShoppingList()
{
	//destructor
	delete[] arr;
}

void ShoppingList::insert(string s, int index)
{
	//inserts the new string s at the index (Will call helper command)

	//if index is larger then size:
	if (index > size)
	{

		//print warning and put item at end of list.
		cout << "WARNING: chosen index exceeds max size, placing at end of array" << endl;
		//if adding one more increases above the max size
		if (size + 1 > maxSize)
		{
			//make new array with double the max size and add insert each element

			maxSize = maxSize * 2; //double the max size
			string *newArr = new string[maxSize];

			for (int i = 0; i < size; i++)
			{

				newArr[i] = arr[i];
			}

			arr = newArr;
		}
		//add element to end of list
		arr[size] = s;
		//increase size by 1
		size++;
	}
	else
	{

		//if adding one more increases above the max size
		if (size + 1 > maxSize)
		{

			maxSize = maxSize * 2; //double the max size
			string *newArr = new string[maxSize];

			for (int i = 0; i < size; i++)
			{

				newArr[i] = arr[i];
			}

			arr = newArr;
		}
	if(size!=0){
		rightShift(&arr, index, size);
	}
	
	arr[index] = s;
	size++;
	}
}


string ShoppingList::remove(int index)
{
	//removes the item at the chosen index and returns the item at that index

	string result = arr[index];
	leftShift(&arr, index);
	size--;
	return result;
}

int ShoppingList::getSize()
{
	//returns the size of the array using the size attribute

	return size;
}
void ShoppingList::printList()
{
	//prints out the list by calling the array inside the function

	printList(&arr, 0);
}

void ShoppingList::printList(string *arr[], int index)
{
	// prints the list using the array

	//base case: if index == size
	if (index + 1 == size)
	{
		//print but dont call
		cout << "arr[" << index << "]: " << (*arr[index]) << endl;
	}
	//reduction case: if index != size
	else
	{

		//print and call
		cout << "arr[" << index << "]: " << (*arr[index]) << endl;

		printList(arr, index+1);
	}
}

int ShoppingList::findItem(string item)
{
	//find the count of how many of the list are in the

	return findItem(&arr, item, 0);
}

int ShoppingList::findItem(string *arr[], string item, int index)
{
	//find the item in the list

	//base case: if index + 1 == size, dont call
	if (index + 1 == size)
	{

		//if the item matches, add 1
		if ((*arr[index]) == item)
		{

			return 1;
		}
		//else return nothing
		else
		{

			return 0;
		}
	}
	//otherwise
	else
	{

		//if the item matches, add 1 and call
		if ((*arr[index]) == item)
		{

			return 1 + findItem(arr, item, index++);
		}
		//else just call the function again
		else
		{

			return findItem(arr, item, index++);
		}
	}
}

void ShoppingList::rightShift(string *shopArr[], int userIndex, int currentIndex)
{
	//shifts every element from the chosen index to the right

	//edge case: size is 0.
	if(currentIndex == 0){

		//do nothing
		return;

	}
	//base case: userIndex + 1 = currentIndex
	else if (userIndex + 1 == currentIndex)
	{

		//Move element but dont call function again
		shopArr[currentIndex] = shopArr[currentIndex-1];
	}
	//reduction case: not at userIndex + 1
	else
	{

		//move element
		shopArr[currentIndex] = shopArr[currentIndex-1];

		//call function
		rightShift(shopArr, userIndex, currentIndex - 1);
	}

}

void ShoppingList::leftShift(string *shopArr[], int index)
{
	//shifts every element from the chosen index to the left
	//base case: Index + 1 = size
	if (index + 1 == size)
	{

		//Move element but dont call function again
		shopArr[index] = shopArr[index + 1];
	}
	//reduction case: not at userIndex + 1
	else
	{

		//move element
		shopArr[index] = shopArr[index + 1];
		//call function
		leftShift(shopArr, index + 1);
	}
}
