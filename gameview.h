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
    void update(QList<Item*> data);
    void update(QList<Unit*> data);
    void test();
    void add_item(Item * item);
    int getSceneHeight();
    int getSceneWidth();
    void foodDisplay(int nbr);
    void increaseHarvester();

private slots:
    void on_harvesterCreate_clicked();
    void on_actionQuit_triggered();

    void on_startButton_clicked();

    void on_pauseButton_clicked();

private:
    Ui::GameView *ui;
    QGraphicsScene * scene;
    Game *control;

};

#endif // GAMEVIEW_H
