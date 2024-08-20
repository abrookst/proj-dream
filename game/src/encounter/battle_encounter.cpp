#include "battle_encounter.h"

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

void BattleEncounter::NextTurn(
    Action act)
{
    // act->Perform(*player, *monster, *textEngine);
    if (act == ATTACK) { Attack(*player, *monster, *textEngine); }
    else if (act == BLOCK) { Block(*player, *textEngine); }
    else if (act == TALK) { Talk(*monster, *textEngine); }

    if (monster->GetBlock()) { monster->SetBlock(false); }
    Action* monsterAction = monster->RandomAction();
    if (*monsterAction == ATTACK) { Attack(*player, *monster, *textEngine); }
    else if (*monsterAction == BLOCK) { Block(*player, *textEngine); }
    else if (*monsterAction == TALK) { Talk(*monster, *textEngine); }

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
