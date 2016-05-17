#include "gamelogic.h"
#include <QDebug>
GameLogic::GameLogic()
{
    QObject::connect(&gameTimer, SIGNAL(timeout()), this, SLOT(objectsInTime()));
    gameTimer.setInterval(50);
    gameTimer.start();

    mage = new MageUnit(520, -100);
    gameObjects.append(mage);
    playerBGameUnits.append(mage);

    monster = new MonsterUnit(100, 10);
    gameObjects.append(monster);
    playerAGameUnits.append(monster);

    enemy = NULL;

    ActionButton *attackButton = new ActionButton("Attack", QImage(":/graphics/attack.png"), QSize(32, 32));
    ActionButton *lightingBallButton = new ActionButton("LightingBall", QImage(":/graphics/attack.png"), QSize(32, 32));
    ActionButton *healButton = new ActionButton("Heal", QImage(":/graphics/attack.png"), QSize(40, 39));
    ActionButton *monsterTargetButton = new ActionButton("MonsterTarget", QImage(":/graphics/attack.png"), QSize(40, 39));

       QObject::connect(attackButton, SIGNAL(pressed()), this, SLOT(attack()));
       QObject::connect(lightingBallButton, SIGNAL(pressed()), this, SLOT(cast()));
       QObject::connect(healButton, SIGNAL(pressed()), this, SLOT(heal()));
       QObject::connect(monsterTargetButton, SIGNAL(pressed()), this, SLOT(getMonsterAsTarget()));

       addButton(attackButton);
       addButton(lightingBallButton);
       addButton(healButton);
       addButton(monsterTargetButton);
}

QList<GameObject *> GameLogic::getGameObjects()
{
    return gameObjects;
}

QList<ActionButton *> GameLogic::getButtons()
{
    return Buttons;
}

void GameLogic::ProcessEvents()
{
    foreach (GameObject *object, gameObjects)
    {
        object->nextFrame();
    }

    foreach (ActionButton *key, Buttons)
    {
        key->redraw();
    }


    emit GameUpdated();
}

void GameLogic::addButton(ActionButton *key)
{
    Buttons.append(key);
}



void GameLogic::attack()
{   if (enemy == NULL) enemy = mage;

    if ( (enemy->getHealthPoints() - mage->getDamage() ) < 0 )
        { enemy->setHealthPoints(0); enemy->isDead = 1; }
        else enemy->setHealthPoints(enemy->getHealthPoints() - 100);

    if ( (mage->getHealthPoints() - enemy->getDamage() ) < 0)
        { mage->setHealthPoints(0); mage->isDead = 1; }
        else  mage->setHealthPoints(mage->getHealthPoints()-50);
}



void GameLogic::heal() {
    if ( (mage->getHealthPoints() + 300) > mage->getMaxHealthPoints() )
        mage->setHealthPoints(mage->getMaxHealthPoints());
        else  mage->setHealthPoints(mage->getHealthPoints() + 300);

 mage->setHealthPoints(mage->getHealthPoints()-50);
}

void GameLogic::cast()
{
    monster->setHealthPoints(monster->getHealthPoints() - 150);
    mage->setHealthPoints(mage->getHealthPoints()-50);
}

void GameLogic::getMonsterAsTarget()
{
   enemy = monster;
}

void GameLogic::getMageAsTarget()
{

}

void GameLogic::getTarget()
{

}

void GameLogic::computerAttack()
{

}

void GameLogic::objectsInTime()
{
    computerAttack();
    ProcessEvents();
}

