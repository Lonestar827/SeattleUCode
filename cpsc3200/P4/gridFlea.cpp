/**Author: Jared Callero
 *FileName: GridFlea.CS
 *Date:5/20/2022

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
 * getValue(): returns the value of the flea, based off of distance from start, size of grid, and the initial value.
 * will return 0 if out of bounds
 *
 * setValue(int num): sets the value of the gridFlea to the value num.
 *
 * reset(): moves flea back to starting coordinates, returns true if successful, false if its out of bounds.
 *
 * revive(): reenergizes flea and resets number of times moved. Returns true if successful, false if its out of bounds
 *
 * dead(): returns true if the flea is out of bounds, false if not
 *
 *  void operator+=(int num): increases the value of the gridFlea by num
 *
 *  void operator-=(int num): decreases the value of the gridFlea by num
 *
 *  void operator*=(int num): multiplies the value of the gridFlea by num
 *
 *  void operator/=(int num): divides the value of the gridFlea by num
 *
 *  void operator%=(int num): modulates the value of the gridFlea by num
 *
 */

using namespace std;

#include <cmath>
#include "gridFlea.h"

gridFlea::gridFlea() {

    x = 0;
    y = 0;
    z = 5;
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

    z = ( abs(newX) + abs(newY) )/ 2;

    moveMax = ((newX * newY) + 3) % 5;

    size = xMax * 2 + yMax * 2;

    reward = size;

}

gridFlea::gridFlea(const gridFlea &oldFlea) {

    x = oldFlea.x;
    y = oldFlea.y;
    z = oldFlea.z;
    xMax = oldFlea.xMax;
    yMax = oldFlea.yMax;
    startX = oldFlea.startX;
    startY = oldFlea.startY;
    moveMax = oldFlea.moveMax;
    size = oldFlea.size;
    reward = oldFlea.reward;
    timesMoved = oldFlea.timesMoved;
    beenOutside = oldFlea.beenOutside;

}

gridFlea::~gridFlea() {
}

gridFlea &gridFlea::operator=(const gridFlea &oldFlea) {

    x = oldFlea.x;
    y = oldFlea.y;
    z = oldFlea.z;
    xMax = oldFlea.xMax;
    yMax = oldFlea.yMax;
    startX = oldFlea.startX;
    startY = oldFlea.startY;
    moveMax = oldFlea.moveMax;
    size = oldFlea.size;
    reward = oldFlea.reward;
    timesMoved = oldFlea.timesMoved;
    beenOutside = oldFlea.beenOutside;

    return *this;

}

void gridFlea::move(int p) {
    //precondition: flea is active and p is not 0
    //postcondition: Flea has moved at least 1 space

    if (!isDead && p != 0) {

        if ((x + y) % 2 == 0) p = -p;

        if (x * y % 2 == 0) moveX(p);
        else moveY(p);

        timesMoved++;

        if (timesMoved >= moveMax) isEnergetic = false;

        if (outOfBounds()) isDead = beenOutsideCheck();

    }

}

void gridFlea::setValue(int num) {

    reward = num;

}

int gridFlea::getValue() {
    //precondition: none
    //postcondition: none

    int change;

    if (outOfBounds()) change = 0;
    else change = abs(x - startX) + abs(y - startY);

    return reward * size * change;

}

bool gridFlea::reset() {
    //precondition: flea is not out of bounds
    //postcondition: flea is reset back to where it started

    if (!outOfBounds()) {

        x = startX;
        y = startY;
        return true;

    } else return false;

}

bool gridFlea::revive() {
    //precondition: flea is not out of bounds
    //postcondition: flea is energetic again

    if (!outOfBounds()) {

        isEnergetic = true;
        timesMoved = 0;
        return true;

    } else return false;
}

bool gridFlea::outOfBounds() const {

    return ((abs(x) > xMax) || (abs(y) > yMax));

}

bool gridFlea::beenOutsideCheck(){

    if ((abs(x) > xMax + z) || (abs(y) > yMax + z) || beenOutside) return true;
    else {

        beenOutside = !beenOutside;
        return false;

    }

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

gridFlea gridFlea::operator+(int num){

    return addValue(num);

}

gridFlea gridFlea::operator++(){

    return addValue(1);

}

gridFlea gridFlea::operator++(int num){

    gridFlea oldState = *this;

    addValue(num);

    return oldState;

}

gridFlea gridFlea::operator+=(int num) {

    return addValue(num);

}

gridFlea gridFlea::operator-(int num){

    return removeValue(num);

}

gridFlea gridFlea::operator--(){

    return removeValue(1);

}

gridFlea gridFlea::operator--(int num){

    gridFlea oldState = *this;

    removeValue(num);

    return oldState;

}

gridFlea gridFlea::operator-=(int num) {

    return removeValue(num);

}

gridFlea gridFlea::addValue(int num){

    reward += num;

    return *this;

}

gridFlea gridFlea::removeValue(int num) {

    reward -= num;

    return *this;

}



/**Implamentation Invariants:
 *
 * move(int p): Moves the flea p squares. Direction is determined by fleas current position and calls moveX or moveY,
 * while magnitude is determined if the flea is energetic or not. It then increases timesMoved by 1
 * and checks to see if it has exceeded moveMax, turning isEnergetic to false if it has,
 * and if its out of bounds, turning isDead true if it has
 *
 * getValue(): Returns the value of the flea using distance from starting position, the size of the grid, and the initial reward
 * will return 0 if out of bounds.
 *
 * setValue(int num): sets value to num.
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
 * bool beenOutsideCheck(): checks to see if the flea is in z range and toggles dead and beenOutside accordingly.
 * first checks to see if the gridFlea is outside of z range (x/ymax + z) OR if the flea has beenOutide before.
 * If it is, return true. If not, toggle beenOutside and return false;
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
 * gridFlea operator+(int num): calls addValue(num)
 *
 * gridFlea operator+=(int num): calls addValue(num)
 *
 * gridFlea operator++(): calls addValue(1)
 *
 * gridFlea operator++(int num): makes a snapshot of the current state oldState, calls addValue(1), then returns oldState.
 *
 * gridFlea operator-(int num): calls removeValue(num)
 *
 * gridFlea operator-=(int num): calls removeValue(num)
 *
 * gridFlea operator--(): calls removeValue(1)
 *
 * gridFlea operator--(int num): makes a snapshot of the current state oldState, calls removeValue(1), then returns oldState.
 *
 * gridFlea addValue(int num): adds the input to the value and returns the current state
 *
 * gridFlea removeValue(int num): subtracts the input from the current value and returns the current state
 *
*/