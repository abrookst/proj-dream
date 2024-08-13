#include "battle_encounter.h"

BattleEncounter::BattleEncounter(
    Monster& m,
    TextEngine& t)
{
    monster = new Monster(m);
    player = Player::GetInstance();
    textEngine = &t;

    instance = this;
}

void BattleEncounter::NextTurn(
    Action* act)
{

    act->Perform(*player, *monster);
    
    std::string writeText = "Congratulations, you have defeated the enemy!";

    if (monster->GetHealth() == 0)
    {
        //TODO: give player loot
        //TODO: display screen for player to choose where to go next
        std::string writeText = "Congratulations, you have defeated the enemy!";
        return;
    } 
    else if (player->GetHealth() == 0)
    {
        std::string writeText = "You have been defeated!";
    }


    // std::cout << "Player: " << (int)player->GetHealth() << ", Monster: " << (int)monster->GetHealth() << std::endl;
    if (monster->GetBlock()) { monster->SetBlock(false); }

    //After player input is done, perform monster action
    Action* monsterAction = monster->RandomAction();
    monsterAction->Perform(*monster, *player);

    if (player->GetBlock()) { player->SetBlock(false); }
}
