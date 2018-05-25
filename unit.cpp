#include "unit.h"
#include <QDebug>

Unit::Unit(QPointF * pos, QString imagePath, int xSize, int ySize):
    Item(pos, imagePath, xSize, ySize)
{
    this->mouvements = new QList<QPointF*>();
    this->canMove = true;
    this->healthPoints = 100;
    this->canHarvest = false;
    this->moveSpeed = 15;
    this->attackSpeed = 100;
    this->attackValue = 100;
}

Unit::~Unit(){}


void Unit::addMovePoint(QPointF* nextPoint)
{
    this->mouvements->append(nextPoint);
}

QList<QPointF*> *Unit::getMovePoints()
{
    return (this->mouvements);
}

float Unit::getMoveSpeed() const {
    return this->moveSpeed;
}

void Unit::harvest(){}

void Unit::setCanHarvest(bool condition)
{
    this->canHarvest = false;
}

bool Unit::getCanHarvest()
{
    return this->canHarvest;
}

bool Unit::getBringBack()
{
    return this->bringBack;
}
void Unit::setBringBack(bool condition){}

bool Unit::getIsHarvester()
{
    return false;
}

bool Unit::getCanAttack()
{
    return this->canAttack;
}
Unit *Unit::getTarget()
{
    return this->target;
}
void Unit::setTarget(Unit * target)
{
    this->target = target;
}
void Unit::setCanAttack(bool condition)
{
    this->canAttack = condition;
}

float Unit::getHealthPoints()
{
    return this->healthPoints;
}
void Unit::setPath(QList<QPointF*> path){}

bool Unit::getIsEnemy()
{
    return this->isEnemy;
}

void Unit::setIsAlive(bool condition)
{
    this->isAlive = condition;
}

bool Unit::getIsAlive()
{
    return this->isAlive;
}
