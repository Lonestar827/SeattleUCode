//Jared Callero
//Lab2.cpp
//10/8/2021

typedef int ElementType;

#include <iostream>
using namespace std;

struct Node {

    ElementType value = 0;
    Node* next = nullptr;

};

void printList(Node* nPtr, int x);
void insertNode(Node *& head, ElementType value);
void deleteNodes(Node* head);

int main()
{
    Node* front = nullptr;
    int userInput;
    ElementType nodeInput;

    //Welcome user and ask them for the number of elements for the list
    cout << endl << endl << endl;
    cout << "Welcome to the Lab 2 Program, written by Jared Callero" << endl;
    cout << "How many elements would you like in the list?:";
    cin >> userInput;
    
    //for loop with userInput as the base to populate list.
    for (int i = 0; i < userInput; i++) {
    
        cout << "Please a value:";
        cin >> nodeInput;
        insertNode(front, nodeInput);
    
    }
    //ask user how many elements they want to print
    cout << "How many elements do you want to print?:";
    cin >> userInput;
    //call Print variable for number inputted
    
    printList(front, userInput-1);

    //thank user and end program.

    cout << endl;
    cout << "Thank you for using this program!";
    cout << endl << endl << endl;
    deleteNodes(front);
    return 0;

}

void printList(Node* nPtr, int x) {
    //prints up to the xth node in the linked list

    //Base Case:If the next node is null or x = 0:
    if (nPtr->next == nullptr || x == 0) {
        //print out value and end function
        cout << nPtr->value << endl;
    }
    //Reduction case: if the next node is not null and x > 0
    else if (nPtr->next != nullptr && x > 0) {

        cout << nPtr->value << " ";
        printList((*nPtr).next, x - 1);

    }
}

void insertNode(Node*& head, ElementType value) {
    //inserts a new node into the linked list

    //If there is no Head node, made the newNode the head
    if (head == nullptr) {
        
        Node* newNode = new Node;
        newNode->value = value;

        head = newNode;

    }
    //if there is a head but no next, make the newNode the next in the list.
    else if (head != nullptr && head->next == nullptr) {
        
        Node* newNode = new Node;
        newNode->value = value;
        head->next = newNode;

    }
    //if there is a head AND a next, recurse with insert(head.next, newNode)
    else {
    
        insertNode(head->next, value);
    
    }

}

void deleteNodes(Node* head) {

    //If there is no Head node, made the newNode the head
    if (head == nullptr) {

        

    }
    //if there is a head but no next, make the newNode the next in the list.
    else if (head != nullptr && head->next == nullptr) {

        delete head;

    }
    //if there is a head AND a next, recurse with insert(head.next, newNode)
    else {

        deleteNodes(head->next);
        delete head;

    }

}
