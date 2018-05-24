#ifndef ENEMY_H
#define ENEMY_H

#include "unit.h"

#include <QList>

class Enemy : public Unit
{
public:
    Enemy(QPointF *pos);
    ~Enemy();

protected:


};

#endif // ENEMY_H
