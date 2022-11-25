#include "pellets.h"

pellets::pellets()
{
    this->counter = 10;
}

void pellets::decreasecounter()
{
    counter--;
}

int pellets::getcounter()
{
    return counter;
}

void pellets::setCounter(int counter)
{
    this->counter = counter;
}


