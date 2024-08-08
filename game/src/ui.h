#ifndef UI_H
#define UI_H

#include <raylib.h>
#include <cstdint>
#include <vector>
#include <string>

enum UIState
{
	TITLESCREEN = 0,
	SETTINGS,
	DAYTIME,
	DREAMWORLD,
	DREAMPLAYER,
	MENU,
	STATS,
	MAGIC,
	ABILITY,
	WEAPON,
	EQUIP,
	ITEMS,
	INALIDSTATE
};
struct UIData
{
	Image uiFrame;
	uint8_t maxListLength;
	uint8_t maxWordLength;
	std::vector<std::string> scrollableList;
	uint8_t selectedElement;
};

class UIEngine
{
public:
	void ChangeScreen(
		UIState state);

	void UIEngine::Input(
		bool input);

	UIState GetCurrentScreen(
		void);

	void ProcessInputKeyboard(
		KeyboardKey keyPressed);

	Texture2D GetTexture(
		void);

private:
	void MoveUp();
	void MoveDown();
	void Confirm();
	void Back();
	void RenderUI();
	bool changingScreen;
	UIState currentUIState;
	UIData currentUIData;
	bool inputEnabled;

};

#endif
