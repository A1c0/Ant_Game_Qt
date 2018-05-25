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
    QList<QPointF*> pathPointList;
    int waveNumber;
    bool encounterSound;
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
    void addPathPoint(QPointF * p);
    void clearPathPoints();
    QList<QPointF*> getPathPointList();
    void setWaveNumber(int number);
    int getWaveNumber();
    bool getEncounterSound();
    void setEncounterSound(bool condition);
};

#endif // GAMEMODEL_H
