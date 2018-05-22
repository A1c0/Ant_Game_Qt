#include "unit.h"
#include <QDebug>

Unit::Unit(QPointF * pos, QString imagePath, int xSize, int ySize):
    Item(pos, imagePath, xSize, ySize)
{
    this->mouvements = new QList<QPointF*>();
    this->canMove = true;
    this->healthPoints = 0;
    this->moveSpeed = 0.2;
    this->attackSpeed = 100;
    this->attackValue = 100;
}

void Unit::move(){
    this->getGraphicData()->setPos(this->mouvements->first()->rx(),this->mouvements->first()->ry());
    this->advance();
}

void Unit::addMovePoint(QPointF* nextPoint)
{
    this->mouvements->append(nextPoint);
}

QList<QPointF*> *Unit::getMovePoints()
{
    return (this->mouvements);
}

void Unit::advance()
{
    QPointF * currentPos = new QPointF(this->getGraphicData()->pos().rx(),this->getGraphicData()->pos().ry());
    QPointF * nextPos = new QPointF(this->mouvements->first()->rx(),this->mouvements->first()->ry());
    qreal newX = std::abs((nextPos->rx() - currentPos->rx()))*this->getMoveSpeed();
    qreal newY = std::abs((nextPos->ry() - currentPos->ry()))*this->getMoveSpeed();
    qDebug() << "currentX = " << currentPos->rx();
    qDebug() << "currentY = " << currentPos->ry();
    qDebug() << "nextX = " << nextPos->rx();
    qDebug() << "nextY = " << nextPos->ry();
    qDebug() << "newX = " << newX;
    qDebug() << "newY = " << newY;
    if(newX > 800)
    {
        newX = 800;
    }
    if(newY > 600)
    {
        newY = 600;
    }
    if(newX < 0)
    {
        newX = 0;
    }
    if(newY < 0)
    {
        newY = 0;
    }
    if(newX  > nextPos->rx())
    {
        newX = nextPos->rx();
    }
    if(newY > nextPos->ry())
    {
        newY = nextPos->ry();
    }

    this->getGraphicData()->setPos(std::round(newX), std::round(newY));
    if( std::round(newX)  == nextPos->rx() && std::round(newY) == nextPos->ry())
    {
        this->mouvements->removeFirst();
    }
  }
