//Jared Callero
//Homework 3
//10/28/2021

//IntSet.h
//provides operations for a Integer Set

#include<iostream>
using namespace std;

#ifndef INTSET_H
#define INTSET_H

typedef int bitstring;

class IntSet{

    private:

        bitstring* intArr; //Integer array representing the bit string
        int domain;
        int arrSize;

    public:

        IntSet();
        //default constructor

        IntSet(int maxsize);
        //parameter constructor, taking in an int that represents the max number that will be in the set

        IntSet(IntSet* const &oldSet);
        //copy constructor, makes a deep copy of the provided IntSet

        ~IntSet();
        //Destructor, deletes the array

        void addElement(int num);
        //adds the inputted element to the IntSet
        //takes num, gets the index with floor of (num - 1)/32 
        //and the leftshift with (num - 1)%32
        //then inserts it into int[index] | leftshift

        void removeElement(int num);
        //remove the inputted element to the IntSet
        //takes num, gets the index with floor of (num - 1)/32 
        //and the leftshift with (num - 1)%32
        //then inserts it into int[index] | leftshift

        bool const isElement(int num);
        //returns true if the element is in the IntArray

        void const display();
        //gives a real number display of the numbers in the array

        int numElements();
        //returns the number of elements in the array

        IntSet unions(const IntSet& operand) const;
        //returns the unions of the two sets

        IntSet intersect(const IntSet& operand) const;
        //returns the intersection of the two sets

        IntSet difference(const IntSet& operand) const;
        //returns the difference of the two sets
        //difference = a union !b

        IntSet complement() const;
        //returns the complement of the set

        bool isEqual(const IntSet& operand) const;
        //returns true if the sets match

        bitstring makeBitString(int i);
        //returns a bitstring with the inputted number

};

#endif // INTSET_H