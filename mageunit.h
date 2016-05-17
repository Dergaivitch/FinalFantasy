#ifndef UNIT_H
#define MAGEUNIT_H

#include "gameunit.h"

class MageUnit : public GameUnit
{
public:
    MageUnit();
    MageUnit(float x, float y);
private:
    void Initialize();
};
#endif // MAGEUNIT_H

