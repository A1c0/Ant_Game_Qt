#include "gameview.h"
#include "gamemodel.h"
#include "game.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameView w;
    GameModel m;

    /*Ant *f3 = new Ant(new Point(350,350));
    m.addItem(f3);*/
    Game *active = new Game(&m, &w);
    active->run_game();
    //active->change_pos(f3);
    w.show();

    //phase de test


    return a.exec();
}
