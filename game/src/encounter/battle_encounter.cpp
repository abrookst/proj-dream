#include "battle_encounter.h"
#include "../entity/entity.h"
#include "../entity/player.h"


BattleEncounter::BattleEncounter(
    Monster& m)
{
    monster = new Monster(m);
    player = &Player::GetInstance();
}

void BattleEncounter::NextTurn(
    void)
{
    //Wait for player to perform action
    if (monster->GetHealth() == 0)
    {
        //TODO: give player loot
        //TODO: display screen for player to choose where to go next
        return;
    } 
    else if (player->GetHealth() == 0)
    {
    }


    //After player input is done, perform monster action
    Action* monsterAction = monster->RandomAction();
    monsterAction->Perform(*monster, Player::GetInstance());
}
