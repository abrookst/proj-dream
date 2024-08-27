#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <iostream>
#include "../game_manager.h"
#include "../encounter/encounter.h"
#include "../ui.h"
#include <raylib.h>

class UIEngine;

struct Button
{
public:
	std::string buttonText;
    UIEngine* engine;
	virtual void confirmAction() {}
	virtual void backAction();
	Button(std::string, UIEngine*);
	virtual ~Button() {}
};

struct AttackButton : public Button
{
public:
	AttackButton(UIEngine* eng) : Button("ATTK", eng) {}
	void confirmAction();
};

struct BlockButton : public Button
{
public:
	BlockButton(UIEngine* eng) : Button("BLCK", eng) {}
	void confirmAction();
};

struct SpecialAttackButton : public Button
{
public:
	Action action;

	SpecialAttackButton(Action act, UIEngine* eng) : Button(GetActionName(act), eng) { action = act; }
	void confirmAction();
	void backAction();
};

struct MenuButton : public Button
{
public:
    std::string name;

	MenuButton(std::string n, UIEngine* eng) : Button(n, eng) {name = n;}
	void confirmAction();
};

struct PathButton : public Button
{
public:
	std::string name;

	PathButton(std::string n, UIEngine* eng) : Button(n, eng) {name = n;}
	void confirmAction();
};

struct ItemButton: public Button
{
public:
	Item item;

	ItemButton(Item i, UIEngine* eng) : Button(GetItemName(i), eng) { item = i; }
	void confirmAction();
};

#endif
