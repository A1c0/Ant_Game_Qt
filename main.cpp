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
    active->run_game();
    w.show();

    //phase de test


    return a.exec();
}
