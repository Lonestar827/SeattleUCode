//Jared Callero
//functionPractice.cpp
//9/8/2021

//Description: Practicing making functions in C++

#include <iostream>
using namespace std;

void welcome(){
  //Print out a welcome message to the screen
  cout << endl << endl << endl;
  cout << "Welcome to the Program!" << endl ;
}

int* input(){
  //requests two integers and returns both of them to main

  //declare variables
  int first, second;
  static int arr[100];

  //request integers
  cout << "First Integer? " << endl;
  cin >> first;
  cout << "Second Integer? " << endl;
  cin >> second;

  //make and output array
  arr[0] = first;
  arr[1] = second;

  return arr;
}

int summation(int arr[100]){
  //requires two integers and returns the sum of the integers from the smaller given number to the larger given number, inclusive
  return arr[0] + arr[1];
}

void output(int arr[100]){
  //requires two integers that had been input as well as the result and prints it all to the screen in a neatly formatted mesage
  int sum = summation(arr);
  cout << arr[0] << " + " << arr[1] << " = " << sum << endl;
}

void goodbye(){
  //print a goodbye message on the screen
  cout << "Goodbye!" << endl << endl << endl;
}

int main(){
  welcome();
  output(input());
  goodbye();

  return 0;
}
