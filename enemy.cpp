#include "enemy.h"

Enemy::Enemy(QPointF * pos):
    Unit(pos, ":/gif/ressources_ant_game/enemy.gif", 75, 75)
{
    this->mouvements = new QList<QPointF*>();
    QPointF * nest = new QPointF(NP_X, NP_Y);
    this->addMovePoint(nest);
    this->moveSpeed = 1;
    this->isEnnemy = true;
    this->canAttack = false;
    this->canHarvest = false;
    this->setCollidable(true);
}

