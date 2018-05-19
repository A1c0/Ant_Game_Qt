#include "game.h"
#include <QDebug>
#include <typeinfo>

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
}


void Game::run_item()
{


}

void Game::createHarvester()
{
    QPointF * locate = new QPointF(rand(),rand());
    this->model->addItem(new Ant(locate));
    this->view->update(this->model->getDataItem());
}
