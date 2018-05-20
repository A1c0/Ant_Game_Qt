#include "game.h"
#include <QDebug>
#include <typeinfo>
#include <QTimer>

Game::Game(GameModel *model, GameView *view) :
    view(view)
{
    this->model = model;
    view->setControl(this);
    init_item();
}

void Game::init_item()
{
    this->model->addItem(new Item(new QPointF(100, 100), ":/item/ressources_ant_game/rock_1.png", 200, 200));
    this->model->addItem(new Item(new QPointF(500, 100), ":/item/ressources_ant_game/rock_2.png", 100, 100));
    this->model->addItem(new Item(new QPointF(400,300), ":/item/ressources_ant_game/Fourmilière.gif", 100, 100));
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
    Sleeper::sleep(10);
    QPointF *point = new QPointF(600,600);
    this->model->getDataItem().last()->getGraphicData()->setPos(point->rx(),point->ry());
}

void Game::createHarvester()
{
    QPointF * locate = new QPointF(400,200);
    this->model->addItem(new Ant(locate));
    this->view->add_item(this->model->getDataItem().last());
    this->view->update(this->model->getDataItem());
    run_item();
    this->view->update(this->model->getDataItem());
}
