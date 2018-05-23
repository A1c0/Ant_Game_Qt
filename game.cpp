#include "game.h"
#include <QDebug>
#include <typeinfo>
#include <QTimer>

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
    this->connect(this->view, SIGNAL(newPoint(QPointF*)), this, SLOT(addPathPoint(QPointF*)));
}

void Game::init_item()
{
    this->model->addItem(new Item(new QPointF(100, 100), ":/item/ressources_ant_game/rock_1.png", 200, 200));
    this->model->addItem(new Item(new QPointF(500, 100), ":/item/ressources_ant_game/rock_2.png", 100, 100));
    this->model->addItem(new Item(new QPointF(400,300), ":/item/ressources_ant_game/Fourmilière.gif", 100, 100));
    this->model->addItem((new Ant(this->model->getDataItem()[2]->getPos())));
    this->view->update(this->model->getDataItem());
    foreach (Item * item, this->model->getDataItem())
    {
        this->view->add_item(item);
    }
}


void Game::run_item()
{
    QPointF * locate = new QPointF(400,200);
    this->model->addItem(new Ant(locate));
    this->view->add_item(this->model->getDataItem().last());
    this->view->update(this->model->getDataItem());
    QPointF *point = new QPointF(600,600);

    this->model->getDataItem().last()->getGraphicData()->setPos(point->rx(),point->ry());
}

void Game::createHarvester()
{
    QPointF * locate = new QPointF(400,200);
    this->model->addItem(new Ant(locate));
    this->view->add_item(this->model->getDataItem().last());
    this->view->update(this->model->getDataItem());
}


void Game::mainProcess()
{
    foreach (Item* item, this->model->getDataItem()) {
        if(item->getCanMove())
        {
            if(item->getMovePoints()->empty())
                item->addMovePoint(new QPointF(100,100));
            if(item->getMovePoints()->length() <= 1)
                item->addMovePoint(new QPointF(500,100));
            if(item->getMovePoints()->length() <= 2)
                item->addMovePoint(new QPointF(500,500));
            if(item->getMovePoints()->length() <= 3)
                item->addMovePoint(new QPointF(100,500));
            }
            item->advance();
        }
}
void Game::update(){
    this->view->update(this->model->getDataItem());
}

void Game::addPathPoint(QPointF * p) {
    model->addPathPoint(p);
}
