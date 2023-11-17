/**Author: Jared Callero
 * Program: rubydice1.cpp
 * 
 * Required Comments:
 * 
 * Structure of optimal solution:
 * 
 * F(n, rem) = sum(F(n-1, rem)
 *                 F(n-1, rem % v[n]) + rem // v[n]  when rem > v[n])
 * 
 * Time Efficiency:
 * O(n)
 */

#include <algorithm>
#include <climits>
#include <vector>
#include<iostream>
using namespace std;

int main(){

    //Initialize necessary variables

    int size, dollars, result = 0;
    vector<int> dice;
    vector<int> cache;

    //read from input and populate variables

    cin >> size >> dollars;

    dice.resize(size);
    cache.resize(size);

    for(int i = 0; i < size; i++){

        cin >> dice[i];

    }

    reverse(dice.begin(), dice.end());
    //traverse cache table
    for(int die = 0; die < size; die++){

      if(dice[die] < dollars){

        cache[die] = dollars / dice[die];
        dollars = dollars % dice[die];

      }

    }

    
    for(int number : cache) result += number;
   
    cout << result << endl;

    return result;

}
