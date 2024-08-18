#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <iostream>
#include "../encounter/encounter.h"

class UIEngine;

struct Button
{
public:
	std::string buttonText;
    Encounter* encounter;
	virtual void confirmAction() {}
	virtual void backAction() {}
	Button(std::string);
	virtual ~Button() {}
};

struct AttackButton : public Button
{
public:
	AttackButton(Encounter* enc) : Button("ATTK") {}
	void confirmAction();
	void backAction();
};

struct BlockButton : public Button
{
public:
	BlockButton(Encounter* enc) : Button("BLCK") {}
	void confirmAction();
	void backAction();
};

struct TalkButton : public Button
{
public:
	TalkButton(Encounter* enc) : Button("TALK") {}
	void confirmAction();
	void backAction();
};

struct MenuButton : public Button
{
public:
    std::string name;

	MenuButton(std::string n) : Button(n) {name = n;}
	void confirmAction();
	void backAction();
};

#endif
