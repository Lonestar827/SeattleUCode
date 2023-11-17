///Jared Callero
///Filename: inFest.h
///5/20/2022

#include "gridFlea.h"

#ifndef INFEST_H
#define INFEST_H

/**Class Invarients:
 * inFest represents an infestation on a board where you can get the highest and lowest value of the fleas on the board
 * Default values defined for constructor
 *
 * The client has to keep track of current size and the current number of active gridfleas
 * by using getSize() and getNumActive() to make sure use of infest doesnt result in data corruption.
 */


class inFest {

public:

    inFest();

    inFest(int x, int y, int z);
    //Precondition: Z is greater then 0

    inFest &operator=(const inFest &src);

    inFest &operator=(inFest&& src) noexcept ;

    inFest(const inFest &src);

    inFest(inFest &&src) noexcept ;

    ~inFest();
    //postcondition: object is deallocated

    void move(int p);
    //Precondition: p is not 0
    //PostCondition: one to all fleas replaced.

    int getMin();
    //precondition: there is at least one flea on the board

    int getMax();
    //precondition: there is at least one flea on the board

    int getSize() const;

    int getNumActive() const;

    bool operator==(const inFest& src) const;

    bool operator<=(const inFest& src) const;

    bool operator>=(const inFest& src) const;

    bool operator<(const inFest& src) const;

    bool operator>(const inFest& src) const;

    inFest operator+=(int num);

    inFest operator++();

    inFest operator++(int num);

    inFest operator-=(int num);

    inFest operator--();

    inFest operator--(int num);

    inFest operator-(int num);

    inFest operator+(int num);

    gridFlea operator[](int index);

private:

    gridFlea *infestation{};
    int size{};
    int numActive{};
    bool isActive{};

    void restock();

    void deepCopy(const inFest &src);

    inFest addFleas(int num);

    inFest removeFleas(int num);

};

#endif