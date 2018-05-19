#ifndef ITEM_H
#define ITEM_H
#include <QString>
#include <QGraphicsPixmapItem>

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
    ItemProp *getGraphicData() const;

private:
    QPointF *pos;
    ItemProp * graphicData;
};


#endif // ITEM_H
