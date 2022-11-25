#ifndef MAP_H
#define MAP_H

#include <QVector>
#include "franklin.h"
#include "enemy.h"
#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "qobject.h"

class map : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int numberOfRows, numberOfColumns;
    QVector<QVector<int> > grid;
    franklin player;
    enemy firstEnemy;
    enemy secondEnemy;
public:
    map();
    map(int numberOfRows, int numOfColumns, QString fileName);

    void fillGrid(QString fileName);
    int getCell(int row, int col);
    int getNumberOfRows();
    int getNumberOfColumns();
    franklin getPlayer();
    enemy getFirstEnemy();
    enemy getSecondEnemy();

    QGraphicsView *view;
    QGraphicsScene *scene;
    QGraphicsPixmapItem boardItems[15][15];
public slots:
    void keyPressEvent(QKeyEvent* event);
};

#endif // MAP_H
