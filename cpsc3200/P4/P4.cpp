///Jared Callero
///Filename: p4.cpp
///5/20/2022
///version: 1
#include <iostream>
#include <memory>
#include <vector>
#include <random>

using namespace std;

#include "inFest.h"

int main() {

    vector<inFest> inFestVector;
    vector<gridFlea> gridFleaVector;
    random_device rd;
    int vectorSize = rd() % 10 + 3;
    int randX, randY, randSize, randMove, randAddition;

    cout << endl << endl << endl;

    cout << "Welcome to P4 by Jared Callero" << endl << endl;

    cout << "inFest Tests, vector size:" << vectorSize << endl;

    for(int i = 0; i < vectorSize; i++){

        randX = rd() % 20;
        randY = rd() % 20;
        randSize = rd() % 10 + 1;

        cout << "Creating and inserting inFest with inputs " << randX << ", " << randY << ", and " << randSize << endl;

        inFestVector.push_back(inFest(randX,randY,randSize));

    }
    cout << endl;

    //InFest Tests

    cout << "numActive, getMin(), getMax(),:" << endl;

    for(int i = 0; i < vectorSize; i++){

        randMove = rd() % 20 + 1;

        inFestVector[i].move(randMove);

        cout << inFestVector[i].getNumActive() << "," << inFestVector[i].getMin() << "," << inFestVector[i].getMax() <<  endl;

    }

    cout << endl;

    cout << "Adding then removing 3 gridfleas to each infest using operator++/-- (pre and post) and operator+=1: " << endl;
    cout << "numActive, getMin(), getMax(),:" << endl;

    for(int i = 0; i < vectorSize; i++){

        //the 1 is hard coded into here to show that Operator++/--(), operator++/--(int num), and Operator+= 1 are equivalent

        ++inFestVector[i];
        inFestVector[i]+= 1;
        inFestVector[i]++;

        cout << inFestVector[i].getNumActive() << "," << inFestVector[i].getMin() << "," << inFestVector[i].getMax() <<  endl;

        --inFestVector[i];
        inFestVector[i]-= 1;
        inFestVector[i]--;

    }

    cout << endl;

    cout << "gridFlea Tests, vector size:" << vectorSize << endl;

    for(int i = 0; i < vectorSize; i++){

        randX = rd() % 20;
        randY = rd() % 20;
        randSize = rd() % 10 + 1;

        cout << "Creating and inserting gridFlea with inputs " << randX << ", " << randY << ", and " << randSize << endl;

        gridFleaVector.push_back(gridFlea(randX,randY,randSize));

    }
    cout << endl;

    cout << "adding then subtracting a random ammount from each gridFlea:"<< endl;

    for(int i = 0; i < vectorSize; i++){

        randAddition = rd() % 50 + 5;

        cout << gridFleaVector[i].getValue()<< " + " << randAddition << "=";

        gridFleaVector[i]+= randAddition;

        cout << gridFleaVector[i].getValue()<< endl;

    }
    cout << endl;

    cout << "Removing fleas from vector" << endl << endl;
    gridFleaVector.clear();

    cout << "Wrapping the first inFest in the vector in a unique_ptr" << endl;
    unique_ptr<inFest> UniquePointerTests(new inFest(inFestVector.front()));
    cout << "numActive, getMin(), getMax(),:" << endl;
    cout << UniquePointerTests->getNumActive() << "," << UniquePointerTests->getMin() << "," << UniquePointerTests->getMax() <<  endl;
    cout<< endl;

    cout << "Wrapping the first inFest in the vector in a unique_ptr" << endl;

    shared_ptr<inFest> SharedPtrTests(new inFest(inFestVector.back()));
    cout << "numActive, getMin(), getMax(),:" << endl;
    cout << SharedPtrTests->getNumActive() << "," << SharedPtrTests->getMin() << "," << SharedPtrTests->getMax() <<  endl;
    cout<< endl;

    cout << endl << "End of P4, Thank you!" << endl << endl << endl;

}


