#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <iostream>

struct Button
{
public:
	std::string buttonText;
	virtual void confirmAction() {}
	virtual void backAction() {}
	Button(std::string bttnText)
	{
		buttonText = bttnText;
	}
	virtual ~Button() {}
};

struct AttackButton : public Button
{
public:
	AttackButton() : Button("ATTK") {}
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
	BlockButton() : Button("BLCK") {}
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
	TalkButton() : Button("TALK") {}
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
	MenuButton() : Button("MENU") {}
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
