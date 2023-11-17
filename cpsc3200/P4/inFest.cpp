#include "inFest.h"
///Jared Callero
///Filename: inFest.cpp
///5/20/2022
///version: 1

/**Interface Invarience:
 * inFest(): Default constructor, sets up a simple infestation
 *
 * inFest(int x, int y, int z): Parameter constuctor. X and Y determine starting location, while Z determines size.
 * Z must be higher then 0 or else an exception will be thrown.
 *
 * inFest(const inFest &src): Copy Constructor
 *
 * inFest(inFest &&src): move constructor
 *
 * ~infest(): destructor
 *
 * void move(int p): moves every flea on the board p spaces in a random direction dependent on p.
 *
 * int getMin(): returns the smallest value among the fleas on the board.
 * if all fleas are dead, it should return -1, indicating an error state.
 *
 * int getMax(): returns the highest value among the fleas on the board
 * if all fleas are dead, it should return -1, indicating an error state.
 *
 * bool operator==(inFest src): equality operator, compares size of src inFest with own. Returns true if equal size
 *
 * bool operator<=(inFest src): equality operator, compares size of src inFest with own. Returns true if less then or equal to
 *
 * bool operator >=(inFest src): equality operator, compares size of src inFest with own. Returns true if greater then or equal to
 *
 * bool operator<(inFest src): equality operator, compares size of src inFest with own, returns true if less then.
 *
 * bool operator>(infest src); equality operator, compares size of src inFest with own, returns true if greater then.
 *
 * void operator++(): increment operator, expands inFest's gridFlea array by 1.
 *
 * void operator--(): decrement operator, reduces inFest's gridFlea array by 1.
 * Will throw an exception if the action would reduce the size to below 1
 *
 * gridFlea operator[](int index): returns a gridFlea at the requested index, will throw an exception if out of index.
 */

#include "inFest.h"
#include "gridFlea.h"
#include <cmath>

using namespace std;

inFest::inFest() {

    int newX = 0;
    int newY = 0;

    size = 5;
    numActive = 5;
    isActive = true;
    infestation = new gridFlea[size];

    for (int i = 0; i < size; i++) {

        if (i == 0)infestation[i] = gridFlea(newX, newY, size);
        else infestation[i] = gridFlea(newX + 1 * i, newY + 1 * i, size);

    }

}

inFest::inFest(int x, int y, int z) {
    //precondition: z is larger then 0

    if (z < 0) throw "Cant make a negetively sized grid!";
    size = z;
    numActive = z;
    isActive = true;
    infestation = new gridFlea[size];

    for (int i = 0; i < size; i++) infestation[i] = gridFlea(x * (i + 1), y * (i + 1), size);

}

inFest::inFest(const inFest &src) {

    deepCopy(src);

}

inFest &inFest::operator=(const inFest &src) {

    if (this == &src) return *this;
    deepCopy(src);
    return *this;

}

inFest &inFest::operator=(inFest&& src) noexcept{

    if (this == &src) return *this;
    deepCopy(src);
    return *this;

}

inFest::inFest(inFest&& src)  noexcept {

    deepCopy(src);

}

inFest::~inFest() {

    delete[] infestation;

}

void inFest::deepCopy(const inFest &src) {

    size = src.size;
    numActive = src.numActive;
    isActive = src.isActive;
    infestation = new gridFlea[size];

    for (int i = 0; i < size; i++) infestation[i] = src.infestation[i];

}

void inFest::move(int p) {
    //precondition: infestation has at least one flea on the grid
    //postcondition: some or all fleas could be restocked.
    if (p != 0) {

        for (int i = 0; i < size; i++) {

            infestation[i].move(p);

            if (infestation[i].dead()) numActive--;

        }

    }
}

int inFest::getMin() {
    //precondition: there needs to be at least one flea on the board
    int currentMin = -1;

    for (int i = 0; i < size; i++) {

        if (infestation[i].dead()) continue;

        if ((infestation[i].getValue() < currentMin) || (currentMin == -1)) {

            currentMin = infestation[i].getValue();

        }
    }

    return currentMin;

}

int inFest::getMax() {
    //Precondition: there needs to be at least one flea on the board
    int currentMax = -1;

    for (int i = 0; i < size; i++) {

        if (infestation[i].dead()) continue;

        if ((infestation[i].getValue() > currentMax) || (currentMax == -1)) {

            currentMax = infestation[i].getValue();

        }
    }

    return currentMax;

}

void inFest::restock() {

    for (int i = 0; i < size; i++) {

        if (infestation[i].dead()) infestation[i] = gridFlea((i + 1) * 2, (i + 2) * 3, size);

    }

}

int inFest::getSize() const{

    return size;

}

int inFest::getNumActive() const{

    return numActive;

}

bool inFest::operator==(const inFest& src) const {

    return size == src.size;

}

bool inFest::operator<=(const inFest& src) const{

    return size <= src.size;

}

bool inFest::operator>=(const inFest& src) const{

    return size >= src.size;

}

bool inFest::operator<(const inFest& src) const{

    return size < src.size;

}

bool inFest::operator>(const inFest& src) const{

    return size > src.size;

}

inFest inFest::operator+=(int num){

    return addFleas(num);

}

inFest inFest::operator++(){

    return addFleas(1);

}

inFest inFest::operator++(int num){

    inFest oldState = *this;

    addFleas(1);

    return oldState;

}

inFest inFest::operator-=(int num){

    if(size - num < 1) throw "Cant go below 0!";
    else return removeFleas(num);

}

inFest inFest::operator--(){

    if(size - 1 < 1) throw "Cant go below 0!";
    else return removeFleas(1);

}

inFest inFest::operator-(int num){

    if(size - num < 1) throw "Cant go below 0!";
    else return removeFleas(num);

}

inFest inFest::operator--(int num){

    if(size - num < 1) throw "Cant go below 0!";
    else {

        inFest oldState = *this;

        removeFleas(num);

        return oldState;

    }
}

inFest inFest::operator+(int num){

    return addFleas(num);

}

gridFlea inFest::operator[](int index){

    if(0 < index && index < size-1){

        return infestation[index];

    }else throw "Out of index!";

}

inFest inFest::addFleas(int num){

    int newSize = size + num;
    int newActive = 0;
    gridFlea* newInFestation = new gridFlea[newSize];
    int newValue;

    for(int i = 0; i < size; i++){

        newInFestation[i] = infestation[i];
        if (!infestation[i].dead()) newActive++;

    }

    while (size < newSize){

        newValue = infestation[size-1].getValue();

        newInFestation[size-1] = gridFlea(newValue/2,newValue/2, newValue);

        size++;
        newActive++;

    }

    numActive = newActive;

    return *this;

}

inFest inFest::removeFleas(int num){

    gridFlea *newInFestation = new gridFlea[size - num];
    int newActive = 0;

    size = size - num;

    for(int i = 0; i < size; i++){

        newInFestation[i] = infestation[i];
        if (!infestation[i].dead()) newActive++;

    }

    numActive = newActive;

    return *this;

}

//todo: recheck implamentation invarients for changes

/**Implamentation Invarients:
 *
 * move(int p): uses a for loop to call move() on each flea then check to see if each flea is dead. If they are, decrease the number active
 * then check the number of fleas to see if half of them are dead. If they are, restock them.
 *
 * getMin():Set up a variable currentMin as -1 because values cant be below 0.
 * use a for loop to check each Flea. If the flea is dead, continue to the next loop without checking
 * if the value of the flea is smaller then the currentMin or the currentMin is negetive 1, make the value the new currentMin
 * return the currentMin at the end of the loops
 *
 * getMax():Set up a variable currentMax as -1 because values cant be below 0.
 * use a for loop to check each Flea. If the flea is dead, continue to the next loop without checking
 * if the value of the flea is larger then the currentMax or the currentMax is negetive 1, make the value the new currentMax
 * return the currentMax at the end of the loops
 *
 * restock():using a for loop, check to see if each flea is dead or not
 * if they are dead, make a new flea using the algorithm gridFlea((i+1)*2, (i+2)*3, size)
 *
 * deepCopy(): utility method for copy methods.
 *
 * General Equality Operators: (==, <=, >=, etc): These use the current sizes of the inFest arrays to assist in inFest comparisons
 *
 * inFest operator+=(int num): increase the infesteation by num gridfleas.
 * calls addFleas(num) and returns the result
 *
 * void operator++() (PreIncrement): increase the infesteation by 1 gridflea.
 * calls addFleas(1) and returns the result
 *
 * * void operator++(int num) (PostCrement): increase the infesteation by 1 gridflea.
 * makes an oldstate Infestation, calls addFleas(1), then returns the oldstate
 *
 * void operator--(): decreases the infestation by 1 gridflea.
 *
 *
 * gridFlea operator[](int index):if the inputted number is within the bounds of the array,
 * this will return the gridFlea at the index in the array inFestation
 *
 * inFest addFleas(int num):
 * It achieves this by first making an array that will fit the new size, adding the num to the current size
 * then scans the old infestation to reset the fleas onto the new list, incrementing the newActive if they're alive.
 * once thats over, it proceeds with the creation of the new fleas, using the algorithm gridFlea(newValue/2,newValue/2, newValue)
 * where newValue is the value of the current gridFlea at the end of the array.it then sets the currentActive to newActive and returns the state.
 *
 * inFest removeFleas(int num):
 * it achieves this by making a new array thats one space smaller then the current array and copying over the current gridfleas but 1.
 * then replaces the current array.
 * the function will throw an exception if the user tries to decrease it past 1 gridflea.
 *
 */
