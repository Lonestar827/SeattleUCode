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
    long long result = 0;
    
    //base case: only 1 space
    if (newStart > newEnd)return 0;

    if (newStart == newEnd) capitalGain(array, newStart - 1, mid);

    //divide
    if(newEnd-newStart > 2){

        result = capitalGain(array, newStart, mid) + capitalGain(array, mid+1, newEnd);

    }
    //conquer

    for(long long i = newStart; i < mid+1; i++){

        for(long long j = mid + 1; j <= newEnd; j++){

            if (array[j] > array[i]) result++;

        }

    }

    return result;

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