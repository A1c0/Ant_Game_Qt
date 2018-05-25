#include "game.h"
#include <time.h>
#include <stdlib.h>


Game::Game(GameModel *model, GameView *view) :
    view(view)
{

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/bgm2/ressources_ant_game/bgmfx.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    BGSFX = new QMediaPlayer;
    BGSFX->setPlaylist(playlist);
    BGSFX->setVolume(100);
    BGSFX->play();
    bgmF = new QMediaPlayer;
    clock = new QTime();
    clock->start();
    timer1 = new QTimer(this);
    this->connect(timer1, SIGNAL(timeout()), this, SLOT(mainProcess()));
    timer2 = new QTimer(this);
    this->connect(timer2, SIGNAL(timeout()), this, SLOT(update()));
    this->model = model;
    timer3 = new QTimer(this);
    this->connect(timer3, SIGNAL(timeout()), this, SLOT(spawnHarvester()));
    timer3->setSingleShot(true);
    timer4 = new QTimer(this);
    this->connect(timer4, SIGNAL(timeout()), this, SLOT(spawnSoldier()));
    timer4->setSingleShot(true);
    timer5 = new QTimer(this);
    this->connect(timer5, SIGNAL(timeout()), this, SLOT(loopSoldiers()));
    view->setControl(this);
    timer1->setInterval(16);
    timer2->setInterval(16);
    timer5->setInterval(16);
    timer6 = new QTimer(this);
    this->connect(timer6, SIGNAL(timeout()), this, SLOT(createWave()));
    timer6->setInterval(25000);
    timer7 = new QTimer();
    this->connect(timer7, SIGNAL(timeout()), this, SLOT(updateHUD()));
    timer7->setInterval(16);
    init_item();
    bgmF = new QMediaPlayer;
    bgmF->setMedia(QUrl("qrc:/bgm2/ressources_ant_game/bgm1.mp3"));
    bgmF->setVolume(100);
    this->connect(this->view, SIGNAL(newPoint(QPointF*)), this, SLOT(addPathPoint(QPointF*)));
}

void Game::init_item()
{
    this->model->addItem(new Item(new QPointF(100, 100), ":/item/ressources_ant_game/rock_1.png", 200, 200));
    this->model->addItem(new Item(new QPointF(500, 100), ":/item/ressources_ant_game/rock_2.png", 100, 100));
    this->model->addItem(new Item(this->model->getNestPos(), ":/item/ressources_ant_game/Fourmilière.gif", 100, 100));
    this->model->addItem(new Item(this->model->getfoodPos(), ":/item/ressources_ant_game/sugar.png", 100, 100));
    this->model->getDataItem().last()->setCollidable(false);
    this->model->addItem(new Item(new QPointF(400,800), ":/item/ressources_ant_game/Feuille_1.gif", 100, 100));
    this->model->addItem(new Item(new QPointF(1500,300), ":/item/ressources_ant_game/Feuille_2.gif", 100, 100));
    this->model->addItem(new Item(new QPointF(1300,100), ":/item/ressources_ant_game/Feuille_2.gif", 100, 100));
    this->model->addItem(new Item(new QPointF(950,230), ":/item/ressources_ant_game/Feuille_1.gif", 100, 100));
    this->model->addItem(new Item(new QPointF(360,200), ":/item/ressources_ant_game/Feuille_2.gif", 100, 100));
    this->model->addUnit((new Harvester(this->model->getNestPos())));
    this->view->foodDisplay(this->model->getFoodSupply());
    this->view->update();
    this->view->update();
    QListIterator<Item*> it(this->model->getDataItem());
    while(it.hasNext())
    {
        this->view->add_item(it.next());
    }
    QListIterator<Unit*> it2(this->model->getDataUnit());
    while(it2.hasNext())
    {
        this->view->add_item(it2.next());
    }
}


void Game::spawnHarvester()
{
    this->model->addUnit(new Harvester(this->model->getNestPos()));
    this->view->add_item(this->model->getDataUnit().last());
    this->view->increaseHarvester();
    this->view->update();
    this->view->activateHarvesterCreate();
}

void Game::spawnSoldier()
{
    this->model->addUnit(new Soldier(this->model->getNestPos()));
    this->model->getDataUnit().last()->setPath(this->model->getPathPointList());
    this->view->increaseSoldier();
    this->view->add_item(this->model->getDataUnit().last());
    this->view->update();
    this->view->activateSoldierCreate();
}

void Game::createHarvester()
{
    if( this->model->getFoodSupply() >= 50)
    {
            this->sfx1();
            this->model->addFood(-50);
            this->view->deactivateHarvesterCreate();
            timer3->start(2000);
    }
    else
    {
        this->view->activateHarvesterCreate();
        this->sfx2();
    }
}

void Game::createSoldier()
{
    if( this->model->getFoodSupply() >= 100)
    {
            this->sfx1();
            this->model->addFood(-100);
        this->view->deactivateSoldierCreate();
            timer4->start(3000);
    }
    else
    {
        this->view->activateSoldierCreate();
        this->sfx2();
    }
}

void Game::mainProcess()
{
    QListIterator<Unit*> it(this->model->getDataUnit());
    while(it.hasNext())
    {
        QListIterator<Unit*> it2(this->model->getDataUnit());
        while(it2.hasNext())
        {
            if(it.peekNext() != it2.peekNext())
                this->getDistance(it.peekNext(),it2.next());
            else
                it2.next();
        }
        if(it.peekNext()->getCanHarvest() == true)
        {
            it.next()->harvest();
        }
        else if(it.peekNext()->getCanAttack() == true)
        {
            Unit * target = it.peekNext()->getTarget();
            this->fight(it.next(), target);
        }
        else
        {
            if(it.peekNext()->getIsAlive() == true || it.peekNext()->getIsHarvester())
                this->advance(it.next());
        }
    }
}
void Game::update(){
    this->view->update();
}


void Game::advance(Unit * unit)
{
    QPointF * currentPos = new QPointF(unit->getGraphicData()->pos().rx(), unit->getGraphicData()->pos().ry());
    if(unit->getCanHarvest() == false)
    {
        if(unit->getMovePoints()->size() != 0)
        {
            QPointF * nextPos = new QPointF(unit->getMovePoints()->first()->rx(),unit->getMovePoints()->first()->ry());
            qreal newX = (nextPos->rx() - currentPos->rx());
            qreal newY = (nextPos->ry() - currentPos->ry());
            if(qFabs(newX) > unit->getMoveSpeed()  && newX > 0)
            {
                newX = unit->getMoveSpeed();
            }
            if(qFabs(newX) > unit->getMoveSpeed() && newX < 0)
            {
                newX = - unit->getMoveSpeed();
            }
            if(qFabs(newY) > unit->getMoveSpeed() && newY > 0)
            {
                newY = unit->getMoveSpeed();
            }
            if(qFabs(newY) > unit->getMoveSpeed() && newY < 0)
            {
                newY = - unit->getMoveSpeed();
            }

            if(newX + currentPos->rx() > (this->view->getSceneWidth() - 100))
            {
                newX = 0;
                unit->getMovePoints()->removeFirst();
            }
            if(newY + currentPos->ry() > (this->view->getSceneHeight()- 100))
            {
                newY = 0;
                unit->getMovePoints()->removeFirst();
            }
            if(newX + currentPos->rx() < 0)
            {
                newX = 0;
                unit->getMovePoints()->removeFirst();
            }
            if(newY + currentPos->ry() < 0)
            {
                newY = 0;
                unit->getMovePoints()->removeFirst();
            }
            qreal rotationFactor = qAcos(( 10 * newY ) / ( qSqrt( 10 * 10 ) * qSqrt( ( newX * newX ) + ( newY * newY ))));
            rotationFactor *= 180;
            rotationFactor /= M_PI;
            if(newX > 0)
            {
                rotationFactor += 180;
                if(newY > 0)
                    rotationFactor += 90;
                else if(newY < 0)
                    rotationFactor -= 90;
            }
            if(qFabs(currentPos->rx() - nextPos->rx()) < unit->getMoveSpeed() && qFabs(currentPos->ry() - nextPos->ry()) < unit->getMoveSpeed())
            {
                unit->getGraphicData()->setPos(nextPos->rx(), nextPos->ry());
                if(rotationFactor == rotationFactor)
                    unit->getGraphicData()->setRotation(rotationFactor);
                unit->getMovePoints()->removeFirst();
            }
            else
            {
                unit->getGraphicData()->setPos(newX + currentPos->rx(), newY + currentPos->ry());
                if(rotationFactor == rotationFactor)
                    unit->getGraphicData()->setRotation(rotationFactor);
            }
        }
    }
    if((unit->getGraphicData()->pos().rx() == FS_X && unit->getGraphicData()->pos().ry() == FS_Y) && unit->getIsHarvester() == true )
    {
        unit->setCanHarvest(true);
    }
    if( (unit->getGraphicData()->pos().rx() == NP_X && unit->getGraphicData()->pos().ry() == NP_Y )&& unit->getIsHarvester() == true && unit->getBringBack() == true )
    {
        this->model->addFood(10);
        unit->setBringBack(false);
    }
    if(unit->getIsEnemy() == true && (unit->getGraphicData()->pos().rx() == NP_X && unit->getGraphicData()->pos().ry() == NP_Y ))
    {
        this->pause();
        this->view->gameOver();
        this->sfx5();
    }
}

void Game::sfx1()
{

    QSoundEffect *player = new QSoundEffect;
    player->setSource(QUrl::fromLocalFile(":/bgm/ressources_ant_game/sfx1.wav"));
    player->setVolume(100);
    player->play();
}

void Game::sfx2()
{
    QSoundEffect *player = new QSoundEffect;
    player->setSource(QUrl::fromLocalFile(":/bgm/ressources_ant_game/sfx2.wav"));
    player->setVolume(100);
    player->play();
}
void Game::sfx3()
{
    QSoundEffect *player = new QSoundEffect;
    player->setSource(QUrl::fromLocalFile(":/bgm/ressources_ant_game/sfx3.wav"));
    player->setVolume(100);
    player->play();
}
void Game::sfx4()
{
    QSoundEffect *player = new QSoundEffect;
    player->setSource(QUrl::fromLocalFile(":/bgm2/ressources_ant_game/sfx4.wav"));
    player->setVolume(100);
    player->play();
}
void Game::sfx5()
{
    QSoundEffect *player = new QSoundEffect;
    player->setSource(QUrl::fromLocalFile(":/bgm2/ressources_ant_game/sfx5.wav"));
    player->setVolume(100);
    player->play();
}

void Game::start()
{
    this->sfx3();
    bgmF->play();
    this->timer1->start();
    this->timer2->start();
    this->timer5->start();
    this->timer6->start();
    this->timer7->start();
    clock->start();
}

void Game::pause()
{
    this->timer1->stop();
    this->timer2->stop();
    this->timer5->stop();
    this->timer6->stop();
    this->timer7->stop();
    bgmF->pause();
}

void Game::fight(Unit * attacker, Unit * target)
{
    if(target->getIsAlive() == true && attacker->getIsAlive() == true)
    {
        float aDamage = attacker->getAttackSpeed() * attacker->getAttackValue();
        float tLife = target->getHealthPoints();
        if(target != nullptr)
        target->setHealthPoints(tLife - aDamage);
        if(target->getHealthPoints() <= 0)
        {
            attacker->setCanAttack(false);
            if(target->getIsAlive() == true)
            {
                this->view->remove_item(target);
            }
            target->setIsAlive(false);
            this->advance(attacker);
            this->model->setEncounterSound(false);
            if(attacker->getTarget() != nullptr)
            {
                attacker->setTarget(nullptr);
            }
        }
    }

}

void Game::addPathPoint(QPointF * p) {
    model->addPathPoint(p);
}

void Game::loopSoldiers()
{
    QListIterator<Unit*> it(this->model->getDataUnit());
    while(it.hasNext())
    {
        if(it.peekNext()->getMovePoints()->size() == 0)
        {
            it.next()->setPath(this->model->getPathPointList());
        }
        else
        {
            it.next();
        }
    }
}

void Game::clearPath()
{
    this->model->clearPathPoints();
}

void Game::waveManagement()
{
    this->model->setWaveNumber(1);
    srand(time(NULL));
    int foeNumber = (rand() % ((this->model->getWaveNumber() +2) - 1)) + 1;
    int switcher = (rand() % 2);
    int xpos;
    int ypos;
    for(int i = 0; i < foeNumber; i++)
    {

        switch (switcher) {
        case 0:
            xpos = rand() % 1500;
            ypos = (rand() % 100) + 700;
            break;
        case 1:
            xpos = rand() % 1500;
            ypos = rand() % 100;
            break;
        default :
            xpos = 1500;
            ypos = 800;
            break;
        }
        this->model->addUnit(new Enemy(new QPointF(xpos,ypos)));
        this->view->add_item(this->model->getDataUnit().last());
    }
}

void Game::createWave()
{
    this->waveManagement();
}

void Game::updateWaveNumber()
{
    this->view->updateDisplayLCD(this->model->getWaveNumber() + 1);
}

void Game::updateHUD()
{
    this->updateWaveNumber();
    if(clock->elapsed() >= 25000)
    {
        clock->restart();
        this->view->wavePrgReset();
    }
    this->updateWaveNumber();
    this->view->wavePrgSet(clock->elapsed());
    this->view->foodDisplay(this->model->getFoodSupply());
}

void Game::getDistance(Unit * first, Unit * second)
{
    qreal firstX = first->getGraphicData()->pos().rx();
    qreal secondX = second->getGraphicData()->pos().rx();
    qreal xdist = qFabs( firstX - secondX);
    qreal firstY = first->getGraphicData()->pos().ry();
    qreal secondY = second->getGraphicData()->pos().ry();
    qreal ydist = qFabs( firstY - secondY);
    if(xdist <= 75 && ydist <= 75)
    {
        if(first->getIsEnemy() != second->getIsEnemy())
        {
            if(first->getIsAlive() == false || second->getIsAlive() == false)
            {

            }
            else
            {
                first->setCanAttack(true);
                if(second != nullptr)
                {
                    first->setTarget(second);
                    if(this->model->getEncounterSound() == false)
                    {
                        this->model->setEncounterSound(true);
                        this->sfx4();
                    }
                }
                second->setCanAttack(true);
                if(first != nullptr)
                {
                    second->setTarget(first);
                }
            }
        }
    }
}
