#include "cardStack.cpp"
#include <iostream>
using namespace std;

int main() {

	cardStack c = cardStack();

	c.pop(); //should print "There is no card to pop"

	c.push(3, "diamonds", false);
	c.push(10, "diamonds", false);
	c.push(0, "joker", true);
	c.push(1, "hearts", false);
	c.push(12, "diamonds", false);

	c.printStack(); 
	//should print the following:
	//Queen of diamonds
	//Ace of hearts
	//Joker
	//10 of diamonds
	//3 of diamonds

	cout << "There are " << c.countSuit("diamonds");
	cout << " diamond(s) on the stack." << endl;
	//prints "There are 3 diamond(s) on the stack

	cardStack c2 = c;


}
