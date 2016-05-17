#ifndef GAMEUNIT_H
#define GAMEUNIT_H

#include "gameobject.h"

class GameUnit : public GameObject
{
public:
    GameUnit();
    int getDamage();
    bool isDead = 0;
    void attack(GameUnit *enemyUnit);
    int getHealthPoints();
    void setHealthPoints(int healthPoints);
    int getMaxHealthPoints();
    //virtual void nextFrame();
protected:
    int healthPoints;
    int maxHealthPoints;
    int damage;
    QMap<size_t, size_t> attackingFrames;
private:

};

#endif // GAMEUNIT_H
