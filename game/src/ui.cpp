#include "ui.h"

UIEngine::UIEngine()
{
	currentUIState = DREAMWORLD;
	inputEnabled = true;

	uidata[DREAMWORLD] = {
		LoadImage("resources/sprites/ui/DREAMWORLD.png"),
		LoadTextureFromImage(LoadImage("resources/sprites/ui/DREAMWORLD.png")),
		5,
		10,
		{
			"Daytime World",
			"Daytime Player",
			"Dream World",
			"Dream Player",
			"Menu"
		},
		0
	};


	currentUIData = uidata[currentUIState];
}

void UIEngine::ChangeScreen(UIState state)
{
	currentUIState = state;

	switch(state)
	{
	case DAYTIMEWORLD:
	case DAYTIMEPLAYER:
	case DREAMWORLD:
	case DREAMPLAYER:
	case MENU:
	case STATS:
	case MAGIC:
	case ABILITY:
	case WEAPON:
	case EQUIP:
	case ITEMS:
	case INALIDSTATE:
	break;
	}
}

void UIEngine::SetInputEnabled(
	bool input)
{
	inputEnabled = input;
}

UIState UIEngine::GetCurrentScreen(
	void)
{
	return currentUIState;
}

void UIEngine::ProcessInputKeyboard(
	KeyboardKey keyPressed)
{
	if (!inputEnabled) 
	{
		return;
	}

	switch(keyPressed)
	{
	case KEY_W:
	case KEY_UP:
		MoveUp();
		break;
	case KEY_S:
	case KEY_DOWN:
		MoveDown();
		break;
	case KEY_ENTER:
	case KEY_Z:
		Confirm();
		break;
	case KEY_X:
	case KEY_BACKSPACE:
		Back();
	}
	RenderUI();
}

Texture2D UIEngine::GetTexture(
	void)
{
	//Gets the texture so that main.cpp can render it
	return currentUIData.uiTexture;
}

void UIEngine::MoveUp()
{
	if (currentUIData.selectedElement > 0)
	{
		currentUIData.selectedElement--;
	}
}

void UIEngine::MoveDown()
{
	if (currentUIData.selectedElement < currentUIData.scrollableList.size() - 1)
	{
		currentUIData.selectedElement++;
	}
}

void UIEngine::Confirm()
{
	// Confirm selection
}

void UIEngine::Back()
{
	// Go back to previous screen
	ChangeScreen(DAYTIMEWORLD);
}

void UIEngine::RenderUI()
{
	//Chat IDK what this is supposed to do
}
