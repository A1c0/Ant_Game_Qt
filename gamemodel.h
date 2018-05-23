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
    QList<QPointF*> pathPointList;
public:
    GameModel();
    void setDataItem(const QList<Item*> &value);
    void addItem(Item *i);
    void addPathPoint(QPointF * p);
    QList<Item*> getDataItem();
};

#endif // GAMEMODEL_H
