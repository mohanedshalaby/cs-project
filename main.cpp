#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QDebug>
#include "map.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    map game = map(15, 15, "/Users/mohanedshalaby/Project_cs2/Board.txt");

    game.view->setFixedSize(900, 900);
    game.view->setWindowTitle("GTA");
    QBrush brush(Qt::black);
    game.view->setBackgroundBrush(brush);

    int numberOfRows = game.getNumberOfRows();
    int numberOfColumns = game.getNumberOfColumns();

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

    coordinates playerCoordinate = game.getPlayer().getStartingCell();
    coordinates firstEnemyCoordinate = game.getFirstEnemy().getStartingCell();
    coordinates secondEnemyCoordinate = game.getSecondEnemy().getStartingCell();

    for (int i = 0; i < numberOfRows ; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {

            // Set Image
            if (game.getCell(i, j) == -1)
            {
                game.boardItems[i][j].setPixmap(wallImage);
            }
            else if(game.getCell(i, j) == -2)
            {
                game.boardItems[i][j].setPixmap(bulletsImage);
            }
            else if(game.getCell(i, j) == -3)
            {
                game.boardItems[i][j].setPixmap(pelletsImage);
            }
            else
            {
                game.boardItems[i][j].setPixmap(streetImage);
            }


            if(playerCoordinate.getRow() == i && playerCoordinate.getColumn() == j)
            {
                game.boardItems[i][j].setPixmap(playerImage);
            }
            else if(firstEnemyCoordinate.getRow() == i && firstEnemyCoordinate.getColumn() == j)
            {
                game.boardItems[i][j].setPixmap(enemyImage);
            }
            else if(secondEnemyCoordinate.getRow() == i && secondEnemyCoordinate.getColumn() == j)
            {
                game.boardItems[i][j].setPixmap(enemyImage);
            }

            // Set Position
            game.boardItems[i][j].setPos(50 + j * 50, 50 + i * 50);

            // Add to the Scene
            game.scene->addItem(&game.boardItems[i][j]);
        }
    }

    game.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    game.setFocus();

    game.view->setScene(game.scene);
    game.view->show();

    return a.exec();
}
