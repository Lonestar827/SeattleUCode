//cardStack.h
//provides operations for a cardstack

#include <iostream>
using namespace std;

#ifndef CARDSTACK_H
#define CARDSTACK_H

class CardStack {

private:

	class CardNode {
	private:

		int value; //the value of the card, 1 = ace. 11,12,13 = jack, queen, king
		string suit; //suit of the card. Spade, diamonds, clubs, hearts
		bool isJoker; // if the card is a joker or not
		cardNode* next; //pointer to the next card

	public:
		//default Constructor
		CardNode();

		//parameter constructor
		CardNode(int newValue, string newSuit, bool IsJoker);

		//copy Constructor
		CardNode(cardNode* newCard);

		//destructor
		~CardNode();

		//prints the card with the appropriate suit and number
		void printCard();

		void setNext(cardNode* newCard);

		cardNode* getNext();

		void setValue(int newValue);

		int getValue();

		void setSuit(string newSuit);

		string getSuit();

		void setIsJoker(bool newJoker);

		bool getIsJoker();
	};

	cardNode* isFront; //the front or top of the deck
	int size; //the current size of the deck


public:

	//default constructor
	CardStack();

	//parameter constructor
	CardStack(cardNode* newcard);

	//copy Constructor
	CardStack(cardStack* newStack);

	//destructor
	~CardStack();

	//takes a card from the top of the cardStack and returns the card
	cardNode* pop();

	//puts a card on the top of the cardStack (cardNode version)
	void push(cardNode* newCard);

	//puts a card on the top of the cardStack (pure variable version)
	void push(int newValue, string newSuit, bool IsJoker);

	//returns the current size
	int getSize();

	//iterates through the deck to find out the size of the deck
	int getNewSize(cardNode* newCard);

	//iterates through the deck with the chosen suit and returns the number of cards with that suit
	int countSuit(string suit);

	//prints each card by iterating through the deck and calling the printCard function on the card
	void printStack();

};

#endif // cardStack.h
