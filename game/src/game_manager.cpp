#include "game_manager.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() {
    instance = this;
}

void GameManager::StartRun() {
    StartRandomMonsterEncounter();
}

void GameManager::GoForward() {
    TextEngine* textEngine = TextEngine::GetInstance();
    textEngine->Write("Where will you go next?");

    UIEngine::GetInstance()->ChangeScreen(CHOOSE_NEXT_ENCOUNTER);    
}

//This function is just for testing,
void GameManager::StartRandomMonsterEncounter() {
    currentEncounter = new BattleEncounter(*monsters.at(0));
    SetEncounter(*currentEncounter);
}

void GameManager::Next(
        Action act)
{
    currentEncounter->Next(act);

    if (currentEncounter->GetFinished()) {
        GoForward();
        
    }
}

void GameManager::SetEncounter(
        Encounter& enc)
{
    currentEncounter = &enc;
    currentEncounter->SetStarted(true);
    if( currentEncounter->GetType() == BATTLE ) { 
        UIEngine* uiengine = UIEngine::GetInstance();
        uiengine->ChangeScreen(FIGHT);

        TextEngine* textEngine = TextEngine::GetInstance();
        textEngine->Write("Encountered Enemy!");
    }
}