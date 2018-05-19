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

    Ant *fourmieTest1 = new Ant(new Point(500,300));
    this->model->addItem(fourmieTest1);

    Ant *fourmieTest2 = new Ant(new Point(400,200));
    this->model->addItem(fourmieTest2);

    Ant *f2 = new Ant (new Point(400,400));
    f2->setPositionsUI(new Point(700,500),":/item/ant/ressources_ant_game/ant_static.gif", 75, 75);
    this->model->addItem(f2);

    int x1 = this->model->getDataItem()[6]->getPositions()->getX();
    int y1 = this->model->getDataItem()[6]->getPositions()->getY();

    qDebug() << "la valeur est de x est" << x1 << "et y" << y1;

    //this->view;
    //this->view->update(this->model->getDataItem());
    this->view->update_test(this->model->getDataItem());

}

/*void Game::run_game(){
    bool isComplete = false;
    while (!isComplete) {

        for(int i = 0; i < this->model->getDataItem().length() ; i++)

                {

                    int x = this->model->getDataItem()[6]->getPositions()->getX();

                    int y = this->model->getDataItem()[6]->getPositions()->getY();

                    Point *pos = new Point(x,y);
                    pos->setX(pos->getX() + 1);
                    qDebug() << "babare";
                    this->model->getDataItem()[6]->setPositions(pos);

                    //this->view->update_test(this->model->getDataItem());

                    if(x >= 500){

                        isComplete = true;

                    }

                }

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
        this->view->repaint();
    }
}*/

GameModel * Game::getModel()
{
    return this->model;
}


