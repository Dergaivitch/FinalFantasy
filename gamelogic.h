#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QList>
#include <QTimer>
#include <QSignalMapper>
#include "gameobject.h"
#include "mageunit.h"
#include "gameunit.h"
#include "monsterunit.h"
#include "actionbutton.h"

class GameLogic : public QObject
{
    Q_OBJECT
public:
    GameLogic();
    QList<GameObject *> getGameObjects();
    QList<ActionButton *> getButtons();
    void ProcessEvents();
    GameUnit* enemy;
    void computerAttack();


private:
    MageUnit *mage;
    MonsterUnit *monster;
    QTimer gameTimer;
    QList<GameObject *> gameObjects;
    QList<GameUnit *> playerAGameUnits;
    QList<GameUnit *> playerBGameUnits;
    QList<ActionButton *> Buttons;
    void addButton(ActionButton *key);

public slots:
    void objectsInTime();
    void attack();
    void heal();
    void cast();
    void getMonsterAsTarget();
    void getMageAsTarget();
    void getTarget();
signals:
    void GameUpdated();
};

#endif // GAMELOGIC_H
