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
    if (finished) {//To prevent text from action from overwritting the ending text.
        return;
    }
    // act->Perform(*player, *monster, *textEngine);
    switch (act)
    {
        case ATTACK:
            Attack(*player, *monster, *textEngine);
            break;
        case BLOCK:
            Block(*player, *textEngine);
            break;
        case TALK:
            Talk(*monster, *textEngine);
        default:
            Other(*monster, *player, act, *textEngine);
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
        default:
            Other(*monster, *player, monsterAction, *textEngine);
    }

    if (player->GetBlock()) { player->SetBlock(false); }
    if (monster->GetHealth() == 0)
    {
        //TODO: give player loot
        //TODO: display screen for player to choose where to go next
        textEngine->Write("Congratulations, you have defeated the enemy!");
        finished = true;
        return;
    } 
    if (player->GetHealth() == 0)
    {
        textEngine->Write("You have been defeated!");
        finished = true;
    }
}
