#include "franklin.h"
#include "pellets.h"

franklin::franklin() : character(3)
{
    numberOfbullets = 0;
    setStartingCell(coordinates(7, 8));
    setCoordinates(getStartingCell());
}

bool franklin::hasPellets()
{
    if(allPellets.length() > 0)
    {
        return true;
    }

    return false;
}

void franklin::removeOnePellet()
{
    int minimumCounter = 11, index = -1;

    for(int i = 0;  i < allPellets.length() ; i++)
    {
        int counter = allPellets[i].getcounter();

        if(counter < minimumCounter)
        {
            minimumCounter = counter;
            index = i;
        }

    }

    if(index != -1)
    {
        allPellets.remove(index);
    }
}

void franklin::move(int row, int column)
{
    int len = allPellets.length();

    for(int i = len - 1; i > 0 ; i--)
    {
        if(allPellets[i].getcounter() > 0)
        {
            allPellets[i].decreasecounter();
        }

        if(allPellets[i].getcounter() == 0)
        {
            allPellets.remove(i);
        }
    }

    setCoordinates(coordinates(row, column));

}

void franklin::addPellet()
{
    pellets pellet = pellets();
    allPellets.append(pellet);
}


void franklin::addBullet()
{
    numberOfbullets++;
}

void franklin::decreaseBullets()
{
    numberOfbullets--;
}

bool franklin::hasBullet()
{
    if(numberOfbullets > 0)
    {
        return true;
    }

    return false;
}

