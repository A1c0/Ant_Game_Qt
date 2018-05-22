#include "unit.h"

Unit::Unit(QPointF * pos, QString imagePath, int xSize, int ySize):
    Item(pos, imagePath, xSize, ySize)
{
    this->mouvements = new QList<QPointF*>();
    this->canMove = true;
    this->healthPoints = 0;
    this->moveSpeed = 100;
    this->attackSpeed = 100;
    this->attackValue = 100;
}

void Unit::move(){
    this->getGraphicData()->setPos(this->mouvements->first()->rx(),this->mouvements->first()->ry());
    this->mouvements->removeFirst();
}

void Unit::addMovePoint(QPointF* nextPoint)
{
    this->mouvements->append(nextPoint);
}
