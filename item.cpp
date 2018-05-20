#include "item.h"
#include <QPointF>

ItemProp::ItemProp(QPointF * pos, QString imagePath, int xSize, int ySize)
{
    setPos(pos->rx(), pos->ry());
    // drew the rect
    QPixmap img(imagePath);

    QPixmap newPixmap = img.scaled(QSize(xSize,ySize),  Qt::KeepAspectRatio);
    setPixmap(QPixmap(newPixmap));
    setTransformOriginPoint(50,50);
    setRotation(0);
}


Item::Item(QPointF * pos, QString imagePath, int xSize, int ySize)
{
    this->pos = pos;
    this->graphicData = new ItemProp(pos, imagePath, xSize, ySize);
}

ItemProp * Item::getGraphicData() const
{
    return graphicData;
}
