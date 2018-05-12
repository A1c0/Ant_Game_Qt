#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QList>
#include "item.h"


class GameModel
{
private:
    QList<Item> dataItem;
    QList<Item> unitItem;
public:
    GameModel();
    void setDataItem(const QList<Item> &value);
    void setUnitItem(const QList<Item> &value);
    void addItem(Item *i);
    void addUnit(Item *i);
    QList<Item> getDataItem() const;
    QList<Item> getUnitItem() const;
};

#endif // GAMEMODEL_H
