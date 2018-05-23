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
public:
    GameModel();
    void setDataItem(const QList<Item*> &value);
    void addItem(Item *i);
    void addUnit(Unit *i);
    QList<Item*> getDataItem();
    QList<Unit*> getDataUnit();
};

#endif // GAMEMODEL_H
