#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QList>
#include "item.h"
#include "Unit.h"
#include "Ant.h"


class GameModel
{
private:
    QList<Item*> dataItem;
    QList<Unit*> dataUnit;
    int foodSupply;
    QPointF * foodSupplyPos;
    QPointF * nestPos;
public:
    GameModel();
    void setDataItem(const QList<Item*> &value);
    void addItem(Item *i);
    void addUnit(Unit *i);
    QList<Item*> getDataItem();
    QList<Unit*> getDataUnit();
    int getFoodSupply();
    void addFood(int someFood);
    QPointF *getfoodPos();
    QPointF *getNestPos();
};

#endif // GAMEMODEL_H
