/**Author: Jared Callero
 *FileName: GridFlea.CS
 *Date:4/5/2022

 *Revision 2:
 *Ported over to C++,
 *added bool property isDead for permanent deactivation,
 *added default constructor gridFlea(),
 *added newSize int parameter to constructor to define size,
 *modified parameter constructor gridFlea() to compensate for new parameter
 *added bool method isActive() that returns active
 *added copy constructor to help with inFest deep copies
 * added operator= to help with deep copies

 */

/**Interface Invariants:
 *
 * gridFlea(): Default constructor, sets up a simple gridflea
 *
 * gridFlea(int newX, int newY, int newSize): Parameter constructor, newX and newY define starting coords and newSize defines size
 * Other parameters are initialized using newX and newY as factors
 *
 * gridFlea(const gridFlea &oldFlea) Copy constructor
 *
 * move(int p): moves the flea p spaces in a random direction, will only move if p is not 0, otherwise nothing happens
 *
 * value(): returns the value of the flea, based off of distance from start, size of grid, and the initial value.
 * will return 0 if out of bounds
 *
 * reset(): moves flea back to starting coordinates, returns true if successful, false if its out of bounds.
 *
 * revive(): reenergizes flea and resets number of times moved. Returns true if successful, false if its out of bounds
 *
 * dead(): returns true if the flea is out of bounds, false if not
 *
 */

using namespace std;

#include <cmath>
#include "gridFlea.h"

gridFlea::gridFlea() {

    x = 0;
    y = 0;
    xMax = 5;
    yMax = 5;
    startX = 0;
    startY = 0;
    moveMax = 3;
    size = 20;
    reward = 80;
    timesMoved = 0;

}

gridFlea::gridFlea(int newX, int newY, int newSize) {

    timesMoved = 0;

    xMax = newSize;
    yMax = newSize;

    if (abs(newX) > xMax) {

        x = newX % newSize;
        startX = x;

    } else {
        x = newX;
        startX = x;
    }

    if (abs(newY) > yMax) {

        y = newY % newSize;
        startY = y;

    } else {
        y = newY;
        startY = newY;
    }

    moveMax = ((newX * newY) + 3) % 5;

    size = xMax * 2 + yMax * 2;

    reward = size * 4;

}

gridFlea::gridFlea(const gridFlea &oldFlea) {

    x = oldFlea.x;
    y = oldFlea.y;
    xMax = oldFlea.xMax;
    yMax = oldFlea.yMax;
    startX = oldFlea.startX;
    startY = oldFlea.startY;
    moveMax = oldFlea.moveMax;
    size = oldFlea.size;
    reward = oldFlea.reward;
    timesMoved = oldFlea.timesMoved;

}

gridFlea::~gridFlea() {
}

gridFlea &gridFlea::operator=(const gridFlea &oldFlea) {

    x = oldFlea.x;
    y = oldFlea.y;
    xMax = oldFlea.xMax;
    yMax = oldFlea.yMax;
    startX = oldFlea.startX;
    startY = oldFlea.startY;
    moveMax = oldFlea.moveMax;
    size = oldFlea.size;
    reward = oldFlea.reward;
    timesMoved = oldFlea.timesMoved;
    
    return *this;

}

void gridFlea::move(int p) {
    //precondition: flea is active and p is not 0
    if (!isDead && p != 0) {

        if ((x + y) % 2 == 0) p = -p;

        if (x * y % 2 == 0) moveX(p);
        else moveY(p);

        timesMoved++;

        if (timesMoved >= moveMax) isEnergetic = false;

        if (outOfBounds()) isDead = true;

    }
    //postcondition: Flea has moved at least 1 space
}

int gridFlea::value() {
    //precondition: none

    int change;

    if (outOfBounds()) change = 0;
    else change = abs(x - startX) + abs(y - startY);

    return reward * size * change;

    //postcondition: none
}

bool gridFlea::reset() {
    //precondition: flea is not out of bounds
    if (!outOfBounds()) {

        x = startX;
        y = startY;
        return true;

    } else return false;
    //postconditionL flea is reset back to where it started
}

bool gridFlea::revive() {
    //precondition: flea is not out of bounds
    if (!outOfBounds()) {

        isEnergetic = true;
        timesMoved = 0;
        return true;
    } else return false;
    //postcondition: flea is energetic again
}

bool gridFlea::outOfBounds() const {

    return ((abs(x) > xMax) || (abs(y) > yMax));

}

void gridFlea::moveX(int p) {

    if (isEnergetic) x = x + p;

    else {

        if (p > 0) x = x + 1;
        else x = x - 1;
    }
}

void gridFlea::moveY(int p) {

    if (isEnergetic) y = y + p;
    else {

        if (p > 0) y = y + 1;
        else y = y - 1;

    }
}

bool gridFlea::dead() {

    return isDead;

}

/**Implamentation Invariants:
 *
 * move(int p): Moves the flea p squares. Direction is determined by fleas current position and calls moveX or moveY,
 * while magnitude is determined if the flea is energetic or not. It then increases timesMoved by 1
 * and checks to see if it has exceeded moveMax, turning isEnergetic to false if it has,
 * and if its out of bounds, turning isDead true if it has
 *
 * value(): Returns the value of the flea using distance from starting position, the size of the grid, and the initial reward
 * will return 0 if out of bounds.
 *
 * reset(): checks if the flea is out of bounds, if it is not, resets the flea back to startX and startY and returns true
 * otherwise returns false if unsuccessful
 *
 * revive(): checks if the flea is out of bounds, if it is not, sets timesMoved to 0 and sets isEnergetic to true and returns true
 * Otherwise returns false
 *
 * outofBounds(): checks the absolute values of current x and y against Xmax and Ymax to see if the flea is out of bounds.
 * Returns true if it is.
 *
 * moveX(int p): utility method for move(), moving the flea on the x axis.
 * If the flea is not dead, the flea will be moved p spaces if energetic and one space if it is not
 *
 * moveY(): utility method for move(), moving the flea along the y axis.
 * If the flea is not dead, the flea will be moved p spaces if energetic and
 * one space if it is not
 *
 * dead(): returns isDead
 *
*/