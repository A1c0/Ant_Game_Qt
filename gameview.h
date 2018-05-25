#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QMainWindow>
#include "game.h"
#include "item.h"
#include "unit.h"
#include <QList>
#include <QGraphicsScene>

class Game;
class GameModel;

namespace Ui {
class GameView;
}

class GameView : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameView(QWidget *parent = 0);
    ~GameView();
    void setControl(Game *control) {
        this->control = control;
    }
    void update();
    void test();
    void add_item(Item * item);
    void remove_item(Item * item);
    int getSceneHeight();
    int getSceneWidth();
    void foodDisplay(int nbr);
    void increaseHarvester();
    void increaseSoldier();
    void decreaseSoldier();
    void mousePressEvent(QMouseEvent *event);
    QGraphicsScene * getScene();
    void activateSoldierCreate();
    void activateHarvesterCreate();
    void deactivateSoldierCreate();
    void deactivateHarvesterCreate();
    void updateDisplayLCD(int newVal);
    void wavePrgReset();
    void wavePrgSet(int elapsed);
    void gameOver();



private slots:
    void on_harvesterCreate_clicked();
    void on_actionQuit_triggered();

    void on_startButton_clicked();

    void on_pauseButton_clicked();

    void on_soldierCreate_clicked();

    void on_pushButton_clicked();

private:
    Ui::GameView *ui;
    QGraphicsScene * scene;
    Game *control;

signals:
    void newPoint(QPointF *p);

};



#endif // GAMEVIEW_H
