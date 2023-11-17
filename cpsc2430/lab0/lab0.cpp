// Callero, Jared
//lab0.cpp
//9/23/2023

#include <iostream>
using namespace std;

//function declaration
int maxValue(int param[10]);

int main()
{

  //Say welcome message
  cout << endl << endl << endl << "Welcome to the Lab 0 Program, made by Jared Callero" << endl;

  //set up array
  int arr[10];//the user will input 10 numbers into here

  //for ten iterations:
  for(int i = 0; i < 10; i++){

    //get input from user for what number they want in I slot of array
    cout << "Please provide a value for slot #" << i + 1 << endl;
    cin >> arr[i];

  }
  //once inputted, iterate through the list saying the index and the value at the index of the array
  for(int i = 0; i < 10; i++){

    cout << "#" << i + 1 << ": " << arr[i] << endl; 

  }
  //call the maxValue() function
  cout << "The max value in the array is: " << maxValue(arr) << endl;

  //announce the end of the program and then return 0
  cout << "Thank you for using the Lab 0 Program!" << endl << endl << endl;
  return 0;

}

int maxValue(int param[10])
{

  //declare values

  int  maxValue = 0; //the index of the max value, along with the max value itself

  //for the length of the array:
  for(int i = 0; i < 10; i++)
    {

      //if the value at param[i] is bigger then the current maxValue:
      if(param[i] > maxValue)
        {

          //replace the current maxvalue with the one at param[i]
          maxValue = param[i];

        }

    }

  //once loop is done, return the maxValue.
  return maxValue;
  
}
