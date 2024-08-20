#include "battle_encounter.h"
#include <iostream>

BattleEncounter::BattleEncounter(
    Monster& m,
    TextEngine& t)
{
    monster = new Monster(m);
    player = Player::GetInstance();
    textEngine = &t;
    encType = BATTLE;

    instance = this;
}

void BattleEncounter::Next(
    Action act)
{
    // act->Perform(*player, *monster, *textEngine);
    switch (act)
    {
        case ATTACK:
            Attack(*player, *monster, *textEngine);
            break;
        case BLOCK:
            Block(*player, *textEngine);
            break;
    }

    if (monster->GetBlock()) { monster->SetBlock(false); }
    Action monsterAction = monster->RandomAction();
    switch (monsterAction)
    {
        case ATTACK:
            Attack(*monster, *player, *textEngine);
            break;
        case BLOCK:
            Block(*monster, *textEngine);
            break;
    }

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
