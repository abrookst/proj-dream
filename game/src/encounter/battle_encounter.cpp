#include "battle_encounter.h"
#include "../entity/entity.h"
#include "../entity/player.h"


BattleEncounter::BattleEncounter(
    Monster m)
{
    monster = m;
}

void BattleEncounter::NextTurn(
    void)
{
    //Wait for player to perform action
    if (monster.GetHealth() == 0)
    {
        //TODO: give player loot
        //TODO: display screen for player to choose where to go next
        return;
    }

    //After player input is done, perform monster action
    Player player = Player(10, 10, 10, std::vector<Action*>());//TODO: get player from somewhere

    Action* monsterAction = monster.RandomAction();
    monsterAction->Perform(monster, player);
}
