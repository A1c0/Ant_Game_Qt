#include "harvester.h"
#include <QDebug>

Harvester::Harvester(QPointF *pos):
    Ant(pos, ":/item/ant/ressources_ant_game/ant_static.gif")
{
    this->setCollidable(false);
    this->moveSpeed = 10;
    this->canHarvest = false;
    this->loopPoints();
    this->harvestTime = 15;
    this->isEnnemy = false;
}

void Harvester::harvest()
{
    if(this->harvestTime != 0)
        this->harvestTime--;
    else
    {
        this->setBringBack(true);
        this->canHarvest = false;
        this->harvestTime = 15;
        this->loopPoints();
    }
}

void Harvester::loopPoints()
{
        this->addMovePoint(new QPointF(FSX1_X,FSX1_Y));
        this->addMovePoint(new QPointF(FS_X,FS_Y));
        this->addMovePoint(new QPointF(FSX2_X,FSX2_Y));
        this->addMovePoint(new QPointF(NP_X,NP_Y));
}

void Harvester::setCanHarvest(bool condition)
{
    this->canHarvest = condition;
}

bool Harvester::getBringBack()
{
    return this->bringBack;
}
void Harvester::setBringBack(bool condition)
{
    this->bringBack = condition;
}
bool Harvester::getIsHarvester()
{
    return true;
}
