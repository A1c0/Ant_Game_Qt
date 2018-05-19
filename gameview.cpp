#include "gameview.h"
#include "ui_gameview.h"
#include <QLabel>


GameView::GameView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameView)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icones/ressources_ant_game/icone_app.png"));
    this->setWindowTitle(QString("Ant Game"));
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/background/ressources_ant_game/herbe.png")));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(800,600);

}

void GameView::update_test(QList<Item *> data_test)
{
    //scene->clear();

    for(int i = 0; i < data_test.size(); i++)
    {
        qDebug() << data_test[i]->getPositions()->getX();
        qDebug() << data_test[i]->getPositions()->getY();
        scene->addItem(data_test[i]->getGraphicData());
        ui->graphicsView->scene()->addItem(data_test.at(i)->getGraphicData());
    }
}

/*void GameView::update(QList<Item*> data)
{
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/background/ressources_ant_game/herbe.png")));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(800,600);

    scene->clear();

    for(int i = 0; i < data.size(); i++){
        qDebug() << "bonjour" ;
        ui->graphicsView->scene()->addItem(data.at(i)->getGraphicData());
    }


    scene->clear();

    foreach(Item* item, data)
    {
        qDebug() << "Bonjour" ;

        //ui->graphicsView->scene()->update();
        ui->graphicsView.scene()->addItem(item->getGraphicData());

    }

}*/

void GameView::test()
{
    QGraphicsScene scene;
    QLabel *gif_anim = new QLabel();
    /*
    QMovie *essai = new QMovie("/item/ant/ressources_ant_game/ant_static.gif");
    gif_anim->setMovie(essai);
    essai->start();*/

    ui->graphicsView->scene()->addWidget(gif_anim);
}



void GameView::on_harvesterButton_clicked()
{
    this->control->getModel()->addItem(new Ant(new Point(300,300)));
    int nbr = 0;
    for(int i = 0; i < this->control->getModel()->getDataItem().length(); i++)
    {
        nbr++;
    }
    this->ui->harvesterNumber->display(nbr);
}

void GameView::on_soldierButton_clicked()
{

}

GameView::~GameView()
{
    delete ui;
}



