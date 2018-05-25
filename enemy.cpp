#include "enemy.h"

Enemy::Enemy(QPointF * pos):
    Unit(pos, ":/gif/ressources_ant_game/enemy.gif", 75, 75)
{
    this->mouvements = new QList<QPointF*>();
    QPointF * nest = new QPointF(NP_X, NP_Y);
    this->addMovePoint(nest);
    this->moveSpeed = 0.8;
    this->isEnemy = true;
    this->canAttack = false;
    this->canHarvest = false;
    this->healthPoints = 500;
    this->attackSpeed = 0.1;
    this->attackValue = 50;
    this->isAlive = true;
}

