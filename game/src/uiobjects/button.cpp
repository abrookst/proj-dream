#include "button.h"

Button::Button(std::string bttnText, UIEngine* eng)
{
    buttonText = bttnText;
    engine = eng;
}

void AttackButton::confirmAction()
{
    GameManager::GetInstance()->Next(ATTACK);
}

void AttackButton::backAction()
{
    std::cout << "BACKED!" << std::endl;
}


void BlockButton::confirmAction()
{
    GameManager::GetInstance()->Next(BLOCK);
}

void BlockButton::backAction()
{
    std::cout << "BACKED!" << std::endl;
}

void TalkButton::confirmAction()
{
    GameManager::GetInstance()->Next(TALK);
}

void TalkButton::backAction()
{
    std::cout << "BACKED!" << std::endl;
}

void MenuButton::confirmAction()
{
    if ( name == "QUIT" ) { CloseWindow(); }
    else if ( name == "START" ) { GameManager::GetInstance()->StartRun(); }
    else if ( name == "SETTINGS" ) { engine->ChangeScreen(SETTINGS); }
}

void MenuButton::backAction()
{
    std::cout << "BACKED!" << std::endl;
}
