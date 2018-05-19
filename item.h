#ifndef ITEM_H
#define ITEM_H
#include <QString>
#include <QGraphicsPixmapItem>
#include "point.h"

class ItemProp: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    ItemProp(Point *pos, QString imagePath, int xSize, int ySize);
};

class Item
{
public:
    Item(Point *pos, QString imagePath, int xSize = 200, int ySize = 200);
    void setPositions(Point *pos);
    void setPositionsUI(Point * pos, QString imagePath, int xSize, int ySize);
    Point * getPositions();
    ItemProp *getGraphicData() const;

private:
    Point *pos;
    ItemProp * graphicData;
};


#endif // ITEM_H
