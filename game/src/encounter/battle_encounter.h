#ifndef BATTLE_ENCOUNTER_H
#define BATTLE_ENCOUNTER_H

#include "encounter.h"
#include "../entity/monster.h"

class BattleEncounter : public Encounter
{
    Monster monster;

public:
    BattleEncounter(Monster m);
    void NextTurn();

};

#endif
