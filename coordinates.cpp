#include "coordinates.h"

coordinates::coordinates()
{
    row = col = -1;
}

coordinates::coordinates(int row, int col)
{
    this->row = row;
    this->col = col;
}

int coordinates::getRow()
{
    return row;
}

int coordinates::getColumn()
{
    return col;
}
