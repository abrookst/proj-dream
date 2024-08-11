#include "ui.h"

UIEngine::UIEngine(Font font)
{
	mainFont = font;

	currentUIState = DREAMWORLD;
	inputEnabled = true;

	uidata[DREAMWORLD] = {
		LoadImage("resources/sprites/ui/DREAMWORLD.png"),
		LoadTextureFromImage(LoadImage("resources/sprites/ui/DREAMWORLD.png")),
		5,
		10,
		{
			"ATTK",
			"BLCK",
			"TALK",
			"MENU"
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
	currentUIData.selectedElement--;
	if (currentUIData.selectedElement >= currentUIData.scrollableList.size())
	{
		currentUIData.selectedElement = currentUIData.scrollableList.size()-1;
	}
}

void UIEngine::MoveDown()
{
	currentUIData.selectedElement++;
	if (currentUIData.selectedElement >= currentUIData.scrollableList.size())
	{
		currentUIData.selectedElement = 0;
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
	DrawTexture(GetTexture(), 0, 0, WHITE);

	// Draw the list of options
	for (int i = 0; i < currentUIData.scrollableList.size(); i++)
	{
		//DrawTextEx(mainFont, buffer.c_str(), Vector2{ 3, 47 }, 6, 1, RED);
		DrawTextEx(
			mainFont,
			currentUIData.scrollableList[i].c_str(),
			Vector2{ 46, 19.0f + (i * 6) },
			6,
			1,
			BLACK
		);
	}

	// Draw the cursor
	DrawTextEx(
		mainFont,
		">",
		Vector2{ 42, 19.0f + (currentUIData.selectedElement * 6) },
		6,
		1,
		BLACK
	);
}
