
#ifndef UNIT_H
#define MONSTERUNIT_H

#include "gameunit.h"

class MonsterUnit : public GameUnit
{
public:
    MonsterUnit();
    MonsterUnit(float x, float y);
private:
    void Initialize();
};
#endif // MONSTERUNIT_H
