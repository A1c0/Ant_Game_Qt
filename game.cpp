#include "game.h"


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
    timer1->setInterval(40);
    timer2->setInterval(40);
    timer5->setInterval(40);
    init_item();
    bgmF = new QMediaPlayer;
    bgmF->setMedia(QUrl("qrc:/bgm2/ressources_ant_game/bgm1.mp3"));
    bgmF->setVolume(50);
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
    this->model->addUnit(new Enemy(new QPointF(800,800)));
    this->view->foodDisplay(this->model->getFoodSupply());
    this->view->update(this->model->getDataItem());
    this->view->update(this->model->getDataUnit());
    foreach (Item * item, this->model->getDataItem())
    {
        this->view->add_item(item);
    }
    foreach (Unit * unit, this->model->getDataUnit())
    {
        this->view->add_item(unit);
    }
}


void Game::spawnHarvester()
{
    this->model->addUnit(new Harvester(this->model->getNestPos()));
    this->view->increaseHarvester();
    this->view->add_item(this->model->getDataUnit().last());
    this->view->update(this->model->getDataUnit());
    this->view->activateHarvesterCreate();
}

void Game::spawnSoldier()
{
    this->model->addUnit(new Soldier(this->model->getNestPos()));
    this->model->getDataUnit().last()->setPath(this->model->getPathPointList());
    this->view->increaseSoldier();
    this->view->add_item(this->model->getDataUnit().last());
    this->view->update(this->model->getDataUnit());
    this->view->activateSoldierCreate();
}

void Game::createHarvester()
{
    if( this->model->getFoodSupply() >= 50)
    {
            this->sfx1();
            this->model->addFood(-50);
            timer3->start(2000);
    }
    else
    {
        this->sfx2();
    }
}

void Game::createSoldier()
{
    if( this->model->getFoodSupply() >= 100)
    {
            this->sfx1();
            this->model->addFood(-100);
            timer4->start(3000);
    }
    else
    {
        this->sfx2();
    }
}

void Game::mainProcess()
{
    foreach (Unit* unit, this->model->getDataUnit()) {
        if(unit->getMovePoints()->size() != 0)
        {
            if(unit->getCanHarvest() == true)
            {
                unit->harvest();
            }
            else if(unit->getCanAttack() == true)
            {
                Unit * target = unit->getTarget();
                this->fight(unit, target);
            }
            else
            {
               this->advance(unit);
            }
        }
    }
    this->view->foodDisplay(this->model->getFoodSupply());
}
void Game::update(){
    this->view->update(this->model->getDataUnit());
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

}
void Game::bgm()
{
}

void Game::start()
{
    this->sfx3();
    bgmF->play();
    this->timer1->start();
    this->timer2->start();
    this->timer5->start();
}

void Game::pause()
{
    this->timer1->stop();
    this->timer2->stop();
    this->timer5->stop();
    bgmF->pause();
}

void Game::fight(Unit * attacker, Unit * target)
{
    target->setHealthPoints(target->getHealthPoints() - attacker->getAttackSpeed()*attacker->getAttackValue());
    attacker->setHealthPoints(attacker->getHealthPoints() - target->getAttackSpeed()*target->getAttackValue());
    if(target->getHealthPoints() <= 0)
    {
        int index = this->model->getDataUnit().indexOf(target);
        attacker->setCanAttack(false);
        this->model->getDataUnit().removeAt(index);
    }
    if(attacker->getHealthPoints() <= 0)
    {
        int index2 = this->model->getDataUnit().indexOf(attacker);
        if(target)
            target->setCanAttack(false);
        this->model->getDataUnit().removeAt(index2);
    }
}

void Game::addPathPoint(QPointF * p) {
    model->addPathPoint(p);
}

void Game::loopSoldiers()
{
    foreach (Unit * units, this->model->getDataUnit()) {
        if(units->getMovePoints()->size() == 0)
            units->setPath(this->model->getPathPointList());
    }
}

void Game::clearPath()
{
    this->model->clearPathPoints();
}

void Game::ManageCollide(Unit * unit, qreal newX, qreal newY)
{
    QGraphicsItem * qgi;
    QPointF * currentPos = new QPointF(unit->getGraphicData()->pos().rx(), unit->getGraphicData()->pos().ry());
    if (!(qgi = this->view->getScene()->itemAt(QPointF(currentPos->rx() + newX, currentPos->ry() + newY), QTransform())) == NULL) {
        if (this->findInModelWithQGraphicItem(qgi) >= 0) {
            qDebug() << "PAF !" << this->model->getDataItem().at(this->findInModelWithQGraphicItem(qgi));
        }
    }
    else if (!(qgi = this->view->getScene()->itemAt(QPointF(currentPos->rx() + newX + unit->getGraphicData()->pixmap().width(), currentPos->ry() + newY + unit->getGraphicData()->pixmap().height()), QTransform())) == NULL) {
        if (this->findInModelWithQGraphicItem(qgi) >= 0) {
            qDebug() << "PAF !" << this->model->getDataItem().at(this->findInModelWithQGraphicItem(qgi));
        }
    }
    else if (!(qgi = this->view->getScene()->itemAt(QPointF(currentPos->rx() + newX, currentPos->ry() + newY + unit->getGraphicData()->pixmap().height()), QTransform())) == NULL) {
        if (this->findInModelWithQGraphicItem(qgi) >= 0) {
            qDebug() << "PAF !" << this->model->getDataItem().at(this->findInModelWithQGraphicItem(qgi));
        }
    }
    else if (!(qgi = this->view->getScene()->itemAt(QPointF(currentPos->rx() + newX + unit->getGraphicData()->pixmap().width(), currentPos->ry() + newY), QTransform())) == NULL) {
        if (this->findInModelWithQGraphicItem(qgi) >= 0) {
            qDebug() << "PAF !" << this->model->getDataItem().at(this->findInModelWithQGraphicItem(qgi));
        }
    }
    else {
        qDebug() << "ca va !";
    }
}
int Game::findInModelWithQGraphicItem(QGraphicsItem *qgi) {
    foreach (Item * item, this->model->getDataItem())
    {
        if (qgi->pos().rx() == item->getGraphicData()->pos().rx() && qgi->pos().ry() == item->getGraphicData()->pos().ry())
        {
            qDebug() << this->model->getDataItem().indexOf(item);
            return this->model->getDataItem().indexOf(item);
        }
    }
    return -1;
}
