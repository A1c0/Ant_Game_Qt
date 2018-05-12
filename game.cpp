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
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("B:\\Users\\NATHZN\\Documents\\Ant_Game_Qt-master\\ressources_ant_game\\main_theme.mp3"));
    player->setVolume(100);
    player->play();
    this->model->addItem(new Item(new Point(100, 100), ":/item/ressources_ant_game/rock_1.png", 200, 200));
    this->model->addItem(new Item(new Point(500, 100), ":/item/ressources_ant_game/rock_2.png", 100, 100));
    this->model->addItem(new Item(new Point(400,300), ":/item/ressources_ant_game/Fourmilière.gif", 100, 100));

    Ant *fourmieTest = new Ant(new Point(300,300));
    this->model->addUnit(fourmieTest);
    this->view->update(this->model->getDataItem());
    this->view->update(this->model->getUnitItem());

}

void Game::run_game(){
    bool isComplete = false;
    while (!isComplete) {
        for(int i = 0; i < this->model->getUnitItem().length(); i++)
        {
            int x = this->model->getUnitItem()[i].getPositions()->getX();
            int y = this->model->getUnitItem()[i].getPositions()->getY();
            Point *pos = new Point(x,y);
            pos->setX(pos->getX() + 1);
            this->model->getUnitItem()[i].setPositions(pos);
            this->view->update(this->model->getUnitItem());
            if(x >= 500){
                isComplete = true;
            }
        }
        this->view->repaint();
    }

}


