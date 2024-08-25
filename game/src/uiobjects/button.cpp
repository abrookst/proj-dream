#include "button.h"

Button::Button(std::string bttnText, UIEngine* eng)
{
    buttonText = bttnText;
    engine = eng;
}

void Button::backAction()
{
    std::cout << "BACKED!" << std::endl;
}

void AttackButton::confirmAction()
{
    GameManager::GetInstance()->Next(ATTACK);
}

void BlockButton::confirmAction()
{
    GameManager::GetInstance()->Next(BLOCK);
}

void TalkButton::confirmAction()
{
    GameManager::GetInstance()->Next(TALK);
}

void MenuButton::confirmAction()
{
    if ( name == "QUIT" ) { CloseWindow(); }
    else if ( name == "START" ) { GameManager::GetInstance()->StartRun(); }
    else if ( name == "SETTINGS" ) { engine->EnterMenu(SETTINGS); }
    else if ( name == "ITEM" ) {engine -> EnterMenu(ITEMS); }
}

void PathButton::confirmAction()
{
    //Replace this code with selecting a specific encounter.
    GameManager::GetInstance()->StartRandomMonsterEncounter();
}

void ItemButton::confirmAction()
{
    UseItem(item);
}