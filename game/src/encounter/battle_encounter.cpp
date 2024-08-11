#include "battle_encounter.h"
#include "../entity/entity.h"
#include "../entity/player.h"
// #include <iostream>


BattleEncounter::BattleEncounter(
    Monster& m)
{
    monster = new Monster(m);
    player = Player::GetInstance();

    instance = this;
}

void BattleEncounter::NextTurn(
    void)
{

    // player->GetActions().at(0)->Perform(Player::GetInstance(), *monster);
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


    // std::cout << "Player: " << (int)player->GetHealth() << ", Monster: " << (int)monster->GetHealth() << std::endl;
    //After player input is done, perform monster action
    if (monster->GetBlock()) { monster->SetBlock(false); }
    Action* monsterAction = monster->RandomAction();
    monsterAction->Perform(*monster, *Player::GetInstance());

    if (player->GetBlock()) { player->SetBlock(false); }
}
