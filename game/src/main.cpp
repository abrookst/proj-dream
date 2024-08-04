#include "raylib.h"
#include "audio_engine.cpp"

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
    AudioEngine engine;

    RenderTexture2D targetScene = LoadRenderTexture(lowRezWidth, lowRezHeight);
    SetTextureFilter(targetScene.texture, TEXTURE_FILTER_POINT);

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        float scale = MIN((float)GetScreenWidth() / lowRezWidth, (float)GetScreenHeight() / lowRezHeight);

        if (IsKeyPressed(KEY_SPACE)) engine.PlayMusic("test.mp3");
        if (IsKeyPressed(KEY_P)) engine.Pause("test.mp3");
        if (IsKeyPressed(KEY_S)) engine.Stop("test.mp3");
        if (IsKeyPressed(KEY_R)) engine.Restart("test.mp3");

        BeginTextureMode(targetScene);

            ClearBackground(RAYWHITE);

            DrawRectangle(2, 46, 60, 16, BLACK);
            DrawRectangle(0, 0, 1, 1, PURPLE);
            

            //DrawText("Test", 3, 48, 3, BLACK);
            DrawTextEx(mainFont, "ABCDEFGHIJKLMN\nOPQRSTUVWXYZ", Vector2{ 3, 47 }, 6, 1, WHITE);

        EndTextureMode();

        renderScene(targetScene, scale);

        engine.UpdateMusic();
        
    }

    UnloadFont(mainFont);
    
    CloseWindow();

    return 0;
}
