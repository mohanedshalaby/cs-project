#ifndef CHARACTER_H
#define CHARACTER_H


#include "coordinates.h"

class character
{
    coordinates coordinate;
    int lives;
    coordinates startingCell;
public:
    character();
    character(int lives);
    character(int lives, coordinates coordinate);

    int getLives();

    void setCoordinates(coordinates coordinate);
    coordinates getCoordinates();

    void setStartingCell(coordinates coordinate);
    coordinates getStartingCell();

    void resetPosition();
    void resetLives(int lives);

    void decreaseLives();
    bool isAlive();
};

#endif // CHARACTER_H
