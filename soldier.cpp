#include "soldier.h"
#include <QDebug>

Soldier::Soldier(QPointF *pos):
    Ant(pos, ":/gif/ressources_ant_game/ant_soldier.png")
{
    this->setCollidable(true);
    this->moveSpeed = 5;
    this->canHarvest = false;
    this->isEnemy = false;
    this->canAttack = false;
    this->healthPoints = 1000;
    this->attackSpeed = 0.1;
    this->attackValue = 50;
    this->setIsAlive(true);
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

Soldier::~Soldier(){
}

