//Jared Callero
//Homework 3
//10/28/2021

#include "IntSet.h"

#include<iostream>
using namespace std;

#include<string>

typedef int bitstring;

int main(){

    cout << endl << endl << endl << "Welcome to the Homework 3 program, Written by Jared Callero:" << endl << endl;

    cout<< "Required Tests" << endl << endl;

    //Make set A: Set of even numbers from 1 to 100
    
    cout << "Creating Set A: Even numbers from 0 to 100: " << endl;
    
    IntSet ASet = new IntSet(100);

    for(int i = 2; i <= 100; i = i+2){

        ASet.addElement(i);

    }
    
    ASet.display();

    cout << "the number of elements in this set is " << ASet.numElements()<< endl;
    
    cout << endl;

    //make set B: Set of 5 divisables

    cout << "Creating Set B: numbers divisable by 5 from 0 to 100: " << endl;

    IntSet BSet = new IntSet(100);

    for(int i = 5; i <= 100; i = i+5){

        BSet.addElement(i);

    }
    
    BSet.display();
    
    cout << "the number of elements in this set is " << BSet.numElements()<< endl;

    cout << endl;

    //make set C: Set of 10 divisables

    cout << "Creating Set C: Numbers Divisable by 10 from 0 to 100: " << endl;

    IntSet CSet = new IntSet(100);

    for(int i = 10; i <= 100; i = i+10){

        CSet.addElement(i);

    }
    
    CSet.display();

    cout << "the number of elements in this set is " << CSet.numElements()<< endl;

    cout << endl;

    //make set D: compliment of Set A

    IntSet DSet = ASet.complement();

    cout << "Making Set D: Compliment of A" << endl;

    DSet.display();

    cout << "the number of elements in this set is " << DSet.numElements()<< endl;

    cout << endl;

    //make set E: unions of A and B

    IntSet ESet = ASet.unions(BSet);

    cout << "Making Set E: Union of A and B" << endl;

    ESet.display();

    cout << "the number of elements in this set is " << ESet.numElements()<< endl;

    cout << endl;

    //make set F: Intersect of A and B

    IntSet FSet = ASet.intersect(BSet);

    cout << "Making Set F: Intersect of A and B" << endl;

    FSet.display();

    cout << "the number of elements in this set is " << FSet.numElements()<< endl;

    cout << endl;

    //make set G: Difference of B and A
    
    IntSet GSet = BSet.difference(ASet);

    cout << "Making Set G: difference of B - A" << endl;

    GSet.display();

    cout << "the number of elements in this set is " << GSet.numElements()<< endl;

    cout << endl;

    //make set H: intersect between b and c

    IntSet HSet = BSet.intersect(CSet);

    cout << "Making Set H: Intersect between b and c" << endl;

    HSet.display();

    cout << "the number of elements in this set is " << HSet.numElements()<< endl;

    cout << endl;

    cout << "Is 15 in set A? :";

    if(ASet.isElement(15)){

        cout << "True" << endl;

    }else{

        cout << "False" << endl;

    }

    cout << "Is 26 in set A? :";

    if(ASet.isElement(26)){

        cout << "True" << endl;

    }else{

        cout << "False" << endl;

    }

    cout << "Set B equal to Set G? :";

    if(BSet.isEqual(GSet)){

        cout << "True" << endl;

    }else{

        cout << "False" << endl;

    }

    cout << "Is Set F equal to Set H? :";

    if(FSet.isEqual(HSet)){

        cout << "True" << endl;

    }else{

        cout << "False" << endl;

    }

    cout << endl << endl<< "Bonus Tests:" << endl << endl;

    cout << endl << "Removing 0,50,and 100 from Set A:" << endl << endl << "Before: " << endl;
    
    ASet.display();
    cout << "the number of elements in this set is " << ASet.numElements()<< endl;

    ASet.removeElement(0);
    ASet.removeElement(50);
    ASet.removeElement(100);

    cout << endl << "After: " << endl;

    ASet.display();
    cout << "the number of elements in this set is " << ASet.numElements()<< endl;

    cout << endl << "Is set A equal to the compliment of set D? ";

    if(ASet.isEqual(DSet.complement())){

        cout << "True" << endl;

    }else{

        cout << "False" << endl;

    }

    cout << "This should be false because of the previous removed elements." << endl << endl;

    cout << "Is set C set equal to H Set? ";

    if(CSet.isEqual(HSet)){

        cout << "True" << endl;

    }else{

        cout << "False" << endl;

    }

    cout << "Is Set A equal to the double compliment of A? ";

    if(ASet.isEqual(ASet.complement().complement())){

        cout << "True" << endl;

    }else{

        cout << "False" << endl;

    }

    cout  << endl << "Thank you for using this program!"<< endl << endl << endl;

    return 0;

}
