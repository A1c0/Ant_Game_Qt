#include "game.h"

Game::Game(GameModel *model, GameView *view) :
    view(view)
{
    this->model = model;
    view->setControl(this);
    init_item();
}

void Game::init_item()
{
    this->model->addItem(new Item(new Point(100, 100), ":/item/ressources_ant_game/rock_1.png", 200, 200));
    this->model->addItem(new Item(new Point(500, 100), ":/item/ressources_ant_game/rock_2.png", 100, 100));
    this->model->addItem(new Item(new Point(400,300), ":/item/ressources_ant_game/Fourmilière.gif", 100, 100));

    Ant *fourmieTest = new Ant(new Point(300,300));
    this->model->addItem(fourmieTest);
    this->view->test();
    this->view->update(this->model->getDataItem());
    /*
    Point *newPos = new Point(300,300);
    newPos->setX(newPos->getX()+100);
    newPos->setY(newPos->getY()+100);
    fourmieTest->setPositions(newPos);
    this->view->repaint();*/
}


