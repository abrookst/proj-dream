#ifndef BATTLE_ENCOUNTER_H
#define BETTLE_ENCOUNTER_H

#include "encounter.h"
#include "monster.h"

class BattleEncounter : public Encounter
{
    Monster monster;

public:
    BattleEncounter(Monster m);
    void NextTurn();

};

#endif