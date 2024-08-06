#include "monster.cpp"

class BattleEncounter : public Encounter
{
    Monster monster;

public:
    BattleEncounter(Monster);
    void NextTurn();

};

BattleEncounter::BattleEncounter(Monster m)
{
    monster = m;
}

void BattleEncounter::NextTurn()
{
    Action monsterAction = monster.RandomAction();
    if (monsterAction == ATTACK)
    {

    }
}
