#include "button.h"

Button::Button(std::string bttnText, UIEngine* eng)
{
    buttonText = bttnText;
    engine = eng;
}

void Button::backAction()
{
    std::cout << "BACKED!" << std::endl;
    engine->ExitMenu();
}

void AttackButton::confirmAction()
{
    GameManager::GetInstance()->Next(ATTACK);
}

void BlockButton::confirmAction()
{
    GameManager::GetInstance()->Next(BLOCK);
}

void SpecialAttackButton::confirmAction()
{
    if ( name == "HEAVY" ) {}
}

void SpecialAttackButton::backAction()
{
    engine -> SetButtonsCombat();
}

void MenuButton::confirmAction()
{
    if ( name == "QUIT" ) { CloseWindow(); }
    else if ( name == "START" ) { GameManager::GetInstance()->StartRun(); }
    else if ( name == "SETTINGS" ) { engine->EnterMenu(SETTINGS); }
    else if ( name == "ITEM" ) {engine -> EnterMenu(ITEMS); }
    else if ( name == "DREAM" ) {engine -> SetButtonsSpecialAttack(); }
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