#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class enemy : public character
{


public:
    enemy();
    enemy(coordinates coordinate);
    coordinates getNextPostion();
};

#endif // ENEMY_H
