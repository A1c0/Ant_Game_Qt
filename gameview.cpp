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

void GameView::update(QList<Item *> data)
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
    ui->graphicsView->scene()->update();
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
    this->control->createHarvester();
    this->ui->harvesterCreate->setDisabled(true);
}

void GameView::update(QList<Unit *> data)
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
    foreach(Unit *unit, data)
    {
        ui->graphicsView->scene()->update();
    }
}

void GameView::on_actionQuit_triggered()
{
    close();
}

int GameView::getSceneHeight()
{
    return this->scene->height();
}

int GameView::getSceneWidth()
{
    return this->scene->width();
}

void GameView::foodDisplay(int nbr)
{
    this->ui->foodNumber->display(nbr);
}

void GameView::increaseHarvester()
{
        int current = this->ui->harvesterCount->intValue();
        current++;
        this->ui->harvesterCount->display(current + 1);
}

void GameView::on_startButton_clicked()
{
    this->control->start();
}

void GameView::on_pauseButton_clicked()
{
    this->control->pause();
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

void GameView::on_soldierCreate_clicked()
{
        this->control->createSoldier();
        this->ui->soldierCreate->setDisabled(true);
}

void GameView::activateSoldierCreate()
{
    this->ui->soldierCreate->setDisabled(false);
}

void GameView::activateHarvesterCreate()
{
    this->ui->harvesterCreate->setDisabled(false);
}

void GameView::increaseSoldier()
{
        int current = this->ui->soldierCount->intValue();
        current++;
        this->ui->soldierCount->display(current);
}

void GameView::on_pushButton_clicked()
{
    this->control->clearPath();
}

QGraphicsScene *GameView::getScene()
{
    return this->ui->graphicsView->scene();
}
