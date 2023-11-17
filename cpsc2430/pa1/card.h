//Callero, Jared
//CardStack.h
//10/11/2021

//provides operations for a CardStack

//sources: PA1.pdf on canvas, Transitioning to C++ Class section on Canvas

#include <iostream>
using namespace std;
#include <string>

#ifndef CARDSTACK_H
#define CARDSTACK_H

class CardStack {

private:

	class CardNode {
	private:

		int value; //the value of the card, 1 = ace. 11,12,13 = jack, queen, king
		string suit; //suit of the card. Spade, diamonds, clubs, hearts
		bool isJoker; // if the card is a joker or not
		CardNode* next; //pointer to the next card

	public:
		//default Constructor
		CardNode();

		//parameter constructor
		CardNode(int newValue, string newSuit, bool IsJoker);

		//copy Constructor
		CardNode(CardNode* newCard);

		//destructor
		~CardNode();

		//prints the card with the appropriate suit and number
		void printCard();

		void setNext(CardNode* newCard);

		CardNode* getNext();

		void setValue(int newValue);

		int getValue();

		void setSuit(string newSuit);

		string getSuit();

		void setIsJoker(bool newJoker);

		bool getIsJoker();
	};

	CardNode* isFront; //the front or top of the deck
	int size; //the current size of the deck


public:

	//default constructor
	CardStack();

	//parameter constructor
	CardStack(CardNode* newcard);

	//copy Constructor
	CardStack(CardStack* newStack);

	//destructor
	~CardStack();

	//takes a card from the top of the CardStack and returns the card
	CardNode* pop();

	//puts a card on the top of the CardStack (CardNode version)
	void push(CardNode* newCard);

	//puts a card on the top of the CardStack (pure variable version)
	void push(int newValue, string newSuit, bool IsJoker);

	//returns the current size
	int getSize();

	//iterates through the deck to find out the size of the deck
	int getNewSize(CardNode* newCard);

	//iterates through the deck with the chosen suit and returns the number of cards with that suit
	int countSuit(string suit);

	//prints each card by iterating through the deck and calling the printCard function on the card
	void printStack();

};

#endif // CardStack.h
