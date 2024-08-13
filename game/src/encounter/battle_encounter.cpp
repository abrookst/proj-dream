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

    uint8_t monsterHpOld = monster->GetHealth();
    uint8_t playerHpOld = player->GetHealth();

    act->Perform(*player, *monster, *textEngine);

    if (monster->GetBlock()) { monster->SetBlock(false); }

    //After player input is done, perform monster action
    Action* monsterAction = monster->RandomAction();
    monsterAction->Perform(*monster, *player, *textEngine);

    if (player->GetBlock()) { player->SetBlock(false); }

    if (monster->GetHealth() == 0)
    {
        //TODO: give player loot
        //TODO: display screen for player to choose where to go next
        textEngine->Write("Congratulations, you have defeated the enemy!");
        return;
    } 
    if (player->GetHealth() == 0)
    {
        textEngine->Write("You have been defeated!");
    }
}
