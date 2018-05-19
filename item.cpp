#include "item.h"

ItemProp::ItemProp(Point *pos, QString imagePath, int xSize, int ySize)
{
    setPos(pos->getX(), pos->getY());
    // drew the rect
    QPixmap img(imagePath);

    QPixmap newPixmap = img.scaled(QSize(xSize,ySize),  Qt::KeepAspectRatio);
    setPixmap(QPixmap(newPixmap));
    setTransformOriginPoint(50,50);
    setRotation(0);
}


Item::Item(Point * pos, QString imagePath, int xSize, int ySize)
{
    this->pos = pos;
    this->graphicData = new ItemProp(pos, imagePath, xSize, ySize);
}

ItemProp *Item::getGraphicData() const
{
    return graphicData;
}

void Item::setPositions(Point *pos){
    this->pos = pos;
}

void Item::setPositionsUI(Point * pos, QString imagePath, int xSize, int ySize){
    this->pos = pos;
    this->graphicData = new ItemProp(pos, imagePath, xSize, ySize);
}

Point * Item::getPositions(){
    return this->pos;
}
