//Jared Callero
//lab6.cpp
//11/19/2021

//Description: a program that can enqueue, dequeue, and print a queue with a size of six

//sources: lab1 on canvas, lab1.cpp from me

#include <iostream>
using namespace std;

#include<vector>

#include<ctime>

//global const definition:
const int MAX_SIZE = 6;

//global function prototypes
template<typename inputType>
void enqueue(inputType* Array,inputType input, int size);

template<typename inputType>
inputType dequeue(inputType* Array);

template<typename inputType>
void print(inputType* Array, int size);


int main(){

  float* array = new float[MAX_SIZE];
  bool userContinue = true;
  int currentSize = 0;
  string userInput;
  float arrayInput;
  int vectorInput;
  
  cout << endl << endl << endl;
  cout << "Welcome to the Lab 1 Queue Program, made by Jared Callero" << endl;

  //while userContinue = true
  while(userContinue){

    cout << "Do you want to enqueue(e), dequeue(d), or quit(q)? ";
    cin >> userInput;

    //if the user wants to enqueue
    if(userInput == "e"){

      //check if the array is full
      if(currentSize == MAX_SIZE){

        //inform user and restart loop
        cout << "Array is currently full, please dequeue to free up space" << endl;

      }else if(currentSize != 0){

        arrayInput = array[currentSize-1]*2;
        currentSize++;
        enqueue(array, arrayInput,currentSize);
        print(array,currentSize);
        

      }else {

        //get value from user and enqueue it to the list
        cout << "Please enter a positive value:" <<endl;
        cin >> arrayInput;
        currentSize++;
        enqueue(array, arrayInput,currentSize);
        print(array,currentSize);

      }

    }//if the user wants to dequeue
    else if(userInput == "d"){

      //check if the array is empty
      if(currentSize == 0){

        //inform user and restart loop
        cout << "There are no elements to dequeue, please add some to dequeue" << endl;

      }
      else {

        cout << "The dequeued value is " << dequeue(array) << endl;
        currentSize--;

      }
      
    }//if the user wants to quit:
    else if(userInput == "q"){

      //set userContinue to false
      userContinue = false;

    }

  }

  cout << endl <<"creating a vector of 5 random integers" << endl;

  vector<int> v1;
  srand(time(0));

  for(int i = 0; i < 5; i++){

    vectorInput = rand() % 100;
    v1.push_back(vectorInput);

  }

  for (int x:v1){

    cout << x << " ";

  }

  cout << endl << endl<< "Doubling each value:" << endl;

  for (int x:v1){

    x = x*2;
    cout << x << " ";

  }

  //thank the user for using the program
  cout << endl << endl << "Thank you for using this program!" << endl << endl << endl;

  delete[] array;
  //return 0
  return 0;

}

template<typename inputType>
void enqueue (inputType* array, inputType input, int size){
  //takes in a user inputed value and adds it to the queue
  //assumes the array has space and input is positive

  //insert input to array[1]
  array[size-1] = input;

}

template<typename inputType>
inputType dequeue(inputType* array){
  //removes an element from the queue and returns said value
  //assumes the array is not empty

  inputType returnValue = 0; //the value that will be returned

  //set the return Value to the first Value of the array

  returnValue = array[0];
  //iterate through the array moving each other element through the left 1
  for(int i = 0; i < MAX_SIZE - 1; i++){

    array[i] = array[i+1];

  }

  //return the returnValue
  return returnValue;


}

template<typename inputType>
void print(inputType* array, int size){
  //prints the current queue

  cout<< "Current Queue:";
  for(int i = 0; i < size; i++){

    cout << array[i];

    if(i != size-1){

      cout << ",";
      
    }

  }
  cout << endl;


}
