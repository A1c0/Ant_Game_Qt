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
    /*QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("B:\\Users\\NATHZN\\Documents\\Ant_Game_Qt-master\\ressources_ant_game\\main_theme.mp3"));
    player->setVolume(100);
    player->play();*/
    this->model->addItem(new Item(new Point(100, 100), ":/item/ressources_ant_game/rock_1.png", 200, 200));
    this->model->addItem(new Item(new Point(500, 100), ":/item/ressources_ant_game/rock_2.png", 100, 100));
    this->model->addItem(new Item(new Point(400,300), ":/item/ressources_ant_game/Fourmilière.gif", 100, 100));

    Ant *fourmieTest = new Ant(new Point(300,300));
    this->model->addItem(fourmieTest);

    Ant *f2 = new Ant (new Point(100,400));
    f2->setPositionsUI(new Point(200,500),":/item/ant/ressources_ant_game/ant_static.gif", 75, 75);
    this->model->addItem(f2);

    this->model->addItem(new Item(new Point(600, 500), ":/item/ressources_ant_game/rock_2.png", 100, 100));

    int x1 = this->model->getDataItem()[4]->getPositions()->getX();
    int y1 = this->model->getDataItem()[4]->getPositions()->getY();

    qDebug() << "la valeur est de x est" << x1 << "et y" << y1;

    //this->view->update_test(this->model->getDataItem());

}

void Game::run_game(){
    int destination_x = 600;
    //int destination_y = 100;
    //int foo[this->model->getDataItem().size()][2] = {{},{}};
    int tab_x[this->model->getDataItem().size()] = {};
    //int tab_y[this->model->getDataItem().size()] = {};
    int x = this->model->getDataItem()[4]->getPositions()->getX();
    int y = this->model->getDataItem()[4]->getPositions()->getY();
    Point *pos = new Point(x,y);

    bool isComplete_x = false;
    //bool isComplete_y = false;

    while (!isComplete_x) {

            pos->setX(pos->getX() + 100);
            //pos->setY(pos->getY() + 100);
            qDebug() << "position de x avant le for:" << pos->getX();

            for(int i = 0; i < this->model->getDataItem().size(); i++)
            {
                tab_x[i] = this->model->getDataItem()[i]->getPositions()->getX();

                if(pos->getX() == tab_x[i] && pos->getX() != destination_x){
                    pos->setX(pos->getX() + 100);
                    qDebug() << "(1) position de x quand != destination et == tab[i]:" << pos->getX();
                }
                else if(pos->getX() == tab_x[i] && pos->getX() == destination_x)
                {
                    pos->setX(pos->getX() - 100);
                    qDebug() << "position de x == destination et == tab[i]:" << pos->getX();
                    this->model->getDataItem()[4]->setPositionsUI(pos,":/item/ant/ressources_ant_game/ant_static.gif", 75, 75);
                    this->view->update_test(this->model->getDataItem());
                    isComplete_x = true;
                }

                if(isComplete_x != false){
                    if(pos->getX() != tab_x[i] && pos->getX() != destination_x){
                        pos->setX(pos->getX() + 100);
                        qDebug() << "position de x:" << pos->getX();
                    }
                    else if(pos->getX() != tab_x[i] && pos->getX() == destination_x)
                    {
                        this->model->getDataItem()[4]->setPositionsUI(pos,":/item/ant/ressources_ant_game/ant_static.gif", 75, 75);
                        this->view->update_test(this->model->getDataItem());
                        isComplete_x = true;
                    }
                }/*else{
                    qDebug() << "On est dans les clous en abscisses";
                }*/

            }
    }

    /*while (!isComplete_y) {

            for(int i = 0; i < this->model->getDataItem().size(); i++)
            {
                tab_y[i] = this->model->getDataItem()[i]->getPositions()->getY();

                if(pos->getY() == tab_y[i] && pos->getY() != destination_y){
                    pos->setY(pos->getY() + 100);
                    qDebug() << "(1) position de y quand != destination et == tab[i]:" << pos->getY();
                }
                else if(pos->getY() == tab_y[i] && pos->getY() == destination_y)
                {
                    pos->setY(pos->getY() - 100);
                    qDebug() << "position de y == destination et == tab[i]:" << pos->getY();
                    //this->model->getDataItem()[4]->setPositionsUI(pos,":/item/ant/ressources_ant_game/ant_static.gif", 75, 75);
                    //this->view->update_test(this->model->getDataItem());
                    isComplete_y = true;
                }

                if(isComplete_y != false){
                    if(pos->getY() != tab_y[i] && pos->getY() != destination_y){
                        pos->setY(pos->getY() + 100);
                        qDebug() << "position de y:" << pos->getY();
                    }
                    else if(pos->getY() != tab_y[i] && pos->getY() == destination_y)
                    {
                        //this->model->getDataItem()[4]->setPositionsUI(pos,":/item/ant/ressources_ant_game/ant_static.gif", 75, 75);
                        //this->view->update_test(this->model->getDataItem());
                        isComplete_y = true;
                    }
                }else{
                    qDebug() << "On est dans les clous en ordonnées";
                }

            }

    }

    if(isComplete_x == true && isComplete_y == true){
        this->model->getDataItem()[4]->setPositionsUI(pos,":/item/ant/ressources_ant_game/ant_static.gif", 75, 75);
        this->view->update_test(this->model->getDataItem());
    }*/
}

GameModel * Game::getModel()
{
    return this->model;
}


