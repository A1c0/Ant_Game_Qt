#include "gamemodel.h"

GameModel::GameModel()
{
    dataItem = *(new QList<Item*>());
}

QList<Item *> GameModel::getDataItem()
{
    return dataItem;
}

void GameModel::setDataItem(const QList<Item*> &value)
{
    dataItem = value;
}

void GameModel::addItem(Item *i)
{
    dataItem << i;
}

void GameModel::addPathPoint(QPointF *p)
{
    pathPointList << p;
}
