///Jared Callero
///Filename: gridFlea.h
///5/20/2022

#ifndef GRIDFLEA_H
#define GRIDFLEA_H

/**class invarients:
 * gridFlea represents a flea on a grid, with x and y coordinates, a value, a size that indicates grid size, and
 * semi random movement based on if its energetic or active.
 *
 * Client can keep track of value and if the flea is alive using getValue() and dead().
 */

class gridFlea {

    public:

        gridFlea();

        gridFlea(int newX, int newY, int newSize);

        gridFlea(const gridFlea &oldFlea);

        ~gridFlea();

        gridFlea &operator=(const gridFlea &oldFlea);

        void move(int p);

        void setValue(int num);

        int getValue();

        bool reset();

        bool revive();

        bool dead();

        gridFlea operator+(int num);

        gridFlea operator++();

        gridFlea operator++(int num);

        gridFlea operator+=(int num);

        gridFlea operator-(int num);

        gridFlea operator--();

        gridFlea operator--(int num);

        gridFlea operator-=(int num);


    private:

        int x, xMax, startX, y, yMax, startY, z, size, reward, timesMoved, moveMax;
        bool isEnergetic = true;
        bool isDead = false;
        bool beenOutside = false;

        bool outOfBounds() const;

        bool beenOutsideCheck();

        void moveX(int p);

        void moveY(int p);

        gridFlea addValue(int num);

        gridFlea removeValue(int num);

};

#endif //GRIDFLEA_H