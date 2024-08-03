#include "raylib.h"

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

int main(void)
{
    const int lowRezWidth = 64;
    const int lowRezHeight = 64;
    const int screenWidth = 640;
    const int screenHeight = 640;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "Proj Dream");

    int framesCounter = 0;

    RenderTexture2D target = LoadRenderTexture(lowRezWidth, lowRezHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        float scale = MIN((float)GetScreenWidth() / lowRezWidth, (float)GetScreenHeight() / lowRezHeight);

        BeginTextureMode(target);

        ClearBackground(RAYWHITE);

        DrawRectangle(0, 0, 64, 64, BLUE);
        DrawCircle(32, 32, 32, RED);

        EndTextureMode();

        BeginDrawing();
        ClearBackground(BLACK);

        DrawTexturePro(target.texture, (Rectangle) { 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },
            (Rectangle) {
            (GetScreenWidth() - ((float)lowRezWidth * scale)) * 0.5f, (GetScreenHeight() - ((float)lowRezHeight * scale)) * 0.5f,
                (float)lowRezWidth* scale, (float)lowRezHeight* scale
        }, (Vector2) { 0, 0 }, 0.0f, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}