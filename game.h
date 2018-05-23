#ifndef GAME_H
#define GAME_H

#include "gameview.h"
#include "gamemodel.h"
#include "ant.h"


class GameView;
class GameModel;


class Game : public QObject
{
    Q_OBJECT
private:
    GameModel *model;
    GameView *view;
public:
    Game(GameModel *model, GameView *view);
    void init_item();
    void run_item();
    void createHarvester();

public slots:
    void update();
    void mainProcess();
    void advance(Unit *item);
};

#endif // GAME_H
