//Callero Jared
//PA2: Shopping List
//10/25/2021

//Description: Header File for the ShoppingList Class.
//Keeps a shopping list using a dynamic array.

#include "ShoppingList.h"

#include <fstream>

#include<iostream>
using namespace std;

#include<string>

int main() {

    //establish file
    fstream file;
    file.open("/home/fac/hkong/cpsc2430/pa2/items.csv");

	ShoppingList s = ShoppingList();
    //string item;
    //string index;
    //int indexConvert;

	//while(getline(file,item,',')){
        //getline(file,index);
        //indexConvert = stoi(index); 
        //s.insert(item,indexConvert);
    //}
    //file.close();

    s.insert("banana",0);
    s.insert("potasium", 0);
	s.printList();

    return 0;

}