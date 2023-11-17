//Jared Callero
//Homework 3
//10/28/2021

#include "IntSet.h"

#include <iostream>
using namespace std;

#include<string>

IntSet::IntSet()
{
    //default constructor
    intArr = new bitstring[8];

    for(int i = 0; i < 8; i++){

        intArr[i] = 0;

    }

    domain = 8 * 32;
    arrSize = 8;

}

IntSet::IntSet(int maxSize)
{
    //parameter constructor, taking in an int that represents the max number that will be in the set

    domain = maxSize;

    arrSize = maxSize/32+ 1; // Cieling of the max number/32

    //debug Command: print the new maxto make sure
    //cout << maxSize << "/32 + 1 =" << newMax << endl;

    intArr = new bitstring[arrSize];

    for(int i = 0; i < arrSize; i++){

        intArr[i] = 0;

    }
    
}

IntSet::IntSet(IntSet *const &oldSet)
{
    //copy constructor, makes a deep copy of the provided IntSet
    arrSize = oldSet->arrSize;
    intArr = new bitstring[arrSize];
    domain = oldSet->domain;

    for(int i = 0; i < arrSize; i++){

        intArr[i] = oldSet->intArr[i];

    }

}
IntSet::~IntSet()
{
    //Destructor, deletes the array
    delete [] intArr;
}
void IntSet::addElement(int num)
{
    //adds the inputted element to the IntSet

    //edge case, num is outside domain
    if(num <= domain){
        
        //takes num, gets the index with floor of (num - 1)/32
        int index = (num - 1)/32;
        //and the leftshift with (num - 1)%32
        int lShift = (num)%32;
        //then inserts it into int[index] | leftshift
        bitstring newString = makeBitString(lShift);

        //debug: show bitstring
        //cout<< "bitstring created:" << newString << endl;

        intArr[index] = intArr[index] | newString;

    }
    else{

        cout << "Error: " << num << " Is outside the domain of the string" << endl;

    }
}

void IntSet::removeElement(int num)
{
    //remove the inputted element to the IntSet
    //takes num, gets the index with floor of (num - 1)/32
    //and the leftshift with (num - 1)%32
    //then inserts it into int[index] | leftshift
    if(num <= domain){
        
        //takes num, gets the index with floor of (num - 1)/32
        int index = (num - 1)/32;
        //and the leftshift with (num - 1)%32
        int lShift = (num)%32;
        //then inserts it into int[index] | leftshift
        bitstring newString = makeBitString(lShift);

        //debug: show bitstring
        //cout<< "bitstring created:" << newString << endl;

        intArr[index] = intArr[index] & ~newString;

    }
    else{

        cout << "Error: " << num << " Is outside the domain of the string" << endl;

    }
    ///TODO: write remove element
}
bool const IntSet::isElement(int num)
{
    if(num <= domain){
        
        //takes num, gets the index with floor of (num - 1)/32
        int index = (num - 1)/32;
        //and the leftshift with (num - 1)%32
        int lShift = (num)%32;
        //then inserts it into int[index] | leftshift
        bitstring newString = makeBitString(lShift);

        //debug: show bitstring
        //cout<< "bitstring created:" << newString << endl;

        if(((intArr[index]) & newString) != 0){

            return true;

        }
        return false;

    }
    else{

        cout << "Error: " << num << " Is outside the domain of the string" << endl;
        return false;
    }
}
void const IntSet::display()
{
    //gives a real number display of the numbers in the array

    bitstring single; //comparison bitstring
    string result = "Set contains:{"; //result to be printed out
    int input;

    for(int i = 0; i < arrSize; i++){

        single = 1;
        for(int j = 0; j < 32; j++){

            if(((intArr[i]) & single) != 0){

                input = ( (i) * 32)+j;
                result += to_string(input) + ", "; // should be adding index + current space in bitstring

            }
            single = single << 1;

        }
        
    }

    result.pop_back();
    result.pop_back();

    result += "}";

    //print the result
    cout << result << endl;
}

int IntSet::numElements()
{
    bitstring single; //comparison bitstring
    int result = 0; //result to be printed out

    for(int i = 0; i < arrSize; i++){

        single = 1;
        for(int j = 0; j < 32; j++){

            if(((intArr[i]) & single) != 0){

                result++;

            }
            single = single << 1;

        }
    }

    return result;
}
IntSet IntSet::unions(const IntSet &operand) const
{
    //returns the union of two sets
    IntSet result = new IntSet(domain);

    for(int i = 0; i <= arrSize; i++){

        result.intArr[i] = intArr[i] | operand.intArr[i];
        
    }

    return result;

    
}
IntSet IntSet::intersect(const IntSet &operand) const
{
    //returns the intersection of the two sets
    IntSet result = new IntSet(domain);

    for(int i = 0; i <= arrSize; i++){

        result.intArr[i] = intArr[i] & operand.intArr[i];
        
    }

    return result;

}

IntSet IntSet::difference(const IntSet &operand) const
{
    //returns the difference of the two sets
    //difference = a union !b
    return unions(operand.complement());
    
}

IntSet IntSet::complement() const
{
    //returns the complement of the set
    IntSet result = new IntSet(domain);

    for(int i = 0; i < arrSize; i++){

        result.intArr[i] = intArr[i];

    }

    bitstring single = 1;

    for(int j = 0; j < arrSize-1; j++){

        result.intArr[j] = ~result.intArr[j];

    }

    for(int k = 0; k < domain % 32; k++){

        if((intArr[arrSize] & single) != 0){

            result.intArr[arrSize] = result.intArr[arrSize] & ~single;           

        }else{

            result.intArr[arrSize] = result.intArr[arrSize] | single;

        }
        single = single << 1;

    }
        
    

    return result;
    
}

bool IntSet::isEqual(const IntSet &operand) const
{

    for(int i = 0; i < arrSize; i++){

        if(intArr[i] != operand.intArr[i]) return false;

    }
    
    return true;
    
}

bitstring IntSet::makeBitString(int i)
{
    //returns a bitstring with the inputted number
    //assumes the number is below 32 and the -1 has been applied

    bitstring single = 1;
    single = single << i;
    return single;

}