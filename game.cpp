#include "game.h"
#include <QDebug>
#include <typeinfo>
#include <QTimer>
#include <QtMath>
#include <math.h>
#include "harvester.h"
Game::Game(GameModel *model, GameView *view) :
    view(view)
{
    QTimer *timer1 = new QTimer(this);
    this->connect(timer1, SIGNAL(timeout()), this, SLOT(mainProcess()));
    QTimer *timer2 = new QTimer(this);
    this->connect(timer2, SIGNAL(timeout()), this, SLOT(update()));
    this->model = model;
    view->setControl(this);
    timer1->setInterval(15);
    timer2->setInterval(15);
    init_item();
    timer1->start();
    timer2->start();
}

void Game::init_item()
{
    this->model->addItem(new Item(new QPointF(100, 100), ":/item/ressources_ant_game/rock_1.png", 200, 200));
    this->model->addItem(new Item(new QPointF(500, 100), ":/item/ressources_ant_game/rock_2.png", 100, 100));
    this->model->addItem(new Item(this->model->getNestPos(), ":/item/ressources_ant_game/Fourmilière.gif", 100, 100));
    this->model->addItem(new Item(this->model->getfoodPos(), ":/item/ressources_ant_game/sugar.png", 100, 100));
    this->model->addItem(new Item(new QPointF(400,800), ":/item/ressources_ant_game/Feuille_1.gif", 100, 100));
    this->model->addItem(new Item(new QPointF(1500,300), ":/item/ressources_ant_game/Feuille_2.gif", 100, 100));
    this->model->addItem(new Item(new QPointF(1300,100), ":/item/ressources_ant_game/Feuille_2.gif", 100, 100));
    this->model->addItem(new Item(new QPointF(950,230), ":/item/ressources_ant_game/Feuille_1.gif", 100, 100));
    this->model->addItem(new Item(new QPointF(360,200), ":/item/ressources_ant_game/Feuille_2.gif", 100, 100));
    this->model->addUnit((new Harvester(new QPointF(600,600))));
    this->view->foodDisplay(this->model->getFoodSupply());
    this->view->update(this->model->getDataItem());
    this->view->update(this->model->getDataUnit());
    foreach (Item * item, this->model->getDataItem())
    {
        this->view->add_item(item);
    }
    foreach (Unit * unit, this->model->getDataUnit())
    {
        this->view->add_item(unit);
    }
}


void Game::run_item()
{

}

void Game::createHarvester()
{
    if(this->model->getFoodSupply() >= 50)
    {
        this->model->addFood(-50);
        this->model->addUnit(new Harvester(this->model->getNestPos()));
        this->view->add_item(this->model->getDataUnit().last());
        this->view->update(this->model->getDataUnit());
    }
    else
    {

    }
}


void Game::mainProcess()
{
    foreach (Unit* unit, this->model->getDataUnit()) {
        if(unit->getMovePoints()->size() != 0)
            this->advance(unit);
    }
    this->view->foodDisplay(this->model->getFoodSupply());
}
void Game::update(){
    this->view->update(this->model->getDataUnit());
}


void Game::advance(Unit * unit)
{
    QPointF * currentPos = new QPointF(unit->getGraphicData()->pos().rx(), unit->getGraphicData()->pos().ry());
    if(unit->getMovePoints()->size() != 0)
    {
        QPointF * nextPos = new QPointF(unit->getMovePoints()->first()->rx(),unit->getMovePoints()->first()->ry());
        qreal newX = (nextPos->rx() - currentPos->rx());
        qreal newY = (nextPos->ry() - currentPos->ry());
        if(qFabs(newX) > unit->getMoveSpeed()  && newX > 0)
        {
            newX = unit->getMoveSpeed();
        }
        if(qFabs(newX) > unit->getMoveSpeed() && newX < 0)
        {
            newX = - unit->getMoveSpeed();
        }
        if(qFabs(newY) > unit->getMoveSpeed() && newY > 0)
        {
            newY = unit->getMoveSpeed();
        }
        if(qFabs(newY) > unit->getMoveSpeed() && newY < 0)
        {
            newY = - unit->getMoveSpeed();
        }

        if(newX + currentPos->rx() > (this->view->getSceneWidth() - 100))
        {
            newX = 0;
            unit->getMovePoints()->removeFirst();
        }
        if(newY + currentPos->ry() > (this->view->getSceneHeight()- 100))
        {
            newY = 0;
            unit->getMovePoints()->removeFirst();
        }
        if(newX + currentPos->rx() < 0)
        {
            newX = 0;
            unit->getMovePoints()->removeFirst();
        }
        if(newY + currentPos->ry() < 0)
        {
            newY = 0;
            unit->getMovePoints()->removeFirst();
        }
        qreal rotationFactor = qAcos(( 10 * newY ) / ( qSqrt( 10 * 10 ) * qSqrt( ( newX * newX ) + ( newY * newY ))));
        rotationFactor *= 180;
        rotationFactor /= M_PI;
        if(newX > 0)
        {
            rotationFactor += 180;
            if(newY > 0)
                rotationFactor += 90;
            else if(newY < 0)
                rotationFactor -= 90;
        }
        if(qFabs(currentPos->rx() - nextPos->rx()) < unit->getMoveSpeed() && qFabs(currentPos->ry() - nextPos->ry()) < unit->getMoveSpeed())
        {
            unit->getGraphicData()->setPos(nextPos->rx(), nextPos->ry());
            if(rotationFactor == rotationFactor)
                unit->getGraphicData()->setRotation(rotationFactor);
            unit->getMovePoints()->removeFirst();
        }
        else
        {
            unit->getGraphicData()->setPos(newX + currentPos->rx(), newY + currentPos->ry());
            if(rotationFactor == rotationFactor)
                unit->getGraphicData()->setRotation(rotationFactor);
        }
    }

  }
