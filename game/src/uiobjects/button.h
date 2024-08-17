#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <iostream>
#include "../encounter/encounter.h"

struct Button
{
public:
	std::string buttonText;
    Encounter* encounter;
	virtual void confirmAction() {}
	virtual void backAction() {}
	Button(std::string bttnText, Encounter* enc)
	{
		buttonText = bttnText;
        encounter = enc;
	}
	virtual ~Button() {}
};

struct AttackButton : public Button
{
public:
	AttackButton(Encounter* enc) : Button("ATTK", enc) {}
	void confirmAction()
	{
		std::cout << "CONFIRMED!" << std::endl;
	}

	void backAction()
	{
		std::cout << "BACKED!" << std::endl;
	}
};

struct BlockButton : public Button
{
public:
	BlockButton(Encounter* enc) : Button("BLCK", enc) {}
	void confirmAction()
	{
		std::cout << "CONFIRMED!" << std::endl;
	}

	void backAction()
	{
		std::cout << "BACKED!" << std::endl;
	}
};

struct TalkButton : public Button
{
public:
	TalkButton(Encounter* enc) : Button("TALK", enc) {}
	void confirmAction()
	{
		std::cout << "CONFIRMED!" << std::endl;
	}

	void backAction()
	{
		std::cout << "BACKED!" << std::endl;
	}
};

struct MenuButton : public Button
{
public:
	MenuButton(Encounter* enc) : Button("MENU", enc) {}
	void confirmAction()
	{
		std::cout << "CONFIRMED!" << std::endl;
	}

	void backAction()
	{
		std::cout << "BACKED!" << std::endl;
	}
};

#endif
