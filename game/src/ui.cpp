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
}

void UIEngine::ChangeScreen(UIState state)
{
    currentUIState = state;
    //If currentUIData is uninitialized, all number values will be 0. In that case, don't unload.
    if (currentUIData.maxWordLength != 0 
            && currentUIData.maxListLength != 0 
            && currentUIData.textXPosition != 0 
            && currentUIData.textYPosition != 0) 
    {
        UnloadImage(currentUIData.uiFrame);
        UnloadTexture(currentUIData.uiTexture);
    }
    

    switch(state)
    {
        case DAYTIMEWORLD:
        case DAYTIMEPLAYER:
        case FIGHT:
            currentUIData = {
                LoadImage("resources/sprites/UI/DREAMWORLD.png"),
                LoadTextureFromImage(LoadImage("resources/sprites/UI/DREAMWORLD.png")),
                5,
                10,
                43.0f,
                19.0f,
                {
                    new AttackButton(this),
                    new BlockButton(this),
                    new TalkButton(this),
                    new MenuButton("MENU", this)
                },
                0
            };
            break;
        case CHOOSE_NEXT_ENCOUNTER:
            currentUIData = {
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
            break;
        case DREAMWORLD:
        case DREAMPLAYER:
            currentUIData = {
                LoadImage("resources/sprites/UI/DREAMPLAYER.png"),
                LoadTextureFromImage(LoadImage("resources/sprites/UI/DREAMPLAYER.png")),
                5,
                10,
                43.0f,
                19.0f,
                {
                    new AttackButton(this),
                    new BlockButton(this),
                    new TalkButton(this),
                    new MenuButton("MENU", this)
                },
                0
            };
            break;
        case MENU:
            currentUIData = {
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
            break;
        case STATS:
        case MAGIC:
        case ABILITY:
        case WEAPON:
        case EQUIP:
        case ITEMS:
            currentUIData = {
                LoadImage("resources/sprites/UI/ITEMS.png"),
                LoadTextureFromImage(LoadImage("resources/sprites/UI/ITEMS.png")),
                0,
                0,
                20.0f,
                20.0f,
                {
                    new MenuButton("USE", this),
                    new MenuButton("INFO", this),
                    new MenuButton("BACK", this),
                },
                0
            };
            break;
        case INALIDSTATE:
        case TITLESCREEN:
            currentUIData = {
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
            break;
        case SETTINGS:
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
            break;
        case KEY_M:
            ChangeScreen(MENU);
            break;
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
    currentUIData.scrollableList[currentUIData.selectedElement]->confirmAction();
}

void UIEngine::Back()
{
    // Go back to previous screen
    currentUIData.scrollableList[currentUIData.selectedElement]->backAction();
}

void UIEngine::RenderUI()
{
    DrawTexture(GetTexture(), 0, 0, WHITE);

    Color currTextColor;

    // Draw the list of options
    for (int i = 0; i < currentUIData.scrollableList.size(); i++)
    {
        if (!inputEnabled) 
        {
            currTextColor = DREAM_GREY;
        }
        else if (i == currentUIData.selectedElement)
        {
            currTextColor = DREAM_RED;
        }
        else
        {
            currTextColor = DREAM_BLUE;
        }

        DrawTextEx(
                mainFont,
                currentUIData.scrollableList[i]->buttonText.c_str(),
                Vector2{ currentUIData.textXPosition, currentUIData.textYPosition + (i * 6) },
                6,
                1,
                currTextColor
                );
    }
}
