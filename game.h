#ifndef GAME_H
#define GAME_H

#include "gameview.h"
#include "gamemodel.h"
#include "ant.h"
#include <QDebug>
#include <typeinfo>
#include <QTimer>
#include <QtMath>
#include <math.h>
#include "harvester.h"
#include <QWindow>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QMediaPlaylist>


class GameView;
class GameModel;


class Game : public QObject
{
    Q_OBJECT
private:
    GameModel *model;
    GameView *view;
    QTimer *timer1;
    QTimer *timer2;
    QMediaPlayer *bgmF;
    QMediaPlayer * BGSFX;
public:
    Game(GameModel *model, GameView *view);
    void init_item();
    void run_item();
    void createHarvester();
    void start();
    void pause();

public slots:
    void update();
    void mainProcess();
    void advance(Unit *item);
    void sfx1();
    void sfx2();
    void sfx3();
    void sfx4();
    void bgm();
};

#endif // GAME_H
