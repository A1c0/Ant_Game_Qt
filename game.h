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
#include "enemy.h"
#include "soldier.h"
#include <QTime>


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
    QTimer *timer3;
    QTimer *timer4;
    QTimer *timer5;
    QTimer *timer6;
    QTimer *timer7;
    QMediaPlayer *bgmF;
    QMediaPlayer * BGSFX;
    QTime * clock;
public:
    Game(GameModel *model, GameView *view);
    void init_item();
    void start();
    void pause();
    void createHarvester();
    void createSoldier();
    void clearPath();
    void manageCollide(Unit * unit, qreal *newX, qreal *newY);
    int findInModelWithQGraphicItem(QGraphicsItem *qgi);
    void waveManagement();
    void updateWaveNumber();

public slots:
    void update();
    void mainProcess();
    void advance(Unit *item);
    void sfx1();
    void sfx2();
    void sfx3();
    void sfx4();
    void bgm();
    void spawnHarvester();
    void spawnSoldier();
    void fight(Unit * attacker, Unit * target);
    void addPathPoint(QPointF *p);
    void loopSoldiers();
    void createWave();
    void updateHUD();


};

#endif // GAME_H
