#include "gameunit.h"
#include <QDebug>
GameUnit::GameUnit()
{
    this->damage = 0;
}

int GameUnit::getDamage()
{
    return damage;
}

void GameUnit::attack(GameUnit *enemyUnit)
{

    enemyUnit->setHealthPoints(enemyUnit->getHealthPoints() - damage);

    if (enemyUnit->getHealthPoints() < 0)
    {


    }

}


int GameUnit::getHealthPoints()
{
    return healthPoints;
}

void GameUnit::setHealthPoints(int healthPoints)
{
    this->healthPoints = healthPoints;
}

int GameUnit::getMaxHealthPoints()
{
    return maxHealthPoints;
}

/*void GameUnit::nextFrame()
{
    ++timeSinceCurrentFrame;

    if (frames.contains(currentFrame) && timeSinceCurrentFrame == frames[currentFrame])
    {
        if (frames.contains(currentFrame + 1))
        {
            ++currentFrame;
            timeSinceCurrentFrame = 0;
        }
        else
        {
            currentFrame = frames.keys().first();
            timeSinceCurrentFrame = 0;
        }
    }
}*/


