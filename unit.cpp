#include "unit.h"

Unit::Unit(Point * pos, QString imagePath, int xSize, int ySize):
    Item(pos, imagePath, xSize, ySize)
{
    QList<Point> *mouvements;
    this->healthPoints = 0;
    this->moveSpeed = 100;
    this->attackSpeed = 100;
    this->attackValue = 100;
}
