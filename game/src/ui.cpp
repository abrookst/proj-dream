#include "ui.h"

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
	}
}

void UIEngine::Input(
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
	case: KEY_BACKSPACE:
		Back();
	}
	RenderUI();
}

Texture2D UIEngine::GetTexture(
	void)
{
	return LoadTextureFromImage(currentUIData.uiFrame);
}