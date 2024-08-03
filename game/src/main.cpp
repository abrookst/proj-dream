#include "raylib.h"

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

        // Calculate the destination rectangle
        Rectangle destRect = {
            (GetScreenWidth() - (lowRezWidth * scale)) * 0.5f,
            (GetScreenHeight() - (lowRezHeight * scale)) * 0.5f,
            lowRezWidth * scale,
            lowRezHeight * scale
        };

        // Draw the texture with the given parameters
        DrawTexturePro(
            targetScene.texture,    // Texture to draw
            sourceRect,       // Source rectangle from the texture
            destRect,         // Destination rectangle on the screen
            Vector2{ 0, 0 },    // Origin of the texture (relative to source rectangle)
            0.0f,             // Rotation angle in degrees
            WHITE             // Tint color
        );
    EndDrawing();
}

int main (
    void)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "Proj Dream");

    int framesCounter = 0;

    //Font mainFont = LoadFont();

    RenderTexture2D targetScene = LoadRenderTexture(lowRezWidth, lowRezHeight);
    SetTextureFilter(targetScene.texture, TEXTURE_FILTER_POINT);

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        float scale = MIN((float)GetScreenWidth() / lowRezWidth, (float)GetScreenHeight() / lowRezHeight);

        BeginTextureMode(targetScene);

            ClearBackground(RAYWHITE);

            DrawRectangle(0, 0, 64, 64, BLUE);
            DrawCircle(32, 32, 32, RED);

        EndTextureMode();

        renderScene(targetScene, scale);
        
    }

    CloseWindow();

    return 0;
}