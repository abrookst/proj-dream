#include "ui.h"

#define DREAM_WHITE      CLITERAL(Color){ 246, 219, 186, 255 }
#define DREAM_GREY         CLITERAL(Color){ 246, 219, 186, 128 }
#define DREAM_ORANGE      CLITERAL(Color){ 219, 96, 76, 255 }
#define DREAM_RED      CLITERAL(Color){ 177, 51, 83, 255 }
#define DREAM_PURPLE      CLITERAL(Color){ 94, 32, 82, 255 }
#define DREAM_GREEN      CLITERAL(Color){ 116, 201, 158, 255 }
#define DREAM_AQUA      CLITERAL(Color){ 49, 124, 135, 255 }
#define DREAM_BLUE      CLITERAL(Color){ 39, 24, 84, 255 }
#define DREAM_BLACK      CLITERAL(Color){ 26, 16, 22, 255 }

UIEngine* UIEngine::instance = nullptr;

UIEngine::UIEngine(Font font) { 
    mainFont = font; 
    instance = this;
#pragma region 
    uiDataMap[FIGHT] = {
        LoadImage("resources/sprites/UI/DREAMWORLD.png"),
        LoadTextureFromImage(LoadImage("resources/sprites/UI/DREAMWORLD.png")),
        5,
        10,
        43.0f,
        19.0f,
        {
            new AttackButton(this),
            new BlockButton(this),
            new MenuButton("DREAM", this),
            new MenuButton("ITEM", this)
        },
        0
    };
    uiDataMap[CHOOSE_NEXT_ENCOUNTER] = {
        LoadImage("resources/sprites/UI/DREAMWORLD.png"),
        LoadTextureFromImage(LoadImage("resources/sprites/UI/DREAMWORLD.png")),
        5,
        10,
        43.0f,
        19.0f,
        {
            new PathButton("LEFT", this),
            new PathButton("FWRD", this),
            new PathButton("RGHT", this)
        },
        0
    };
    uiDataMap[ITEMS] = {
        LoadImage("resources/sprites/UI/ITEMS.png"),
        LoadTextureFromImage(LoadImage("resources/sprites/UI/ITEMS.png")),
        5,
        10,
        5.0f,
        5.0f,
        {},
        0
    };
    uiDataMap[MENU] = {
        LoadImage("resources/sprites/UI/MENU.png"),
        LoadTextureFromImage(LoadImage("resources/sprites/UI/MENU.png")),
        5,
        10,
        3.0f,
        4.0f,
        {
            new MenuButton("MENU", this)
        },
        0
    };
    uiDataMap[TITLESCREEN] = {
        LoadImage("resources/sprites/UI/SETTINGS.png"),
        LoadTextureFromImage(LoadImage("resources/sprites/UI/SETTINGS.png")),
        0,
        0,
        20.0f,
        20.0f,
        {
            new MenuButton("START", this),
            new MenuButton("SETTINGS", this),
            new MenuButton("QUIT", this),
        },
        0
    };
#pragma endregion
    currentUIData = &uiDataMap[TITLESCREEN];
}

void UIEngine::EnterMenu(
		UIState state)
{
    escapeQueue.push_back(currentUIState);
    ChangeScreen(state);
}

void UIEngine::ChangeScreen(UIState state)
{
    currentUIState = state;

    //Dont unload, because now we only load once at the start of the game.
    //If currentUIData is uninitialized, all number values will be 0. In that case, don't unload.
    // if (currentUIData.maxWordLength != 0 
    //         && currentUIData.maxListLength != 0 
    //         && currentUIData.textXPosition != 0 
    //         && currentUIData.textYPosition != 0) 
    // {
    //     UnloadImage(currentUIData.uiFrame);
    //     UnloadTexture(currentUIData.uiTexture);
    // }
    currentUIData = &uiDataMap[currentUIState];

    if (currentUIState == ITEMS) {
        SetButtonsInventory();
    }
}

void UIEngine::SetButtonsInventory() {
    std::cout << "items" << std::endl;
    Player &player = *Player::GetInstance();
    std::vector<Button*> itemButtons = {};
    for (int i = 0; i < player.inventory.size(); i++) {
        itemButtons.push_back(new ItemButton(player.inventory[i], this));
    }
    SetButtons(itemButtons);
}

void UIEngine::SetButtonsCombat() {
    std::vector<Button*> b = {
            new AttackButton(this),
            new BlockButton(this),
            new MenuButton("DREAM", this),
            new MenuButton("ITEM", this)
        };
    SetButtons(b);
}

void UIEngine::SetButtonsSpecialAttack() {
    Player &player = *Player::GetInstance();
    std::vector<Button*> specialButtons = {};
    std::vector<Action> actions = player.GetActions();
    for (int i = 0; i < actions.size(); i++) {
        specialButtons.push_back(new SpecialAttackButton(GetActionName(actions[i]), this));
    }
    SetButtons(specialButtons);
}

void UIEngine::SetButtons(
        std::vector<Button*>& buttons) 
{
    currentUIData->selectedElement = 0;
    std::cout << "SetButtons " << currentUIData->scrollableList.size() << std::endl;
    for (int i = 0; i < currentUIData->scrollableList.size(); i++) {
        delete currentUIData->scrollableList[i];
    }
    currentUIData->scrollableList.clear();
    std::cout << "SetButtons After Delete" << currentUIData->scrollableList.size() << std::endl;
    for (int i = 0; i < buttons.size(); i++) {
        currentUIData->scrollableList.push_back(buttons[i]);
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
            break;
        case KEY_M:
            if (currentUIState == MENU) {
                Back();
            } else {
                escapeQueue.push_back(currentUIState);
                ChangeScreen(MENU);
            }
            
            break;
    }
    RenderUI();
}

Texture2D UIEngine::GetTexture(
        void)
{
    //Gets the texture so that main.cpp can render it
    return currentUIData->uiTexture;
}

void UIEngine::MoveUp()
{
    currentUIData->selectedElement--;
    if (currentUIData->selectedElement >= currentUIData->scrollableList.size())
    {
        currentUIData->selectedElement = currentUIData->scrollableList.size()-1;
    }
}

void UIEngine::MoveDown()
{
    currentUIData->selectedElement++;
    if (currentUIData->selectedElement >= currentUIData->scrollableList.size())
    {
        currentUIData->selectedElement = 0;
    }
}

void UIEngine::Confirm()
{
    // Confirm selection
    currentUIData->scrollableList[currentUIData->selectedElement]->confirmAction();
}

void UIEngine::Back()
{
    // Go back to previous screen
    currentUIData->scrollableList[currentUIData->selectedElement]->backAction();
}

void UIEngine::ExitMenu() {
    if (!escapeQueue.empty()) {
        ChangeScreen(escapeQueue.at(escapeQueue.size()-1));
        escapeQueue.pop_back();
    }
}

void UIEngine::RenderUI()
{
    Player &player = *Player::GetInstance();

    DrawTexture(GetTexture(), 0, 0, WHITE);

    Color currTextColor;

    // Draw the list of options
    for (int i = 0; i < currentUIData->scrollableList.size(); i++)
    {
        if (!inputEnabled) 
        {
            currTextColor = DREAM_GREY;
        }
        else if (i == currentUIData->selectedElement)
        {
            currTextColor = DREAM_RED;
        }
        else
        {
            currTextColor = DREAM_BLUE;
        }

        DrawTextEx(
                mainFont,
                currentUIData->scrollableList[i]->buttonText.c_str(),
                Vector2{ currentUIData->textXPosition, currentUIData->textYPosition + (i * 6) },
                6,
                1,
                currTextColor
                );
    }

    if (currentUIState == ITEMS) {
        if (player.inventory.size() > 0) {
            //Get the item description. Right now its the same as name.
            const char* description = GetItemName(player.inventory[currentUIData->selectedElement]);
            DrawTextEx(
                mainFont,
                description,
                Vector2{ 37.0f, 30.0f },
                6,
                1,
                DREAM_WHITE
                );
        }
    }

    //Display healthbars only if in battle (possibly add other UI states where health bars are shown)
    if (currentUIState == FIGHT || currentUIState == CHOOSE_NEXT_ENCOUNTER) {
        float healthPercentage = player.GetHealthPercentage();
        int healthBarLength = (int)(15 * healthPercentage);
        DrawRectangle(60, 17-healthBarLength, 1, healthBarLength, DREAM_RED);

        float sanityPercentage = player.GetManaPercentage();
        int sanityBarLength = (int)(15 * sanityPercentage);
        DrawRectangle(61, 17-sanityBarLength, 1, sanityBarLength, DREAM_BLUE);
    }    
}
