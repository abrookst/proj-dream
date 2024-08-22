// #include "encounter/battle_encounter.h"
#include "raylib.h"
#include "audio_engine.h"
#include "text_engine.h"
#include "game_manager.h"
#include <stdio.h>
#include <fstream>
#include "ui.h"

#include "entity/player.h"
#include "entity/monster.h"

#include "encounter/battle_encounter.h"

#include "action.h"
#include <vector>

#include "item.h"

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

const int lowRezWidth = 64;
const int lowRezHeight = 64;
const int screenWidth = 640;
const int screenHeight = 640;

//Takes in the final 64x64 image, and displays it on the screen
void renderScene(
    RenderTexture2D targetScene,
    float scale)
{
    BeginDrawing();
        ClearBackground(BLACK);

        Rectangle sourceRect = 
        { 
            0.0f, 
            0.0f,
            static_cast<float>(targetScene.texture.width), 
            -static_cast<float>(targetScene.texture.height) 
        };

        Rectangle destRect = {
            (GetScreenWidth() - (lowRezWidth * scale)) * 0.5f,
            (GetScreenHeight() - (lowRezHeight * scale)) * 0.5f,
            lowRezWidth * scale,
            lowRezHeight * scale
        };

        DrawTexturePro(
            targetScene.texture,
            sourceRect,
            destRect,
            Vector2{ 0, 0 },
            0.0f,
            WHITE
        );
    EndDrawing();
}

int main(
    void)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "Proj Dream");

    int framesCounter = 0;

    Font mainFont = LoadFontEx("./resources/fonts/mainfont.ttf", 6, 0, 0);
    AudioEngine audioEngine;
    UIEngine uiEngine = UIEngine(mainFont);
    TextEngine textEngine(mainFont, uiEngine);
    GameManager gameManager = GameManager();

    uiEngine.ChangeScreen(TITLESCREEN);
    uiEngine.SetInputEnabled(true);

    Player player = Player(50, 5, 95, 20, { ATTACK, BLOCK }, ":3");

    //Default items for testing inventory mechanics
    player.inventory.push_back(BANDAGE);
    player.inventory.push_back(PILLS);

    RenderTexture2D targetScene = LoadRenderTexture(lowRezWidth, lowRezHeight);
    SetTextureFilter(targetScene.texture, TEXTURE_FILTER_POINT);

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {

        if (IsKeyPressed(KEY_SPACE)) { audioEngine.PlayMusic("test.mp3"); }

        if (IsKeyPressed(KEY_UP)) { uiEngine.ProcessInputKeyboard(KEY_UP); }
        if (IsKeyPressed(KEY_DOWN)) {  uiEngine.ProcessInputKeyboard(KEY_DOWN); }
        if (IsKeyPressed(KEY_ENTER)) { uiEngine.ProcessInputKeyboard(KEY_ENTER); }
        if (IsKeyPressed(KEY_BACKSPACE)) { uiEngine.ProcessInputKeyboard(KEY_BACKSPACE); }

        BeginTextureMode(targetScene);

            ClearBackground(RAYWHITE);

            DrawRectangle(2, 46, 60, 16, BLACK);
            DrawRectangle(0, 0, 1, 1, PURPLE);
            
            uiEngine.RenderUI();

            if (IsKeyPressed(KEY_ENTER)) { textEngine.UpdateText(true); }
            else { textEngine.UpdateText(false); }

        EndTextureMode();

        audioEngine.UpdateAudio();

        float scale = MIN((float)GetScreenWidth() / lowRezWidth, (float)GetScreenHeight() / lowRezHeight);
        renderScene(targetScene, scale);
    }

    for ( Monster* m : GameManager::GetInstance()->monsters ) { delete m; }

    UnloadFont(mainFont);
    
    CloseWindow();

    return 0;
}
