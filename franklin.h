#ifndef FRANKLIN_H
#define FRANKLIN_H

#include <QVector>
#include "character.h"
#include "pellets.h"
#include <QKeyEvent>

class franklin : public character
{
    int numberOfbullets;
    QVector<pellets> allPellets;
public:
    void move(int row, int column);
    franklin();
    bool hasPellets();
    void removeOnePellet();
    void addPellet();
    void addBullet();
    bool hasBullet();
    void decreaseBullets();

};

#endif // FRANKLIN_H
