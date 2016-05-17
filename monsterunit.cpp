
#include "monsterunit.h"

MonsterUnit::MonsterUnit()
{
    Initialize();
}


MonsterUnit::MonsterUnit(float x, float y)
{
    Initialize();

    this->x = x;
    this->y = y;
}

void MonsterUnit::Initialize()
{
    this->image = new QImage(":/graphics/monsterunit.png");
    this->frameSize = QSize(64, 64);
    this->maxHealthPoints = 1000;
    this->healthPoints = maxHealthPoints;
    this->damage = 200;

    this->frames.insert(0, 1);
    this->frames.insert(1, 1);
    this->frames.insert(2, 1);

}
