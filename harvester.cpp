#include "harvester.h"

Harvester::Harvester(QPointF *pos):
    Ant(pos, ":/item/ant/ressources_ant_game/ant_static.gif")
{
    this->moveSpeed = 5;
    this->canHarvest = true;
    this->loopPoints();
}

void Harvester::harvest()
{

}

void Harvester::loopPoints()
{
    if(this->mouvements->size() == 0)
    {
        this->addMovePoint(new QPointF(FSX1_X,FSX1_Y));
        this->addMovePoint(new QPointF(FS_X,FS_Y));
        this->addMovePoint(new QPointF(FSX2_X,FSX2_Y));
        this->addMovePoint(new QPointF(NP_X,NP_Y));
    }
}
