#ifndef BATTLE_ENCOUNTER_H
#define BATTLE_ENCOUNTER_H

#include "encounter.h"
#include "../entity/monster.h"
#include "../entity/player.h"
#include "../action/action.h"

class BattleEncounter : public Encounter
{
    Monster* monster;
    Player* player;

public:
    BattleEncounter(Monster& m);
    void NextTurn();

};

#endif
