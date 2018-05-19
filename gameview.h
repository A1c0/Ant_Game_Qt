#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QMainWindow>
#include "game.h"
#include "item.h"
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
    void test();
    QGraphicsScene * getScene();

private slots:
    void on_harvesterButton_clicked();

    void on_soldierButton_clicked();

    void on_lcdNumber_overflow();

private:
    Ui::GameView *ui;
    QGraphicsScene * scene;
    Game *control;
};

#endif // GAMEVIEW_H
