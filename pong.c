/*******************************************************************************************
*   raylib - Pong
********************************************************************************************/

#include "raylib.h"
#include <stdio.h>

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;
int screenWidth = 0;
int screenHeight = 0;
Rectangle pelota = {100, 100, 10, 10};
int xx = 5, yy = 5;
int left;
int right;
int top;
int bottom;

// Paint court.
void PaintCourt()
{
    left = 10;
    right = screenWidth - 10;
    top = 10;
    bottom = screenHeight - 10;

    // Bounds
    DrawRectangle(0, 0, screenWidth, top, GRAY);
    DrawRectangle(0, bottom, screenWidth, screenHeight, GRAY);
    DrawRectangle(0, 0, left, screenHeight, GRAY);
    DrawRectangle(right, 0, bottom, screenHeight, GRAY);

    // Half court.
    DrawRectangle((screenWidth/2) - 5, top, 10, bottom - 10, DARKGRAY);
}

// Start game.
int main(void)
{
    InitWindow(0, 0, "Pong");

    HideWindow();
    screenWidth = GetMonitorWidth(0) / 2;
    screenHeight = GetMonitorHeight(0) / 2;
    SetWindowSize(screenWidth, screenHeight);
    SetWindowPosition(screenWidth/2, screenHeight/2);
    UnhideWindow();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(BLACK);

            PaintCourt();
            if (!(pelota.x > left && pelota.x < right))
                xx = -xx;

            if (!(pelota.y > top && pelota.y < bottom))
                yy = -yy;

            pelota.x += xx;
            pelota.y += yy;
            DrawRectangle(pelota.x-5, pelota.y-5, 10, 10, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}