#include "raylib.h"
#include "include/Map1.h"
#include "resources.h/Keybinds.h"
#include <stdio.h>
#define GameScreenWidth 1280
#define GameScreenHeight 720

int telas = 0;
bool finaliza = false;

int main(void)
{
    int StarterWindowWidth = 0;
    int StarterWindowHeight = 0;

    /*--------------------WINDOWS CONFIGURATION--------------------*/
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(GameScreenWidth, GameScreenHeight, "THE FRAMED MAZE");
    SetWindowState(FLAG_WINDOW_UNDECORATED);
    /*-------------------------------------------------------------*/

    int iniciar = 0;

    Image Keybinds = { 0 };
        Keybinds.data = KEYBINDS_DATA;
        Keybinds.width = KEYBINDS_WIDTH;
        Keybinds.height = KEYBINDS_HEIGHT;
        Keybinds.format = KEYBINDS_FORMAT;
        Keybinds.mipmaps = 1;
    
    Rectangle KeybindsRec = { 0, 0, 398, 430};

    Texture2D KeybindsTexture = LoadTextureFromImage(Keybinds);

    Vector2 KeyBindsPosition = { 0, 0 };


    SetTargetFPS(60);

    SetupScreen();

    // Main game loop
    while (!finaliza)    // Detect window close button or ESC key
    {
        switch(telas)
        {
            case 0:
                DrawTextureRec(KeybindsTexture, KeybindsRec, KeyBindsPosition, WHITE);
                SetWindowPosition(screenPosX-300,screenPosY+100);
                SetWindowSize(StarterWindowWidth,StarterWindowHeight);

                if(iniciar < 100)
                {
                    if(StarterWindowWidth < 395)
                    {
                        StarterWindowWidth += 18;
                        screenPosX -= 7;
                    }
                    if(StarterWindowHeight < 419)
                    {
                        StarterWindowHeight += 20;
                        screenPosY -= 10;
                    }
                }

                if(iniciar > 350)
                {
                    if(StarterWindowWidth > 1 )
                    {
                        StarterWindowWidth -= 18;
                        screenPosX += 7;
                    }
                    if(StarterWindowHeight > 1 )
                    {
                        StarterWindowHeight -= 20;
                        screenPosY += 10;
                    }
                }

                iniciar++;
                if(IsKeyPressed(KEY_ESCAPE))
                    finaliza = true;
                if((IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) && iniciar < 350)
                    iniciar = 350;
                        if(iniciar == 400)
                        {
                            SetupScreen();
                            screenPosX = GetMonitorWidth(0)/2-ViewSizeWidth/2;
                            screenPosY = GetMonitorHeight(0)/2-ViewSizeHeight/2;
                            telas = 1;
                            UnloadTexture(KeybindsTexture);
                        }
                        BeginDrawing();
                        ClearBackground(BLANK);
                        EndDrawing();
                break;
            case 1:
                    ClearWindowState(FLAG_WINDOW_MOUSE_PASSTHROUGH);
                        if(IsKeyPressed(KEY_ESCAPE))
                            finaliza = true;
                        telas = Map1();
                break;
            case 2:
                SetWindowPosition(screenPosX,screenPosY);
                SetWindowSize(ViewSizeWidth,ViewSizeHeight);
                if(ViewSizeHeight>1)
                {
                    ViewSizeWidth -= 2;
                    ViewSizeHeight -= 2;
                    screenPosX += 1;
                    screenPosY +=1;
                }
                if(ViewSizeHeight == 0)
                    finaliza = true;
        }
        //----------------------------------------------------------------------------------ssssssssssssssssssssss
    }
    

    CloseWindow();

    return 1;
}