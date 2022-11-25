#include "enemy.h"
#include <QtGlobal>

enemy::enemy() : character(2)
{
}

enemy::enemy(coordinates coordinate) : character(2, coordinate)
{
    setStartingCell(coordinate);
    setCoordinates(getStartingCell());
}


coordinates enemy::getNextPostion()
{
    // 0 --> row, 1 --> column
    int RowOrColumn = rand() % 2;
    int pos = rand() % 2;

    if(pos == 0)
    {
        pos = -1;
    }

    coordinates coordinate = getCoordinates();
    int row = coordinate.getRow();
    int column = coordinate.getColumn();

    if(RowOrColumn == 0)
    {
        return coordinates(row + pos, column);
    }
    else
    {
        return coordinates(row, column + pos);
    }
}
