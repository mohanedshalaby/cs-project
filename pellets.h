#ifndef PELLETS_H
#define PELLETS_H
#include "coordinates.h"


class pellets
{
    int counter;

public:
    pellets();
    void decreasecounter();
    int getcounter();
    void setCounter(int counter);
};

// delete pellet

#endif // PELLETS_H
