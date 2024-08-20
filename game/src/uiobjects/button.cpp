#include "button.h"
#include "../ui.h"
#include <raylib.h>


Button::Button(std::string bttnText, UIEngine* eng)
{
    buttonText = bttnText;
    engine = eng;
}

void AttackButton::confirmAction()
{
    engine->Next(ATTACK);
}

void AttackButton::backAction()
{
    std::cout << "BACKED!" << std::endl;
}


void BlockButton::confirmAction()
{
    engine->Next(BLOCK);
}

void BlockButton::backAction()
{
    std::cout << "BACKED!" << std::endl;
}

void TalkButton::confirmAction()
{
    engine->Next(TALK);
}

void TalkButton::backAction()
{
    std::cout << "BACKED!" << std::endl;
}

void MenuButton::confirmAction()
{
    if ( name == "QUIT" ) { CloseWindow(); }
    else if ( name == "START" ) { engine->ChangeScreen(FIGHT); }
    else if ( name == "SETTINGS" ) { engine->ChangeScreen(SETTINGS); }
}

void MenuButton::backAction()
{
    std::cout << "BACKED!" << std::endl;
}
