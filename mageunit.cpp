#include "mageunit.h"

MageUnit::MageUnit()
{
    Initialize();
}


MageUnit::MageUnit(float x, float y)
{
    Initialize();

    this->x = x;
    this->y = y;
}

void MageUnit::Initialize()
{
    this->image = new QImage(":/graphics/mageunit.png");
    this->frameSize = QSize(49, 48);
    this->maxHealthPoints = 1000;
    this->healthPoints = maxHealthPoints;
    this->damage = 200;

    this->frames.insert(0, 1);
    this->frames.insert(1, 1);
    this->frames.insert(2, 1);
    this->frames.insert(3, 1);
    this->frames.insert(4, 1);
}
