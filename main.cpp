#include "gameview.h"
#include "gamemodel.h"
#include "game.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameView w;
    GameModel m;

    Game *active = new Game(&m, &w);
    w.showFullScreen();
    active->run_item();
    //phase de test


    return a.exec();
}
