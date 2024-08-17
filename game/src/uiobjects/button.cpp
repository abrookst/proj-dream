#include "button.h"
#include "../ui.h"

Button::Button(std::string bttnText, Encounter* enc)
{
    buttonText = bttnText;
    encounter = enc;
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
    uiEngine->SetEncounter(*encounter);
    std::cout << "CONFIRMED!" << std::endl;
}

void MenuButton::backAction()
{
    std::cout << "BACKED!" << std::endl;
}
