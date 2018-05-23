#include "ant.h"

Ant::Ant(QPointF *pos):
    Unit(pos, ":/item/ant/ressources_ant_game/ant_static.gif", 75, 75)
{
    this->moveSpeed = 5;
}
