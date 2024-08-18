#include "button.h"
#include <raylib.h>

Button::Button(std::string bttnText)
{
    buttonText = bttnText;
}

void AttackButton::confirmAction()
{
    std::cout << "CONFIRMED!" << std::endl;
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
    if (name == "QUIT")
    {
        CloseWindow();
    }
    std::cout << "CONFIRMED!" << std::endl;
}

void MenuButton::backAction()
{
    std::cout << "BACKED!" << std::endl;
}
