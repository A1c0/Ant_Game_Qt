#ifndef ITEM_H
#define ITEM_H
#include <QString>
#include <QGraphicsPixmapItem>
#include "path.h"

class ItemProp: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    ItemProp(QPointF * pos, QString imagePath, int xSize, int ySize);
};

class Item
{
public:
    Item(QPointF *pos, QString imagePath, int xSize = 200, int ySize = 200);
    void setPositions(QPointF *pos);
    ItemProp *getGraphicData();
    bool getCanMove();
    QPointF * getPos();
    virtual void move();
    virtual void addMovePoint(QPointF * nextPoint);

protected:
    QPointF *pos;
    ItemProp * graphicData;
    bool canMove;
};


#endif // ITEM_H
