//Callero Jared
//card.cpp
//10/11/2021

//Description:provides operations for a CardStack

//sources: PA1.pdf on canvas, Transitioning to C++ Class section on Canvas

#include "card.h"

CardStack::CardNode::CardNode() {
	//default Constructor
	//CardNode();

	value = 0;
	suit = "clubs";
	isJoker = false;
	next = nullptr;

}

CardStack::CardNode::CardNode(int newValue, string newSuit, bool newJoker) :
	//parameterized Constructor
	value(newValue),
	suit(newSuit),
	isJoker(newJoker) {

	next = nullptr;

}

CardStack::CardNode::CardNode(CardNode* newCard) {
	//copy Constructor

	value = newCard->value;
	suit = newCard->suit;
	isJoker = newCard->isJoker;
	next = newCard->next;

}


CardStack::CardNode::~CardNode() {
	//destructor
	delete next;

}
//prints the card with the appropriate suit and number
void CardStack::CardNode::printCard() {
	//prints the card with the appropriate suit and number

	
	//Edge case: the card is a joker
	if (isJoker) {

		cout << "Joker" << endl;

	}

	//edge case: the value is a 1, 11, 12, or 13 (Ace, jack, queen, king)
	else if (value == 1 || value == 11 || value == 12 || value == 13) {

		//ace case
		if (value == 1) {

			cout << "Ace of " << suit << endl;

		}
		//jack case
		else if (value == 11) {

			cout << "Jack of " << suit << endl;

		}
		//queen case
		else if (value == 12) {

			cout << "Queen of " << suit << endl;

		}
		//king case
		else {

			cout << "King of " << suit << endl;

		}



	}
	//base case:
	else {

		cout << value << " of " << suit << endl;

	}

}

void CardStack::CardNode::setNext(CardNode* newCard) {

	next = newCard;

}

CardStack::CardNode* CardStack::CardNode::getNext() {

	return next;

}

void CardStack::CardNode::setValue(int newValue) {

	value = newValue;

}

int CardStack::CardNode::getValue() {

	return value;

}

void CardStack::CardNode::setSuit(string newSuit) {

	suit = newSuit;

}

string CardStack::CardNode::getSuit() {

	return suit;

}

void CardStack::CardNode::setIsJoker(bool newJoker) {

	isJoker = newJoker;

}

bool CardStack::CardNode::getIsJoker() {

	return isJoker;

}

CardStack::CardStack() {
	//default constructor
	isFront = nullptr;
	size = 0;

}

CardStack::CardStack(CardNode* newCard) {
	//parameter constructor
	//REMEMBER TO PASS IN THE ADDRESS OF THE POINTER
	isFront = newCard;
	size = getNewSize(newCard);

}


CardStack::CardStack(CardStack* oldStack) {
	//copy Constructor
	
	//old carsStack to copy
	CardNode* oldCard = oldStack->isFront;

	//newFront to be set
	CardNode* newFront = new CardNode(oldStack->isFront);

	//traversal node
	CardNode* tmp = newFront;

	for (int i = 0; i < oldStack->getSize(); i++) {
	
		tmp->setSuit(oldCard->getSuit());
		tmp->setValue(oldCard->getValue());
		tmp->setIsJoker(oldCard->getIsJoker());
		tmp->setNext(oldCard->getNext());
	
		//traverse through
		oldCard = oldCard->getNext();
		tmp = tmp->getNext();

	}

	isFront = newFront;
	size = oldStack->size;
}

CardStack::~CardStack(){



}

CardStack::CardNode* CardStack::pop() {
	//takes a card from the top of the CardStack and returns the card
	CardNode* resultCard = nullptr;

	//edge case: there are no cards to pop:
	if (isFront == nullptr) {

		//inform user there are no cards to pop
		cout << "Theres no cards to pop" << endl;
		return resultCard;

	}
	//base case: there is a card to pop from the top
	else {

		//set resultCard to top card
		resultCard = isFront;

		//set isFront to be the next card
		isFront = isFront->getNext();

		//reduce size by 1
        size--;

		//return resultCard
		return resultCard;

	}


}

void CardStack::push(CardNode* newCard) {
	//puts a card on the top of the CardStack (CardNode version)

	//edgecase: there is no front
	if (isFront == nullptr) {

		//set isFront to newCard
		isFront = newCard;

		//increase size by 1
		size++;

	}
	//basecase: there is a front
	else {

		//set the newCards next to the current front
		newCard->setNext(newCard);

		//Set the front to the newCard
		isFront = newCard;

		//increase size by 1
		size++;

	}


}

void CardStack::push(int newValue, string newSuit, bool IsJoker) {
	//puts a card on the top of the CardStack (pure variable version)

	CardNode* newCard = new CardNode(newValue, newSuit, IsJoker);

	//edgecase: there is no front
	if (isFront == nullptr) {

		//set isFront to newCard
		isFront = newCard;

		//increase size by 1
		size++;

	}
	//basecase: there is a front
	else {

		//set the newCards next to the current front
		newCard->setNext(isFront);

		//Set the front to the newCard
		isFront = newCard;

		//increase size by 1
		size++;

	}
}

int CardStack::getSize() {
	//returns the current size
	return size;
}


int CardStack::getNewSize(CardNode* newNode) {
	//iterates through the deck to find out the size of the deck

	//base case, there is no next
	if (newNode->getNext() == nullptr) {

		//just return 1
		return 1;

	}
	//reduction case: there is a next
	else {

		//return 1 with an iteration on the next 
		return 1 + getNewSize(newNode->getNext());

	}
}


int CardStack::countSuit(string suitCheck) {
	//iterates through the deck with the chosen suit and returns the number of cards with that suit

	//edgeCase:there is no top
	if (isFront == nullptr) {
	
		cout << "No cards to scan";
		return 0;
	
	}
	//base case:
	else {
		
		CardNode* tmp = isFront; //traversal node
		int result = 0;//the return value of each checked suit

		//for loop going through stack using Size as the number of times to go through
		for(int i = 0; i < size; i++){
			
			if (tmp->getSuit() == suitCheck) {
				
				result++;
			
			}

			tmp = tmp->getNext();
		
		}

		return result;

	}
}


void CardStack::printStack() {
	//prints each card by iterating through the deck and calling the printCard function on the card

	//edge case: there is nothing to print
	if (isFront == nullptr) {
	
		cout << "No deck to print" << endl;

	}
	else {
		
		CardNode* tmp = isFront;

		for (int i = 0; i < size; i++) {
		
			tmp->printCard();
			tmp = tmp->getNext();
		
		}
	
	}


}
