//Jared Callero
//loopsProgram.cpp
//Purpose : This program is for lab two and to get a handle on writting in cpp

#include <iostream>
using namespace std;

int main()
{
  //declare variables
  int first = 0, second = 0;
  bool condition = true;
  string answer;

  //explanation
  cout << endl << endl << endl;
  cout << "This will find out if the first number you prvide is a multiple of the second number you provide";
  cout << endl << endl;

  //begin loop
  while(condition)
    {
      //input
      cout << "First number? ";
      cin >> first;
      cout << "Second Number?";
      cin >> second;

      //output
      if(first % second == 0)
        {
          cout << first << " IS a multiple of " << second;
        } else {
        cout << first << " IS NOT a multiple of " << second;
      }

      // ask to continue the loop
      cout << endl;
      cout << "Would you like to repeat this? y/n?";
      cin >> answer;
      
      if(answer == "n")
        {
          condition = false;
        }
    }
  cout << "Thank you for using this program!"<< endl;
  return 0;
}
      
