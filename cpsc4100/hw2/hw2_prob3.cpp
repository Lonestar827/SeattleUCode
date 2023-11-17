/*Author: Jared Callero
 *Program: hw2_prob3.cpp (Maximum Subarray Sum)
 *Purpose: To find the transaction that provides the maximum profit
 *Version: 1
 */
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long findMaxCrossArray(vector<long long> array, long long start, long long mid, long long end)
{
  long long newStart = start, newEnd = end;
  long long leftsum = 0, rightsum = 0, sum = 0;

    

  for (long long i = mid; i > newStart; i--)
  {

    sum = sum + array[i];
    if (sum > leftsum)
      leftsum = sum;
  }

  sum = 0;
  

  for (long long j = mid + 1; j < newEnd; j++)
  {

    sum = sum + array[j];
    if (sum > rightsum)
      rightsum = sum;

    
  }
  
  return rightsum + leftsum;
}

long long findMaxRoundArray(vector<long long> array, long long mid, long long end, long long start)
{
  long long newStart = start, newEnd = end;
  long long leftsum = 0, rightsum = 0, sum = 0;

  for (long long i = newEnd; i > mid + 1; i--)
  {

    sum = sum + array[i];
    if (sum > leftsum)
      leftsum = sum;
  }

  sum = 0;
  for (long long i = newStart + 1; i < mid; i++)
  {

    sum = sum + array[i];
    if (sum > rightsum)
      rightsum = sum;
  }

  return rightsum + leftsum;
}

long long findMaxSubArray(vector<long long> array, long long start, long long end)
{

  long long newStart = start, newEnd = end;
  long long mid = newStart + (newEnd - newStart)/2;
  long long leftsum = 0, rightsum = 0, midsum = 0, crosssum = 0, firstmax = 0, secondmax = 0;

  // divide

  // edge case: 1 element
  if (newEnd == newStart)
    return array[newEnd];

  leftsum += findMaxSubArray(array, newStart, mid);
  rightsum += findMaxSubArray(array, mid + 1, newEnd);
  midsum += findMaxCrossArray(array, newStart, mid, newEnd);
  crosssum += findMaxRoundArray(array, mid + 1, newEnd, newStart);

  // conquer
  firstmax = max(leftsum, rightsum);
  secondmax = max(midsum, crosssum);

  return max(firstmax, secondmax);
}

long long max(long long n1, long long n2)
{

  if (n1 > n2)
    return n1;
  else
    return n2;
}

int main()
{

  long long size;
  // grab file and extract array size
  cin >> size;
  // make array of said size and populate it with the file contents
  vector<long long> newArray;
  newArray.resize(size);
  for (int i = 0; i < size; i++)
  {

    cin >> newArray[i];
  }

  // snewEnd array though algorithm
  cout << findMaxSubArray(newArray, 0, size - 1);
  // return result
  return 0;
}
