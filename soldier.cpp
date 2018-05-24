#include "soldier.h"
#include <QDebug>

Soldier::Soldier(QPointF *pos):
    Ant(pos, ":/gif/ressources_ant_game/ant_soldier.png")
{
    this->setCollidable(true);
    this->moveSpeed = 10;
    this->canHarvest = false;
    this->isEnnemy = false;
    this->canAttack = false;
    //'qDebug() << this->mouvements->last()->rx();
}

void Soldier::setPath(QList<QPointF*> path)
{
    if(path.size() != 0)
    {
        foreach (QPointF * points, path) {
            this->addMovePoint(points);
        }
        this->addMovePoint(new QPointF(NP_X,NP_Y));
    }
}

void Soldier::loopPoints()
{

}
