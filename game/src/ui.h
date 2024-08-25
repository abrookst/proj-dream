#ifndef UI_H
#define UI_H

#include <raylib.h>
#include <cstdint>
#include <vector>
#include <string>
#include <map>
#include "uiobjects/button.h"
#include "encounter/encounter.h"
#include "item.h"

enum UIState
{
	TITLESCREEN = 0,
	SETTINGS,
	DAYTIMEWORLD,
	DAYTIMEPLAYER,
	DREAMWORLD,
	DREAMPLAYER,
	CHOOSE_NEXT_ENCOUNTER,
    FIGHT,
	MENU,
	STATS,
	MAGIC,
	ABILITY,
	WEAPON,
	EQUIP,
	ITEMS,
	INALIDSTATE
};

struct Button; //Forward declaration

struct UIData
{
	Image uiFrame;
	Texture2D uiTexture;
	uint8_t maxListLength;
	uint8_t maxWordLength;
	float textXPosition;
	float textYPosition;
	std::vector<Button*> scrollableList;
	uint8_t selectedElement;
};

class UIEngine
{
public:
	UIEngine(Font mainFont);

	void ChangeScreen(
		UIState state);

	void SetButtons(
		std::vector<Button*>& buttons);

	void SetInputEnabled(
		bool input);

	UIState GetCurrentScreen(
		void);

	void ProcessInputKeyboard(
		KeyboardKey keyPressed);

	Texture2D GetTexture(
		void);

	void RenderUI(
            void);

    uint8_t GetCurrentItem(void) { return currentUIData.selectedElement; }

	static UIEngine* GetInstance( ) { return instance; };

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

	std::map<UIState, UIData> uiDataMap;

	static UIEngine* instance;
};

#endif
