#include "map.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QGraphicsItem>
#include <iostream>


map::map()
{
    numberOfRows = numberOfColumns = 0;
    player = franklin();
    firstEnemy = enemy();
    secondEnemy = enemy();
    view = new QGraphicsView;
    scene = new QGraphicsScene;
}

map::map(int numberOfRows, int numberOfColumns, QString fileName)
{
    view = new QGraphicsView;
    scene = new QGraphicsScene;
    player = franklin();
    firstEnemy = enemy(coordinates(13, 6));
    secondEnemy = enemy(coordinates(13, 7));

    this->numberOfColumns = numberOfColumns;
    this->numberOfRows = numberOfRows;

    grid.resize(numberOfRows);
    for(int i = 0 ; i < numberOfRows ; i++)
    {
        grid[i].resize(numberOfColumns);
    }


    fillGrid(fileName);
}

void map::fillGrid(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line = in.readLine();

    int i = 0;
    while (!line.isNull())
    {
        QStringList numbers = line.split(' ');
        for(int j = 0 ; j < numberOfColumns ; j++)
        {
            grid[i][j] = numbers[j].toInt();
            // -1 -> wall
            // -2 -> bullets
            // -3 -> pellets
        }
        i++;
        line = in.readLine();
    }

}

int map::getCell(int row, int col)
{
    return grid[row][col];
}

int map::getNumberOfRows()
{
    return numberOfRows;
}

int map::getNumberOfColumns()
{
    return numberOfColumns;
}

franklin map::getPlayer()
{
    return player;
}

enemy map::getFirstEnemy()
{
    return firstEnemy;
}

enemy map::getSecondEnemy()
{
    return secondEnemy;
}

void map::keyPressEvent(QKeyEvent* event)
{
    qDebug() << "Hello from press";

    int row = player.getCoordinates().getRow();
    int column = player.getCoordinates().getColumn();

    QPixmap streetImage("/Users/mohanedshalaby/Project_cs2/square.png");
    streetImage = streetImage.scaledToWidth(50);
    streetImage = streetImage.scaledToHeight(50);

    QPixmap playerImage("/Users/mohanedshalaby/Project_cs2/vampire-cape.png");
    playerImage = playerImage.scaledToWidth(50);
    playerImage = playerImage.scaledToHeight(50);

    QPixmap wallImage("/Users/mohanedshalaby/Project_cs2/brick-wall.png");
    wallImage = wallImage.scaledToWidth(50);
    wallImage = wallImage.scaledToHeight(50);

    QPixmap enemyImage("/Users/mohanedshalaby/Project_cs2/rock-golem.png");
    enemyImage = enemyImage.scaledToWidth(50);
    enemyImage = enemyImage.scaledToHeight(50);

    QPixmap bulletsImage("/Users/mohanedshalaby/Project_cs2/flail.png");
    bulletsImage = bulletsImage.scaledToWidth(50);
    bulletsImage = bulletsImage.scaledToHeight(50);

    QPixmap pelletsImage("/Users/mohanedshalaby/Project_cs2/spiked-bat.png");
    pelletsImage = pelletsImage.scaledToWidth(50);
    pelletsImage = pelletsImage.scaledToHeight(50);


    boardItems[row][column].setPixmap(streetImage);

    if (event->key() == Qt::Key_Up && grid[row - 1][column] != -1 )

    {
        std::cout<<"helloo"<<std::endl;
        player.move(row - 1, column);
    }
    else if (event->key() == Qt::Key_Down && grid[row + 1][column] != -1)
    {
        player.move(row + 1, column);
    }
    else if (event->key() == Qt::Key_Right && grid[row][column + 1] != -1)
    {
        player.move(row, column + 1);
    }
    else if (event->key() == Qt::Key_Left && grid[row][column - 1] != -1)
    {
        player.move(row, column - 1);
    }

    row = player.getCoordinates().getRow();
    column = player.getCoordinates().getColumn();


    if(firstEnemy.isAlive() == 0 &&  firstEnemy.getCoordinates().getRow() == row && firstEnemy.getCoordinates().getColumn() == column)
    {
        if(player.hasBullet() == true)
        {
            player.decreaseBullets();
            firstEnemy.decreaseLives();
            // TODO :Remove enemy from MAP
        }
        else
        {
            if(player.hasPellets() == false)
            {
                player.decreaseLives();
                player.resetPosition();

                firstEnemy.resetPosition();
                secondEnemy.resetPosition();

                firstEnemy.resetLives(1);
                secondEnemy.resetLives(1);

                if(player.isAlive() == false)
                {
                    // TODO: Close the game
                }
            }
            else
            {
                player.removeOnePellet();
            }
        }
    }

    if(secondEnemy.isAlive() == true &&  secondEnemy.getCoordinates().getRow() == row && secondEnemy.getCoordinates().getColumn() == column)
    {
        if(player.hasBullet() == true)
        {
            player.decreaseBullets();
            secondEnemy.decreaseLives();
            // TODO :Remove enemy from MAP
        }
        else
        {
            if(player.hasPellets() == false)
            {
                player.decreaseLives();
                player.resetPosition();

                firstEnemy.resetPosition();
                secondEnemy.resetPosition();

                firstEnemy.resetLives(1);
                secondEnemy.resetLives(1);

                if(player.isAlive() == false)
                {
                    // TODO: Close the game
                }
            }
            else
            {
                player.removeOnePellet();
            }
        }
    }

    if(grid[row][column] == -2)
    {
        player.addPellet();
    }

    if(grid[row][column] == -3)
    {
        player.addBullet();
    }

    if(firstEnemy.isAlive())
    {
        coordinates coordinate = firstEnemy.getNextPostion();

        int row = coordinate.getRow();
        int column = coordinate.getColumn();

        if(grid[row][column] != -1)
        {
            firstEnemy.setCoordinates(coordinates(row, column));
        }
    }

    if(secondEnemy.isAlive())
    {
        coordinates coordinate = secondEnemy.getNextPostion();

        int row = coordinate.getRow();
        int column = coordinate.getColumn();

        if(grid[row][column] != -1)
        {
            secondEnemy.setCoordinates(coordinates(row, column));
        }
    }


    boardItems[row][column].setPixmap(playerImage);
}
