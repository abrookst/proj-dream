#include "battle_encounter.h"

#include "monster.h"

BattleEncounter::BattleEncounter(
    Monster m)
{
    monster = m;
}

void BattleEncounter::NextTurn(
    void)
{
    Action monsterAction = monster.RandomAction();
    if (monsterAction == ATTACK)
    {

    }
}
