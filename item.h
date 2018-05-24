#ifndef ITEM_H
#define ITEM_H
#include <QString>
#include <QGraphicsPixmapItem>
#include "constant.h"

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
    void setCollidable(bool condition);
    bool getIsCollidable();

protected:
    QPointF *pos;
    ItemProp * graphicData;
    bool canMove;
    bool canCollide;
};


#endif // ITEM_H
