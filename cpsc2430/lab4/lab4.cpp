//Callero Jared
//Lab 4
//10/29/2021

//SourceL Lecture9-Heaps.pdf from canvas

#include <iostream>
using namespace std;

#include<ctime>

typedef int ElementType;

ElementType deleteMin();
void insertValue(ElementType value, ElementType* heapArr, int& currentSize);
ElementType deleteMin(ElementType* heapArr, int& currentSize);
void percolateDown(ElementType* heapArr, int& currentSize, int hole);
void printArray(ElementType*& arr, int currentSize);

int main(){

    ElementType* heapArr = new ElementType[13];
    int currentSize = 0;
    int input = 0;
    int userInput = 0;
    ElementType removed = 0;

    srand(time(0));

    cout << endl << endl << endl;
    cout << "Welcome to the Lab 4 Program, written by Jared Callero" << endl;

    for(int i = 0; i < 10; i++){

        input = rand() % 100;
        insertValue(input,heapArr,currentSize);
        
    }
    printArray(heapArr,currentSize);

    cout << "How many elements do you want to remove?: ";
    cin >> userInput;
    cout << endl;

    for(int i = 0; i < userInput; i++){

        removed = deleteMin(heapArr,currentSize);
        cout << removed << " has been removed." << endl << endl;

    }

    cout << "End of Lab 4. Thank you for using this program!" << endl << endl << endl;

    return 0;

}

void insertValue(ElementType value, ElementType* heapArr, int& currentSize){

    int hole = ++currentSize;
    
    heapArr[0] = value;

    while(value < heapArr[hole/2]){

        heapArr[hole] = heapArr[hole/2];
        hole /= 2; 

    }
    heapArr[hole] = heapArr[0];

}

ElementType deleteMin(ElementType* heapArr, int& currentSize){

    ElementType result = heapArr[1];
    heapArr[1] = heapArr[currentSize--];
    percolateDown(heapArr, currentSize, 1);
    return result;

}

void percolateDown(ElementType* heapArr, int& currentSize, int hole){

    int child;
    ElementType tmp = heapArr[hole];
    bool bubbleDown = true;
    while( bubbleDown && hole * 2 <= currentSize){

        child = hole * 2;
        if(child != currentSize && heapArr[child + 1] < heapArr[child])
            ++child;
        if (heapArr[child] < tmp){
            cout << heapArr[child] << " goin up!" << endl;
            heapArr[hole] = heapArr[child];
        }
        else
        bubbleDown = false;

        if (bubbleDown) hole = child;

    }
    heapArr[hole] = tmp;

}

void printArray(ElementType*& arr, int currentSize){

    for(int i = 0; i < currentSize; i++){

        cout << arr[i];
        if(i != currentSize - 1){

            cout << ", "; 

        }
    }
    cout << endl;

}