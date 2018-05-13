#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QList>
#include "item.h"


class GameModel
{
private:
    QList<Item> dataItem;
public:
    GameModel();
    void setDataItem(const QList<Item> &value);
    void addItem(Item *i);
    QList<Item> getDataItem() const;
};

#endif // GAMEMODEL_H
