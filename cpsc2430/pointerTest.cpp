//Jared Callero
//pointerTests.cpp

//description: this program is used to apply my knowledge about c++ pointers

#include <iostream>
using namespace std;

int main(){

  //declare variables

  int firstValue, secondValue;
  int * fPtr,;

  //Get input

  cout << endl << endl << endl;
  cout << "Please enter two values for the integers" << endl;
  cin << firstValue;
  cin << secondValue;

  fPtr = &firstValue;
  cout << "The first value is" << *fPtr;

  fPtr = &secondValue;
  cout << "The second value is" << *fPtr;

  cout << "Program is finished.";
  cout << endl << endl << endl;

  return 0;

}
