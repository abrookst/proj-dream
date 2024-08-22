#include "battle_encounter.h"

BattleEncounter::BattleEncounter(
    Monster& m)
{
    monster = new Monster(m);
    player = Player::GetInstance();
    textEngine = TextEngine::GetInstance();
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
            Attack(*player, *monster);
            break;
        case BLOCK:
            Block(*player);
            break;
        case TALK:
            Talk(*monster);
        default:
            Other(*monster, *player, act);
    }

    if (monster->GetBlock()) { monster->SetBlock(false); }

    if (monster->GetHealth() == 0)
    {
        //TODO: give player loot
        //TODO: display screen for player to choose where to go next
        textEngine->Write("Congratulations, you have defeated the enemy!");
        finished = true;
        return;
    } 
    Action monsterAction = monster->RandomAction();
    switch (monsterAction)
    {
        case ATTACK:
            Attack(*monster, *player);
            break;
        case BLOCK:
            Block(*monster);
            break;
        default:
            Other(*monster, *player, monsterAction);
    }

    if (player->GetBlock()) { player->SetBlock(false); }
    
    if (player->GetHealth() == 0)
    {
        textEngine->Write("You have been defeated!");
        finished = true;
    }
}
