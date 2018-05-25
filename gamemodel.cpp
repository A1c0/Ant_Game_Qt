#include "gamemodel.h"

GameModel::GameModel()
{
    dataItem = *(new QList<Item*>());
    dataUnit = *(new QList<Unit*>());
    foodSupplyPos = new QPointF(FS_X,FS_Y);
    nestPos = new QPointF(NP_X,NP_Y);
    foodSupply = 200;
    waveNumber = 0;
    this->encounterSound = false;
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

int GameModel::getFoodSupply(){
    return this->foodSupply;
}

void GameModel::addFood(int someFood){
  this->foodSupply += someFood;
}

QPointF * GameModel::getfoodPos(){
    return this->foodSupplyPos;
}

QPointF * GameModel::getNestPos(){
    return this->nestPos;
}

void GameModel::addPathPoint(QPointF *p)
{
    pathPointList << p;
}

QList<QPointF*> GameModel::getPathPointList()
{
    return this->pathPointList;
}

void GameModel::clearPathPoints()
{
    if(this->pathPointList.size() != 0)
    {
        foreach (QPointF * points, this->pathPointList)
        {
            this->pathPointList.removeAll(points);
        }
    }
}

void GameModel::setWaveNumber(int number)
{
    this->waveNumber += number;
}
int GameModel::getWaveNumber()
{
    return this->waveNumber;
}
bool GameModel::getEncounterSound()
{
    return this->encounterSound;
}
void GameModel::setEncounterSound(bool condition)
{
    this->encounterSound = condition;
}
