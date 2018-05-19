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
   /* QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("B:\\Users\\NATHZN\\Documents\\Ant_Game_Qt-master\\ressources_ant_game\\main_theme.mp3"));
    player->setVolume(100);
    player->play();*/
    this->model->addItem(new Item(new Point(100, 100), ":/item/ressources_ant_game/rock_1.png", 200, 200));
    this->model->addItem(new Item(new Point(500, 100), ":/item/ressources_ant_game/rock_2.png", 100, 100));
    this->model->addItem(new Item(new Point(400,300), ":/item/ressources_ant_game/Fourmilière.gif", 100, 100));

    Ant *fourmieTest = new Ant(new Point(300,300));
    this->model->addItem(fourmieTest);


    this->updateView();

}

void Game::run_game(){
    bool isComplete = false;
        this->updateUnit(this->getModel()->getDataItem().at(4));

        this->getModel()->getDataItem().at(4)->setPositions(new Point(500,500));

        this->updateUnit(this->getModel()->getDataItem().at(4));

        this->view->repaint();
        /*int x = this->model->getDataItem()[3].getPositions()->getX();
        int y = this->model->getDataItem()[3].getPositions()->getY();
        Point *pos = new Point(x,y);
        pos->setX(pos->getX() + 1);
        this->model->getDataItem()[3].setPositions(pos);
        int x2 = this->model->getDataItem()[3].getPositions()->getX();
        int y2 = pos->getY();
        QString msg = QString::number(x2);
        msg.append(";");
        msg.append(QString::number(y2));
        QString title = "yolo";
        this->view->update(this->model->getDataItem());
        if(x >= 500){
            isComplete = true;
        }
        this->view->repaint();*/
}

void Game::change_pos(){
    Point * newpos = new Point(0,0);
    this->getModel()->getDataItem()[4]->setPositions(newpos);
    //this->updateView();
}

GameModel * Game::getModel()
{
    return this->model;
}

GameView * Game::getView(){
    return this->view;
}

bool Game::updateUnit(Item * test){
    this->getView()->getScene()->removeItem(test->getGraphicData());
    this->getView()->getScene()->addItem(test->getGraphicData());
}

void Game::updateView(){
    this->getView()->getScene()->clear();
    foreach(Item* item, this->getModel()->getDataItem())
    {
        Point * updatepos = new Point(0,0);
        updatepos->setX(item->getPositions()->getX());
        updatepos->setY(item->getPositions()->getY());
        qDebug() << updatepos->getX();
        qDebug() << updatepos->getY();
        item->getGraphicData()->setPos(updatepos->getX(),updatepos->getX());
    }

}
