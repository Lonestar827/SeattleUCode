///Jared Callero
///Filename: p2.cpp
///4/12/2022
///version: 1
#include <iostream>

using namespace std;

#include "inFest.h"

void defaultTest();

void parameterTest();

int main() {

    cout << endl << endl << endl;
    cout << "Welcome to P2:inFest, by Jared Callero" << endl << endl;

    defaultTest();

    parameterTest();

    cout << "Thank you for using P2!" << endl << endl << endl;

    return 0;

}

void defaultTest() {

    cout << "Creating default infestation:" << endl;

    inFest *regular = new inFest();

    cout << "Current max value is: " << regular->getMax() << endl;

    cout << "Current min value is: " << regular->getMin() << endl;

    cout << "Attempting copy..." << endl;
    inFest *copy = new inFest(*regular);

    cout << "Moving every flea 5 spaces: " << endl;
    regular->move(5);

    cout << "Current max value for regular is is: " << regular->getMax() << endl;

    cout << "Current max value for copy is is: " << copy->getMax() << endl;

    cout << "Current min value for regular is: " << regular->getMin() << endl;

    cout << "Current min value for copy is: " << copy->getMin() << endl;

    cout << endl;

}

void parameterTest() {

    int testX = 5;
    int testY = 10;
    int testZ = 20;

    cout << "Creating parameterized infestation with x,y, and z being "
         << testX << "," << testY << ", and " << testZ << " respectively" << endl;

    inFest *parameter = new inFest(testX, testY, testZ);

    cout << "Current max value is: " << parameter->getMax() << endl;

    cout << "Current min value is: " << parameter->getMin() << endl;

    cout << "Attempting copy..." << endl;
    inFest *copy = new inFest(*parameter);

    cout << "Moving every flea 5 spaces: " << endl;
    parameter->move(5);

    cout << "Current max value for parameter is: " << parameter->getMax() << endl;

    cout << "Current max value for copy is: " << copy->getMax() << endl;

    cout << "Current min value for parameter is: " << parameter->getMin() << endl;

    cout << "Current min value for copy is: " << copy->getMin() << endl;

}
