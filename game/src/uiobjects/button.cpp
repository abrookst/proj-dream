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
    else if ( name == "SETTINGS" ) { engine->ChangeScreen(SETTINGS); }
    else if ( name == "ITEM" ) {engine -> ChangeScreen(ITEMS); }
}

void PathButton::confirmAction()
{
    // if ( name == "FWRD") {
        GameManager::GetInstance()->GoForward();
    // }
}