#ifndef GAME_H
#define GAME_H

#include "gameview.h"
#include "gamemodel.h"
#include "ant.h"
#include <QThread>

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};

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
    void run_item();
    void createHarvester();

};

#endif // GAME_H
