///Jared Callero
///Filename: inFest.h
///4/12/2022
///version 1

#include "gridFlea.h"

#ifndef INFEST_H
#define INFEST_H

/**Class Invarients:
 * inFest represents an infestation on a board where you can get the highest and lowest value of the fleas on the board
 * Default values defined for constructor
 */


class inFest {

public:

    inFest();

    inFest(int x, int y, int z);
    //Precondition: Z is greater then 0

    inFest &operator=(const inFest &src);

    inFest(const inFest &src);

    inFest(inFest &&src);

    ~inFest();
    //postcondition: object is deallocated

    void move(int p);
    //Precondition: p is not 0
    //PostCondition: one to all fleas replaced.

    int getMin();
    //precondition: there is at least one flea on the board

    int getMax();
    //precondition: there is at least one flea on the board

private:

    gridFlea *infestation;
    int size;
    int numActive;

    void restock();

    void deepCopy(const inFest &src);

};

#endif