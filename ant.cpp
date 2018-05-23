#include "ant.h"

Ant::Ant(QPointF *pos, QString imagePath):
    Unit(pos, imagePath, 75, 75)
{
    this->moveSpeed = 5;
}

Ant::~Ant(){}
