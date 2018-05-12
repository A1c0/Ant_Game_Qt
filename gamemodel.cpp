#include "gamemodel.h"

GameModel::GameModel()
{
    dataItem = *(new QList<Item>()); //static elements
    unitItem = *(new QList<Item>());//units

}

QList<Item> GameModel::getDataItem() const
{
    return dataItem;
}

QList<Item> GameModel::getUnitItem() const
{
    return dataItem;
}

void GameModel::setDataItem(const QList<Item> &value)
{
    dataItem = value;
}

void GameModel::addItem(Item *i)
{
    dataItem << *i;
}

void GameModel::addUnit(Item *i)
{
    unitItem << *i;
}

void GameModel::setUnitItem(const QList<Item> &value)
{
    unitItem = value;
}

