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
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/background/ressources_ant_game/herbe.png")));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(800,600);

}

GameView::~GameView()
{
    delete ui;
}

void GameView::update(QList<Item> data)
{
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/background/ressources_ant_game/herbe.png")));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(800,600);

    foreach( Item item, data)
    {
        ui->graphicsView->scene()->addItem(item.getGraphicData());
    }
}

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

