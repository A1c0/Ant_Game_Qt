#include "gamemodel.h"

GameModel::GameModel()
{
    dataItem = *(new QList<Item*>());
}

QList<Item *> GameModel::getDataItem() const
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

