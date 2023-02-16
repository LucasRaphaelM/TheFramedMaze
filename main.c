#include "raylib.h"
#include "include/Map1.h"
#include <stdio.h>
#define GameScreenWidth 1280
#define GameScreenHeight 720

unsigned int nextFrameDataOffset = 0;  // Current byte offset to next frame in image.data
int currentAnimFrame = 0;       // Current animation frame to load and draw
int frameDelay = 3;             // Frame delay to switch between animation frames
int frameCounter = 0;           // General frames counter
int animFrames = 15;
int animacaoTecla = 0;
bool textoAnimado = false;
bool tocarGlitch = true;

int telas = 0;

void animacaoTeclas(Image KeyBindsAnim, Texture2D texKeyBindsAnim, Sound glitch);
int PlayerAnimation(Texture2D PlayerSprites, Rectangle PlayerSprite, int Nimagens);

int main(void)
{
    /*--------------------WINDOWS CONFIGURATION--------------------*/
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_TRANSPARENT);
    InitWindow(GameScreenWidth, GameScreenHeight, "THE FRAMED MAZE");
    SetWindowState(FLAG_WINDOW_UNDECORATED);
    /*-------------------------------------------------------------*/
    
    InitAudioDevice();

    Sound glitch = LoadSound("SFX/GlitchSoundFx.mp3");
    SetSoundVolume(glitch, 0.05);

    Image KeyBindsAnim = LoadImageAnim("resourcesAnimation/animation.gif", &animFrames);

    Texture2D texKeyBindsAnim = LoadTextureFromImage(KeyBindsAnim);

    Vector2 KeyBindsAnimPosition = { 500, 200 };


    SetTargetFPS(60);

    SetupScreen();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        switch(telas)
        {
            case 0:
                        //SetWindowState(FLAG_WINDOW_MOUSE_PASSTHROUGH);
                        animacaoTeclas(KeyBindsAnim, texKeyBindsAnim, glitch);
                        if(animacaoTecla == 2)
                        {
                            screenPosX = GetMonitorWidth(0)/2-ViewSizeWidth/2;
                            screenPosY = GetMonitorHeight(0)/2-ViewSizeHeight/2;
                        }
                        BeginDrawing();
                        ClearBackground(BLANK);
                        DrawTextureEx(texKeyBindsAnim, KeyBindsAnimPosition, 0, 1, WHITE);
                        EndDrawing();
                break;
            case 1:
                    ClearWindowState(FLAG_WINDOW_MOUSE_PASSTHROUGH);

                        Map1();
            break;
        }
        //----------------------------------------------------------------------------------ssssssssssssssssssssss
    }
    
    UnloadTexture(texKeyBindsAnim);

    UnloadImage(KeyBindsAnim);

    UnloadSound(glitch);

    CloseAudioDevice();
    CloseWindow();

    return 1;
}

void animacaoTeclas(Image KeyBindsAnim, Texture2D texKeyBindsAnim, Sound glitch)
{
    if(animacaoTecla == 0)
    {
        if(tocarGlitch)
        {
            PlaySound(glitch);
            tocarGlitch = false;
        }

        frameCounter++;

        if (frameCounter >= frameDelay)
        {

            currentAnimFrame++;

            if (currentAnimFrame >= animFrames)
            {
                nextFrameDataOffset = 14;
                currentAnimFrame = 14;
                frameDelay = 13;
                frameCounter = 14;
                animFrames = 15;
                animacaoTecla = 1;
                WaitTime(2);
                tocarGlitch = true;
            }

            nextFrameDataOffset = KeyBindsAnim.width*KeyBindsAnim.height*4*currentAnimFrame;

            UpdateTexture(texKeyBindsAnim, ((unsigned char *)KeyBindsAnim.data) + nextFrameDataOffset);

            frameCounter = 0;
        }
    }

    if(animacaoTecla == 1)
    {
        if(tocarGlitch)
        {
            PlaySound(glitch);
            tocarGlitch = false;
        }

        frameCounter--;

        if (frameCounter <= frameDelay)
        {
            currentAnimFrame--;

            if (currentAnimFrame == -1)
            {
                animacaoTecla = 2;
                currentAnimFrame = 14;
                WaitTime(0.5);
                telas = 1;
                //ClearWindowState(FLAG_WINDOW_UNDECORATED);
            }
            nextFrameDataOffset = KeyBindsAnim.width*KeyBindsAnim.height*4*currentAnimFrame;
            UpdateTexture(texKeyBindsAnim, ((unsigned char *)KeyBindsAnim.data) + nextFrameDataOffset);
            frameCounter = 15;
        }
    }
}
