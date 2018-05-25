#include "gameview.h"
#include "gamemodel.h"
#include "game.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameView w;
    GameModel m;

    Game *mainGame = new Game(&m, &w);
    w.showFullScreen();
    return a.exec();
}
