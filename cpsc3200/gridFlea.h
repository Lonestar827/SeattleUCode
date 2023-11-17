///Jared Callero
///Filename: gridFlea.h
///4/12/2022

#ifndef GRIDFLEA_H
#define GRIDFLEA_H

/**class invarients:
 * gridFlea represents a flea on a grid, with x and y coordinates, a value, a size that indicates grid size, and
 * semi random movement based on if its energetic or active.
 */

class gridFlea {

public:

    gridFlea();

    gridFlea(int newX, int newY, int newSize);

    gridFlea(const gridFlea &oldFlea);

    ~gridFlea();

    gridFlea &operator=(const gridFlea &oldFlea);

    void move(int p);

    int value();

    bool reset();

    bool revive();

    bool dead();

private:

    int x;
    int y;
    int xMax;
    int yMax;
    int startX;
    int startY;
    int size;
    int reward;
    int timesMoved;
    int moveMax;
    bool isEnergetic = true;
    bool isDead = false;

    bool outOfBounds() const;

    void moveX(int p);

    void moveY(int p);

};

#endif //GRIDFLEA_H