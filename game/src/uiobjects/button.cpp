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

}

void AttackButton::backAction()
{
    std::cout << "BACKED!" << std::endl;
}


void BlockButton::confirmAction()
{
    std::cout << "CONFIRMED!" << std::endl;
}

void BlockButton::backAction()
{
    std::cout << "BACKED!" << std::endl;
}

void TalkButton::confirmAction()
{
    std::cout << "CONFIRMED!" << std::endl;
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
    std::cout << "CONFIRMED!" << std::endl;
}

void MenuButton::backAction()
{
    std::cout << "BACKED!" << std::endl;
}
