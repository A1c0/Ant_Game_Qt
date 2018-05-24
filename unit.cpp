#include "unit.h"
#include <QDebug>

Unit::Unit(QPointF * pos, QString imagePath, int xSize, int ySize):
    Item(pos, imagePath, xSize, ySize)
{
    this->mouvements = new QList<QPointF*>();/*
    this->mouvements->append(new QPointF(200,200));
    this->mouvements->append(new QPointF(600,600));
    this->mouvements->append(new QPointF(600,200));
    this->mouvements->append(new QPointF(600,600));
    this->mouvements->append(new QPointF(1000,200));
    this->mouvements->append(new QPointF(600,600));
    this->mouvements->append(new QPointF(1000,600));
    this->mouvements->append(new QPointF(600,600));
    this->mouvements->append(new QPointF(1000,1000));
    this->mouvements->append(new QPointF(600,600));
    this->mouvements->append(new QPointF(600,1000));
    this->mouvements->append(new QPointF(600,600));
    this->mouvements->append(new QPointF(200,1000));
    this->mouvements->append(new QPointF(600,600));
    this->mouvements->append(new QPointF(200,600));
    this->mouvements->append(new QPointF(600,600));*/
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

void Unit::setPath(QList<QPointF*> path){}
void Unit::loopPoints(){}
