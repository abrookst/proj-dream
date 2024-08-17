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
	Button(std::string, Encounter*);
	virtual ~Button() {}
};

struct AttackButton : public Button
{
public:
	AttackButton(Encounter* enc) : Button("ATTK", enc) {}
	void confirmAction();
	void backAction();
};

struct BlockButton : public Button
{
public:
	BlockButton(Encounter* enc) : Button("BLCK", enc) {}
	void confirmAction();
	void backAction();
};

struct TalkButton : public Button
{
public:
	TalkButton(Encounter* enc) : Button("TALK", enc) {}
	void confirmAction();
	void backAction();
};

struct MenuButton : public Button
{
public:
    UIEngine* uiEngine;

	MenuButton(Encounter* enc, UIEngine* eng) : Button("MENU", enc) { uiEngine = eng; }
	void confirmAction();
	void backAction();
};

#endif
