///Jared Callero
///Filename: inFest.cpp
///4/12/2022
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
 * move(int p): moves every flea on the board p spaces in a random direction dependent on p.
 *
 * getMin(): returns the smallest value among the fleas on the board
 *
 * getMax(): returns the highest value among the fleas on the board
 */

#include "inFest.h"
#include "gridFlea.h"

using namespace std;

inFest::inFest() {

    int newX = 0;
    int newY = 0;

    size = 5;
    numActive = 5;
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

inFest::inFest(inFest &&src) {

    deepCopy(src);

    this->size = 0;
    this->numActive = 0;
    infestation = nullptr;

}

inFest::~inFest() {

    delete[] infestation;

}

void inFest::deepCopy(const inFest &src) {

    size = src.size;
    numActive = src.numActive;
    infestation = new gridFlea[size];

    for (int i = 0; i < size; i++) infestation[i] = src.infestation[i];

}

void inFest::move(int p) {
    //precondition: infestation has at least one flea on the grid
    //postcondition: some or all fleas could be restocked.
    if (p != 0) {

        for (int i = 0; i < size; i++) {

            infestation[i].move(p);

            if (!infestation[i].dead()) numActive--;

        }

        if (numActive < size / 2) restock();

    }
}

int inFest::getMin() {
    //precondition: there needs to be at least one flea on the board
    int currentMin = -1;

    for (int i = 0; i < size; i++) {

        if (infestation[i].dead()) continue;

        if ((infestation[i].value() < currentMin) || (currentMin == -1)) {

            currentMin = infestation[i].value();

        }
    }

    return currentMin;

}


int inFest::getMax() {
    //Precondition: there needs to be at least one flea on the board
    int currentMax = -1;

    for (int i = 0; i < size; i++) {

        if (infestation[i].dead()) continue;

        if ((infestation[i].value() > currentMax) || (currentMax == -1)) {

            currentMax = infestation[i].value();

        }
    }

    return currentMax;

}


void inFest::restock() {

    for (int i = 0; i < size; i++) {

        if (infestation[i].dead()) infestation[i] = gridFlea((i + 1) * 2, (i + 2) * 3, size);

    }

}

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
 */
