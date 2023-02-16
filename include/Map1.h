#include "raylib.h"
#include "WindowScreenConfig.h"
#include "WallHitBoxesMap.h"
#include "../SpritesPlayer.h/AllPlayerSprites.h"
#include "../Maps.h/AllMaps.h"

int PlayerAnimation(Texture2D PlayerSprites, Rectangle PlayerSprite,int Nimagens);

/*---------------------IDLE BOOLS---------------------*/
    bool BLeftIdle = false;
    bool BRightIdle = false;
    bool BUpIdle = false;
    bool BDownIdle = true;
/*----------------------------------------------------*/


/*----------PLAYER POSITION AND PLAYER HITBOX----------*/
    Vector2 PlayerPosition = { 68, 68 };
    Rectangle Player = { 88, 105, 24, 15 };
/*-----------------------------------------------------*/


/*--------------------BACKGROUND STARTER POSITION--------------------*/
    Vector2 fundo = {-700,-400};
/*-------------------------------------------------------------------*/


/*--------------------------PLAYER ANIMATION CONTROL-------------------------*/
    int CurrentFramePlayer = 0;
    int framesCounterPlayer = 0;
    int frameSpeed = 7;
/*---------------------------------------------------------------------------*/

/*-----------------------PLAYER SPEED-----------------------*/
    float PlayerSpeed = 60.0;
/*----------------------------------------------------------*/


Rectangle PlayerSprite[8];
bool AnimationPositionStarter = true;
bool GetBigger = true;


int Map1(void)
{
    int i = 0;

/*----------------------LOAD BACKGROUND IMG----------------------*/
    Image FundoMapa = { 0 };
        FundoMapa.data = FUNDOMAPA_DATA;
        FundoMapa.width = FUNDOMAPA_WIDTH;
        FundoMapa.height = FUNDOMAPA_HEIGHT;
        FundoMapa.format = FUNDOMAPA_FORMAT;
        FundoMapa.mipmaps = 1;
    Image FundoMapaAcimaPlayer = { 0 };
        FundoMapaAcimaPlayer.data = FUNDOMAPAACIMAPLAYER_DATA;
        FundoMapaAcimaPlayer.width = FUNDOMAPAACIMAPLAYER_WIDTH;
        FundoMapaAcimaPlayer.height = FUNDOMAPAACIMAPLAYER_HEIGHT;
        FundoMapaAcimaPlayer.format = FUNDOMAPAACIMAPLAYER_FORMAT;
        FundoMapaAcimaPlayer.mipmaps = 1;
/*---------------------------------------------------------------*/


/*----------------------LOAD BACKGROUND----------------------*/
Texture2D Fundo[2] = {LoadTextureFromImage(FundoMapa),
                      LoadTextureFromImage(FundoMapaAcimaPlayer)};
/*-----------------------------------------------------------*/


/*--------------------LOAD PLAYER SPRITES--------------------*/

    Image DownIdle = { 0 };
        DownIdle.data = DOWNIDLE_DATA;
        DownIdle.width = DOWNIDLE_WIDTH;
        DownIdle.height = DOWNIDLE_HEIGHT;
        DownIdle.format = DOWNIDLE_FORMAT;
        DownIdle.mipmaps = 1;


    Image DownWalk = { 0 };
        DownWalk.data = DOWNWALK_DATA;
        DownWalk.width = DOWNWALK_WIDTH;
        DownWalk.height = DOWNWALK_HEIGHT;
        DownWalk.format = DOWNWALK_FORMAT;
        DownWalk.mipmaps = 1;

    Image LeftIdle = { 0 };
        LeftIdle.data = LEFTIDLE_DATA;
        LeftIdle.width = LEFTIDLE_WIDTH;
        LeftIdle.height = LEFTIDLE_HEIGHT;
        LeftIdle.format = LEFTIDLE_FORMAT;
        LeftIdle.mipmaps = 1;

    Image LeftSideWalk = { 0 };
        LeftSideWalk.data = LEFTSIDEWALK_DATA;
        LeftSideWalk.width = LEFTSIDEWALK_WIDTH;
        LeftSideWalk.height = LEFTSIDEWALK_HEIGHT;
        LeftSideWalk.format = LEFTSIDEWALK_FORMAT;
        LeftSideWalk.mipmaps = 1;

    Image RightIdle = { 0 };
        RightIdle.data = RIGHTIDLE_DATA;
        RightIdle.width = RIGHTIDLE_WIDTH;
        RightIdle.height = RIGHTIDLE_HEIGHT;
        RightIdle.format = RIGHTIDLE_FORMAT;
        RightIdle.mipmaps = 1;

    Image RightSideWalk = { 0 };
        RightSideWalk.data = RIGHTSIDEWALK_DATA;
        RightSideWalk.width = RIGHTSIDEWALK_WIDTH;
        RightSideWalk.height = RIGHTSIDEWALK_HEIGHT;
        RightSideWalk.format = RIGHTSIDEWALK_FORMAT;
        RightSideWalk.mipmaps = 1;

    Image UpIdle = { 0 };
        UpIdle.data = UPIDLE_DATA;
        UpIdle.width = UPIDLE_WIDTH;
        UpIdle.height = UPIDLE_HEIGHT;
        UpIdle.format = UPIDLE_FORMAT;
        UpIdle.mipmaps = 1;

    Image UpWalk = { 0 };
        UpWalk.data = UPWALK_DATA;
        UpWalk.width = UPWALK_WIDTH;
        UpWalk.height = UPWALK_HEIGHT;
        UpWalk.format = UPWALK_FORMAT;
        UpWalk.mipmaps = 1;

    Texture2D PlayerSprites[8] = {LoadTextureFromImage(LeftSideWalk),
                                  LoadTextureFromImage(LeftIdle),
                                  LoadTextureFromImage(RightSideWalk),
                                  LoadTextureFromImage(RightIdle),
                                  LoadTextureFromImage(UpWalk),
                                  LoadTextureFromImage(UpIdle),
                                  LoadTextureFromImage(DownWalk),
                                  LoadTextureFromImage(DownIdle)};
/*--------------------------------------------------------------*/



/*-------------------------------------------SPRITES COORDENATES--------------------------------------------------*/
if(AnimationPositionStarter)
{
    for(i = 0; i < 8; i++)
    {
        PlayerSprite[i].x = 0;
        PlayerSprite[i].y = 0;
        PlayerSprite[i].height = (float)PlayerSprites[i].height;
        if(i % 2 == 0)
            PlayerSprite[i].width = (float)PlayerSprites[i].width/6;
        else
            PlayerSprite[i].width = (float)PlayerSprites[i].width/5;
    }
    AnimationPositionStarter = false;
}
/*----------------------------------------------------------------------------------------------------------------*/

    SetWindowPosition( screenPosX, screenPosY);
    SetWindowSize(ViewSizeWidth, ViewSizeHeight);

/*------------------------------WALLS COLLISIONS------------------------------*/
    Rectangle WallsBOTTOM[3] = { posXBOTTOM[0], posYBOTTOM[0], WidthWallHori[0], 3,
                                 posXBOTTOM[1], posYBOTTOM[1], WidthWallHori[1], 3,
                                 posXBOTTOM[2], posYBOTTOM[2], WidthWallHori[2], 3};

    Rectangle WallsTOP[3] = { posXTOP[0], posYTOP[0], WidthWallHori[0], 3,
                              posXTOP[1], posYTOP[1], WidthWallHori[1], 3,
                              posXTOP[2], posYTOP[2], WidthWallHori[2], 3};

    Rectangle WallsLEFT[3] = { posXLEFT[0], posYLEFT[0], 3, HeightWallVert[0],
                               posXLEFT[1], posYLEFT[1], 3, HeightWallVert[1],
                               posXLEFT[2], posYLEFT[2], 3, HeightWallVert[2]};

    Rectangle WallsRIGHT[3] = { posXRIGHT[0], posYRIGHT[0], 3, HeightWallVert[0],
                                posXRIGHT[1], posYRIGHT[1], 3, HeightWallVert[1],
                                posXRIGHT[2], posYRIGHT[2], 3, HeightWallVert[2]};
/*-----------------------------------------------------------------------------*/

/*-----------------CHECKING PLAYER COLLISION WITH WALLS------------------*/
   /*for(i = 0; i < 3; i++)
    {
        WallsTOP[i].x = posXTOP[i];
        WallsTOP[i].y = posYTOP[i];
        WallsTOP[i].width = WidthWallHori[i];

        WallsBOTTOM[i].x = posXBOTTOM[i];
        WallsBOTTOM[i].y = posYBOTTOM[i];
        WallsBOTTOM[i].width = WidthWallHori[i];  

        WallsLEFT[i].x = posXLEFT[i];
        WallsLEFT[i].y = posYLEFT[i];
        WallsLEFT[i].height = HeightWallVert[i];

        WallsRIGHT[i].x = posXRIGHT[i];
        WallsRIGHT[i].y = posYRIGHT[i];
        WallsRIGHT[i].height = HeightWallVert[i];
    }*/
    for(i = 0; i < 3; i++)
    {
        WallsTOP[i].x = posXTOP[i];
        WallsTOP[i].y = posYTOP[i];
        WallsTOP[i].width = WidthWallHori[i];
        CollisionTOP = CheckCollisionRecs(Player, WallsTOP[i]);
        if(CollisionTOP)
            break;
    }
    for(i = 0; i < 3; i++)
    {
        WallsBOTTOM[i].x = posXBOTTOM[i];
        WallsBOTTOM[i].y = posYBOTTOM[i];
        WallsBOTTOM[i].width = WidthWallHori[i];
        CollisionBOTTOM = CheckCollisionRecs(Player, WallsBOTTOM[i]);
        if(CollisionBOTTOM)
            break;
    }
    for(i = 0; i < 3; i++)
    {
        WallsLEFT[i].x = posXLEFT[i];
        WallsLEFT[i].y = posYLEFT[i];
        WallsLEFT[i].height = HeightWallVert[i];
        CollisionLEFT = CheckCollisionRecs(Player, WallsLEFT[i]);
        if(CollisionLEFT)
            break;
    }
    for(i = 0; i < 3; i++)
    {
        WallsRIGHT[i].x = posXRIGHT[i];
        WallsRIGHT[i].y = posYRIGHT[i];
        WallsRIGHT[i].height = HeightWallVert[i];
        CollisionRIGHT = CheckCollisionRecs(Player, WallsRIGHT[i]);
        if(CollisionRIGHT)
            break;
    }
/*-----------------------------------------------------------------------------------*/

    


    if((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && !CollisionLEFT)
    {
        for(i = 0; i < 3; i++)
        {
            posXTOP[i] -= PlayerSpeed*GetFrameTime();
            posXBOTTOM[i] -= PlayerSpeed*GetFrameTime();
            posXLEFT[i] -= PlayerSpeed*GetFrameTime();
            posXRIGHT[i] -= PlayerSpeed*GetFrameTime();
        }
        fundo.x -= PlayerSpeed*GetFrameTime();
        screenPosX += PlayerSpeed*GetFrameTime();
        BRightIdle = true;
        BLeftIdle = false;
        BUpIdle = false;
        BDownIdle = false;
    }


    if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && !CollisionRIGHT)
    {
        for(i = 0; i < 3; i++)
        {
            posXTOP[i] += PlayerSpeed*GetFrameTime();
            posXBOTTOM[i] += PlayerSpeed*GetFrameTime();
            posXLEFT[i] += PlayerSpeed*GetFrameTime();
            posXRIGHT[i] += PlayerSpeed*GetFrameTime();
        }
        fundo.x += PlayerSpeed*GetFrameTime();
        screenPosX -= PlayerSpeed*GetFrameTime();
        BLeftIdle = true;
        BRightIdle = false;
        BUpIdle = false;
        BDownIdle = false;
    }


    if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && !CollisionBOTTOM)
    {
        for(i = 0; i < 3; i++)
        {
            posYTOP[i] += PlayerSpeed*GetFrameTime();
            posYBOTTOM[i] += PlayerSpeed*GetFrameTime();
            posYLEFT[i] += PlayerSpeed*GetFrameTime();
            posYRIGHT[i] += PlayerSpeed*GetFrameTime();
        }
        fundo.y += PlayerSpeed*GetFrameTime();
        screenPosY -= PlayerSpeed*GetFrameTime();
        BUpIdle = true;
        BLeftIdle = false;
        BRightIdle = false;
        BDownIdle = false;
    }


    if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && !CollisionTOP)
    {
        for(i = 0; i < 3; i++)
        {
            posYTOP[i] -= PlayerSpeed*GetFrameTime();
            posYBOTTOM[i] -= PlayerSpeed*GetFrameTime();
            posYLEFT[i] -= PlayerSpeed*GetFrameTime();
            posYRIGHT[i] -= PlayerSpeed*GetFrameTime();
        }
        fundo.y -= PlayerSpeed*GetFrameTime();
        screenPosY += PlayerSpeed*GetFrameTime();
        BDownIdle = true;
        BLeftIdle = false;
        BRightIdle = false;
        BUpIdle = false;
    }


    if (IsKeyDown(KEY_SPACE) && GetBigger)
    {
        ViewSizeWidth += 50;
        ViewSizeHeight += 50;
        screenPosX -= 25;
        screenPosY -= 25;
        Player.x = 113;
        Player.y = 130;
        Player.width = 24;
        Player.height = 15; 
        PlayerPosition.x = 93;
        PlayerPosition.y = 93;
        fundo.x += 25;
        fundo.y +=25;
        for(i = 0; i < 3; i++)
        {
            posXTOP[i] += 25;
            posXBOTTOM[i] += 25;
            posXLEFT[i] += 25;
            posXRIGHT[i] += 25;
            posYTOP[i] += 25;
            posYBOTTOM[i] += 25;
            posYLEFT[i] += 25;
            posYRIGHT[i] += 25;
        }
        GetBigger = false;
    }

    BeginDrawing();
    DrawTextureV(Fundo[0], fundo, WHITE);
    if(IsKeyDown(KEY_A))
    {
        PlayerSprite[0].x = PlayerAnimation(PlayerSprites[0],PlayerSprite[0], 6);
        DrawTextureRec(PlayerSprites[0], PlayerSprite[0], PlayerPosition, WHITE);
    }


    else if(!IsKeyDown(KEY_A) && BLeftIdle)
    {
        PlayerSprite[1].x = PlayerAnimation(PlayerSprites[1],PlayerSprite[1], 5);
        DrawTextureRec(PlayerSprites[1], PlayerSprite[1], PlayerPosition, WHITE);
    }


    else if(IsKeyDown(KEY_D))
    {
        PlayerSprite[2].x = PlayerAnimation(PlayerSprites[2],PlayerSprite[2], 6);
        DrawTextureRec(PlayerSprites[2], PlayerSprite[2], PlayerPosition, WHITE);
    }


    else if(!IsKeyDown(KEY_D) && BRightIdle)
    {
        PlayerSprite[3].x = PlayerAnimation(PlayerSprites[3],PlayerSprite[3], 5);
        DrawTextureRec(PlayerSprites[3], PlayerSprite[3], PlayerPosition, WHITE);
    }


    else if(IsKeyDown(KEY_W))
    {
        PlayerSprite[4].x = PlayerAnimation(PlayerSprites[4],PlayerSprite[4], 6);
        DrawTextureRec(PlayerSprites[4], PlayerSprite[4], PlayerPosition, WHITE);
    }


    else if(!IsKeyDown(KEY_W) && BUpIdle)
    {
        PlayerSprite[5].x = PlayerAnimation(PlayerSprites[5],PlayerSprite[5], 5);
        DrawTextureRec(PlayerSprites[5], PlayerSprite[5], PlayerPosition, WHITE);
    }


    else if(IsKeyDown(KEY_S))
    {
        PlayerSprite[6].x = PlayerAnimation(PlayerSprites[6],PlayerSprite[6], 6);
        DrawTextureRec(PlayerSprites[6], PlayerSprite[6], PlayerPosition, WHITE);
    }


    else if(!IsKeyDown(KEY_S) && BDownIdle)
    {
        PlayerSprite[7].x = PlayerAnimation(PlayerSprites[7],PlayerSprite[7], 5);
        DrawTextureRec(PlayerSprites[7], PlayerSprite[7], PlayerPosition, WHITE);
    }

    for(i = 0; i < 3; i++)
    {
        DrawRectangleRec(WallsTOP[i],MAROON);
        DrawRectangleRec(WallsBOTTOM[i],MAROON);
        DrawRectangleRec(WallsLEFT[i],MAROON);
        DrawRectangleRec(WallsRIGHT[i],MAROON);
    }

    DrawTextureV(Fundo[1], fundo, WHITE);
    EndDrawing();
    for(i = 0; i < 9; i++)
        UnloadTexture(PlayerSprites[i]);
    UnloadTexture(Fundo[0]);
    UnloadTexture(Fundo[1]);

    return 1;
}

int PlayerAnimation(Texture2D PlayerSprites, Rectangle PlayerSprite,int Nimagens)
{
    framesCounterPlayer++;

        if (framesCounterPlayer >= (60/frameSpeed))
        {
            framesCounterPlayer = 0;
            CurrentFramePlayer++;

            if (CurrentFramePlayer > Nimagens-1) CurrentFramePlayer = 0;

            PlayerSprite.x = (float)CurrentFramePlayer*(float)PlayerSprites.width/Nimagens;
        }
        return PlayerSprite.x;
}