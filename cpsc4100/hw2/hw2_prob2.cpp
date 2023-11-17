/*Author: Jared Callero
*Program: hw2_prob1.cpp (Counting Transactions Yielding a Capital Gain)
*Purpose: To find the number of transactions that yield a 
*capital gain in a provided array
*Version: 1 
*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

long long capitalGain(vector<long long> array, long long start, long long end){
    
    long long newStart = start;
    long long newEnd = end;
    long long mid = newStart + (newEnd - newStart)/2;
    long long capital= 0, newCapital = 0, newMin, newMax;
    
    //base case: only 1 space
    if (newStart > newEnd)return 0;

    //divide
    if(newEnd-newStart > 2){

        capital = max(capitalGain(array, newStart, mid), capitalGain(array, mid+1, newEnd));

    }
    //conquer
    
    newMin = array[start];

    for(long long i = start; i <= mid; i++){

        if(array[i] < newMin) newMin = array[i];

    }
    
    newMax = array[mid+1];

    for(long long j = mid+1; j < end; j++){

        if(array[j] > newMax) newMax = array[j];
        
    }

    newCapital = newMax - newMin;

    if(newCapital < capital) return capital;
    else return newCapital;

}

int main(){

    long long size;
    //grab file and extract array size
    cin >> size;
    //make array of said size and populate it with the file contents
    vector<long long> newArray;
    newArray.resize(size);
    for(int i = 0; i < size; i++){

        cin >> newArray[i];

    }

    
    //snewEnd array though algorithm
    cout << capitalGain(newArray, 0, size-1);
    //return result
    return 0;

}