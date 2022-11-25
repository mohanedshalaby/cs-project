#include "character.h"

character::character()
{
    lives = 0;
    coordinate = coordinates();
}

character::character(int lives)
{
    this->lives = lives;
    coordinate = coordinates();
}

character::character(int lives, coordinates coordinate)
{
    this->lives = lives;
    this->coordinate = coordinate;
}

void character::decreaseLives()
{
    lives--;
}

int character::getLives()
{
    return lives;
}

bool character::isAlive()
{
    if(lives > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

coordinates character::getCoordinates()
{
    return coordinate;
}

void character::setCoordinates(coordinates coordinate)
{
    this->coordinate = coordinate;
}

void character::setStartingCell(coordinates startingCell)
{
    this->startingCell = startingCell;
}

coordinates character::getStartingCell()
{
    return startingCell;
}

void character::resetPosition()
{
    coordinate = startingCell;
}

void character::resetLives(int lives)
{
    this->lives = lives;
}

