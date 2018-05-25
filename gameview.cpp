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
    scene->setSceneRect(0,0,1600,900);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/background/ressources_ant_game/herbe.png")));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(1600,900);
    this->ui->waveProgress->setRange(0,25000);

}

GameView::~GameView()
{
    delete ui;
}

void GameView::update()
{

    scene->setSceneRect(0,0,1600,900);
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
void GameView::remove_item(Item * item)
{
    this->scene->removeItem(item->getGraphicData());
}

void GameView::test()
{
}




void GameView::on_harvesterCreate_clicked()
{
    this->control->createHarvester();
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
        this->ui->harvesterCount->display(current);
}

void GameView::on_startButton_clicked()
{
    this->control->start();
}

void GameView::on_pauseButton_clicked()
{
    this->control->pause();
}

void GameView::mousePressEvent(QMouseEvent *event)
{
    QPointF * point = new QPointF(this->ui->graphicsView->mapFromGlobal(event->pos()));
    if(point->rx() >= 0 && point->rx() <= this->ui->graphicsView->scene()->width() && point->ry() >= 0 && point->ry() <= this->ui->graphicsView->scene()->height() )
    {
        emit newPoint(point);
    }
}

void GameView::on_soldierCreate_clicked()
{
        this->control->createSoldier();
}

void GameView::activateSoldierCreate()
{
    this->ui->soldierCreate->setEnabled(true);
    this->ui->soldierCreate->setDisabled(false);
}

void GameView::activateHarvesterCreate()
{
    this->ui->harvesterCreate->setDisabled(false);
    this->ui->harvesterCreate->setEnabled(true);
}

void GameView::deactivateHarvesterCreate()
{
    this->ui->harvesterCreate->setDisabled(true);
    this->ui->harvesterCreate->setEnabled(false);
}

void GameView::deactivateSoldierCreate()
{
    this->ui->soldierCreate->setDisabled(true);
    this->ui->soldierCreate->setEnabled(false);
}

void GameView::increaseSoldier()
{
        int current = this->ui->soldierCount->intValue();
        current++;
        this->ui->soldierCount->display(current);
}

void GameView::decreaseSoldier()
{
        int current = this->ui->soldierCount->intValue();
        current--;
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

void GameView::updateDisplayLCD(int newVal)
{
    this->ui->waveNumber->display(newVal);
}

void GameView::wavePrgSet(int elapsed)
{
    this->ui->waveProgress->setValue(elapsed);
}

void GameView::wavePrgReset()
{
    this->ui->waveProgress->setValue(0);
}
void GameView::gameOver()
{
    QGraphicsTextItem* gameOver = this->scene->addText(QString("GAME OVER !! "), QFont("Tahoma",36));
    gameOver->setOpacity(1);
}
