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

	//Sets the button for the current UI state.
	//If you switch UI states and later switch back, the buttons will be saved.
	void SetButtons(
		std::vector<Button*>& buttons);

	void SetButtonsInventory();

	void SetButtonsCombat();

	void SetButtonsSpecialAttack();

	//Same as changescreen, except the current state is placed into the escape queue.
	void EnterMenu(
		UIState state);

	void ExitMenu();

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

    uint8_t GetCurrentItem(void) { return currentUIData->selectedElement; }

	static UIEngine* GetInstance( ) { return instance; };

private:
	void MoveUp();
	void MoveDown();
	void Confirm();
	void Back();

	Font mainFont;
	
	bool changingScreen;
	UIState currentUIState;
	UIData* currentUIData;
	bool inputEnabled;

	std::map<UIState, UIData> uiDataMap;

	//This stores the UI state before entering a menu, so that you can return to it after you exit the menu.
	std::vector<UIState> escapeQueue;

	static UIEngine* instance;
};

#endif
