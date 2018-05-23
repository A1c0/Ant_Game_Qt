#include "gameview.h"
#include "ui_gameview.h"
#include <QLabel>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

GameView::GameView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameView)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icones/ressources_ant_game/icone_app.png"));
    this->setWindowTitle(QString("Ant Game"));
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1600,900); // make the scene 800x600 instead of infinity by infinity (default)
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/background/ressources_ant_game/herbe.png")));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(1600,900);

}

GameView::~GameView()
{
    delete ui;
}

void GameView::update(QList<Item*> data)
{
    /*
    foreach(Item *item, data)
    {
        ui->graphicsView->scene()->removeItem(item->getGraphicData());
    }*/
    scene->setSceneRect(0,0,1600,900); // make the scene 800x600 instead of infinity by infinity (default)
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/background/ressources_ant_game/herbe.png")));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(1600,900);
    foreach(Item *item, data)
    {
        ui->graphicsView->scene()->update();
    }
}

void GameView::add_item(Item * item)
{
    this->scene->addItem(item->getGraphicData());
}

void GameView::test()
{
    /*
    QGraphicsScene scene;
    QLabel *gif_anim = new QLabel();
    QMovie *movie = new QMovie(":/item/ant/ressources_ant_game/ant_static.gif");
    gif_anim->setMovie(movie);
    movie->start();
    ui->graphicsView->scene()->addWidget(gif_anim);*/
}

void GameView::on_harvesterCreate_clicked()
{
    int current = this->ui->harvesterCount->intValue();
    this->control->createHarvester();
    current++;
    this->ui->harvesterCount->display(current);
}

void GameView::mousePressEvent(QMouseEvent *event){
    int posX = event->pos().x();
    int posY = event->pos().y();
    qDebug() << this->ui->graphicsView->scene()->height();
    qDebug() << this->ui->graphicsView->scene()->width();
    QPointF * point = new QPointF(this->ui->graphicsView->mapFromGlobal(event->pos()));
    qDebug() << "x/y pos mapToGlobal : " << point;

    if(point->rx() >= 0 && point->rx() <= this->ui->graphicsView->scene()->width() && point->ry() >= 0 && point->ry() <= this->ui->graphicsView->scene()->height() ) {
        emit newPoint(point);
    }
}
