#include "game_manager.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() {
    instance = this;
}

void GameManager::StartRun() {
    BattleEncounter* firstEncounter = new BattleEncounter(*monsters.at(0));
    SetEncounter(*firstEncounter);
}

void GameManager::Next(
        Action act)
{
    currentEncounter->Next(act);

    if (currentEncounter->GetFinished()) {
        TextEngine* textEngine = TextEngine::GetInstance();
        textEngine->Write("Where will you go next?");
    }
}

void GameManager::SetEncounter(
        Encounter& enc)
{
    currentEncounter = &enc;
    currentEncounter->SetStarted(true);
    if( currentEncounter->GetType() == BATTLE ) { UIEngine::GetInstance()->ChangeScreen(FIGHT); }
}