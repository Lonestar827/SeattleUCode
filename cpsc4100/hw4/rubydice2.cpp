/**Author: Jared Callero
 * Program: rubydice2.cpp
 * 
 * Required Comments:
 * 
 * Structure of optimal solution:
 * V(n,rem) = max(V(n-1,j)
 *                V(n-1, j-w[n-1]) + v[n-1] if w[n-1] if w[n] < rem
 *                V(n-1, j- 2w[n-1]) + 2v[n-1] if 2[n-1] if 2w[n] < rem)
 * 
 * Time Efficiency
 * O(n*rem)
 */

#include <algorithm>
#include <climits>
#include <vector>
#include<iostream>
using namespace std;

int main(){

    //Initialize necessary variables

    int size, dollars;
    vector<int> weight;
    vector<int> value;
    vector<vector<int>> cache;

    //read from input and populate variables

    cin >> size >> dollars;

    weight.resize(size);
    value.resize(size);
    cache.resize(size+1);

    for(int i = 0; i < size; i++){

      cache[i].resize(dollars);

    }

    fill(cache[0].begin(), cache[0].end(), 0);

    for(int i = 0; i < size; i++){

        cin >> weight[i];
        cin >> value[i];

    }

    //traverse cache table
    for(int die = 1; die < size; die++){

        for(int currentDollar = 0; currentDollar < dollars; currentDollar++){

            cache[die][currentDollar] = 0;
            //take 2
            if(weight[die-1] * 2 < currentDollar){

                cache[die][currentDollar] = max(cache[die][currentDollar], cache[die-1][currentDollar - 2*weight[die-1]] + 2 * value[die-1]);

            }//take 1
            else if(weight[die-1]< currentDollar){

                cache[die][currentDollar] = max(cache[die][currentDollar], cache[die-1][currentDollar - weight[die-1]] + value[die-1]);

            }//else
            else cache[die][currentDollar] = max(cache[die][currentDollar], cache[die-1][currentDollar]);
            

        }      

    }

    cout << cache[size][dollars] << endl;
    return cache[size][dollars];

}
