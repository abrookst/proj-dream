#ifndef UI_H
#define UI_H

#include <raylib.h>
#include <cstdint>
#include <vector>
#include <string>
#include <map>

enum UIState
{
	TITLESCREEN = 0,
	SETTINGS,
	DAYTIMEWORLD,
	DAYTIMEPLAYER,
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
	Texture2D uiTexture;
	uint8_t maxListLength;
	uint8_t maxWordLength;
	std::vector<std::string> scrollableList;
	uint8_t selectedElement;
};

class UIEngine
{
public:
	UIEngine(Font mainFont);

	void ChangeScreen(
		UIState state);

	void SetInputEnabled(
		bool input);

	UIState GetCurrentScreen(
		void);

	void ProcessInputKeyboard(
		KeyboardKey keyPressed);

	Texture2D GetTexture(
		void);

	void RenderUI();

private:
	void MoveUp();
	void MoveDown();
	void Confirm();
	void Back();

	Font mainFont;
	
	bool changingScreen;
	UIState currentUIState;
	UIData currentUIData;
	bool inputEnabled;

	std::map<UIState, UIData> uidata;
};

#endif
