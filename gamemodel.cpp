#include "gamemodel.h"

GameModel::GameModel()
{
    dataItem = *(new QList<Item*>());
    dataUnit = *(new QList<Unit*>());
}

QList<Item *> GameModel::getDataItem()
{
    return dataItem;
}

QList<Unit *> GameModel::getDataUnit()
{
    return dataUnit;
}

void GameModel::setDataItem(const QList<Item*> &value)
{
    dataItem = value;
}

void GameModel::addItem(Item *i)
{
    dataItem << i;
}

void GameModel::addUnit(Unit *i)
{
    dataUnit << i;
}

