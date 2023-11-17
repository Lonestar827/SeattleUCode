/**Author: Jared Callero
 * Program: chain.cpp
 * 
 * Required Comments:
 * 
 * Structure of optimal solution:
 *
 * F(i) = 1 + max ( F(j)  where j > i and F0i) > F(j) )
 * 
 * Time Efficiency
 * O(nlogn)
 */
#include <algorithm>
#include <climits>
#include <vector>
#include<iostream>
using namespace std;

int main(){

    int size, result = 1;
    vector<int> dice;
    vector<int> cache;
    
    cin >> size;

    dice.resize(size);
    cache.resize(size);

    for(int i = 0; i < size; i++){

        cin >> dice[i];

    }

    //base case
    cache[0] = 1;

    for(int i = 1; i < size; i++){
        
        cache[i] = 1;

        for(int j = 0; j < i; j++){

            if (dice[i] < dice[j] && cache[i] < cache[j] + 1) 
            cache[i] = cache[j] +1;

        }

    }

    for(int number : cache) result = max(result, number);

    cout << result << endl;
    return result;

}
