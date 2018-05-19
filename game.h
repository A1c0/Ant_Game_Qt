#ifndef GAME_H
#define GAME_H

#include "gameview.h"
#include "gamemodel.h"
#include "ant.h"
#include <QMediaPlayer>
#include <QMessageBox>

#include <QDebug>

class GameView;
class GameModel;


class Game
{
private:
    GameModel *model;
    GameView *view;
public:
    Game(GameModel *model, GameView *view);
    void init_item();
    void run_game();
    void change_pos();
    bool updateUnit(Item *test);
    void updateView();
    GameView * getView();
    GameModel * getModel();
};

#endif // GAME_H
