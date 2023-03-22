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
    int TextBlinkingAmination = 0;
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
    int QWallsTop = 59;
    int QWallsBottom = 63;
    int QWallsLeft = 58;
    int QWallsRight = 63;
    int MostWallsQuantity = 63;

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
    Rectangle WallsBOTTOM[63] = { posXBOTTOM[0], posYBOTTOM[0], WidthWallHoriB[0], 3,
                                 posXBOTTOM[1], posYBOTTOM[1], WidthWallHoriB[1], 3,
                                 posXBOTTOM[2], posYBOTTOM[2], WidthWallHoriB[2], 3,
                                 posXBOTTOM[3], posYBOTTOM[3], WidthWallHoriB[3], 3,
                                 posXBOTTOM[4], posYBOTTOM[4], WidthWallHoriB[4], 3,
                                 posXBOTTOM[5], posYBOTTOM[5], WidthWallHoriB[5], 3,
                                 posXBOTTOM[6], posYBOTTOM[6], WidthWallHoriB[6], 3,
                                 posXBOTTOM[7], posYBOTTOM[7], WidthWallHoriB[7], 3,
                                 posXBOTTOM[8], posYBOTTOM[8], WidthWallHoriB[8], 3,
                                 posXBOTTOM[9], posYBOTTOM[9], WidthWallHoriB[9], 3,
                                 posXBOTTOM[10], posYBOTTOM[10], WidthWallHoriB[10], 3,
                                 posXBOTTOM[11], posYBOTTOM[11], WidthWallHoriB[11], 3,
                                 posXBOTTOM[12], posYBOTTOM[12], WidthWallHoriB[12], 3,
                                 posXBOTTOM[13], posYBOTTOM[13], WidthWallHoriB[13], 3,
                                 posXBOTTOM[14], posYBOTTOM[14], WidthWallHoriB[14], 3,
                                 posXBOTTOM[15], posYBOTTOM[15], WidthWallHoriB[15], 3,
                                 posXBOTTOM[16], posYBOTTOM[16], WidthWallHoriB[16], 3,
                                 posXBOTTOM[17], posYBOTTOM[17], WidthWallHoriB[17], 3,
                                 posXBOTTOM[18], posYBOTTOM[18], WidthWallHoriB[18], 3,
                                 posXBOTTOM[19], posYBOTTOM[19], WidthWallHoriB[19], 3,
                                 posXBOTTOM[20], posYBOTTOM[20], WidthWallHoriB[20], 3,
                                 posXBOTTOM[21], posYBOTTOM[21], WidthWallHoriB[21], 3,
                                 posXBOTTOM[22], posYBOTTOM[22], WidthWallHoriB[22], 3,
                                 posXBOTTOM[23], posYBOTTOM[23], WidthWallHoriB[23], 3,
                                 posXBOTTOM[24], posYBOTTOM[24], WidthWallHoriB[24], 3,
                                 posXBOTTOM[25], posYBOTTOM[25], WidthWallHoriB[25], 3,
                                 posXBOTTOM[26], posYBOTTOM[26], WidthWallHoriB[26], 3,
                                 posXBOTTOM[27], posYBOTTOM[27], WidthWallHoriB[27], 3,
                                 posXBOTTOM[28], posYBOTTOM[28], WidthWallHoriB[28], 3,
                                 posXBOTTOM[29], posYBOTTOM[29], WidthWallHoriB[29], 3,
                                 posXBOTTOM[30], posYBOTTOM[30], WidthWallHoriB[30], 3,
                                 posXBOTTOM[31], posYBOTTOM[31], WidthWallHoriB[31], 3,
                                 posXBOTTOM[32], posYBOTTOM[32], WidthWallHoriB[32], 3,
                                 posXBOTTOM[33], posYBOTTOM[33], WidthWallHoriB[33], 3,
                                 posXBOTTOM[34], posYBOTTOM[34], WidthWallHoriB[34], 3,
                                 posXBOTTOM[35], posYBOTTOM[35], WidthWallHoriB[35], 3,
                                 posXBOTTOM[36], posYBOTTOM[36], WidthWallHoriB[36], 3,
                                 posXBOTTOM[37], posYBOTTOM[37], WidthWallHoriB[37], 3,
                                 posXBOTTOM[38], posYBOTTOM[38], WidthWallHoriB[38], 3,
                                 posXBOTTOM[39], posYBOTTOM[39], WidthWallHoriB[39], 3,
                                 posXBOTTOM[40], posYBOTTOM[40], WidthWallHoriB[40], 3,
                                 posXBOTTOM[41], posYBOTTOM[41], WidthWallHoriB[41], 3,
                                 posXBOTTOM[42], posYBOTTOM[42], WidthWallHoriB[42], 3,
                                 posXBOTTOM[43], posYBOTTOM[43], WidthWallHoriB[43], 3,
                                 posXBOTTOM[44], posYBOTTOM[44], WidthWallHoriB[44], 3,
                                 posXBOTTOM[45], posYBOTTOM[45], WidthWallHoriB[45], 3,
                                 posXBOTTOM[46], posYBOTTOM[46], WidthWallHoriB[46], 3,
                                 posXBOTTOM[47], posYBOTTOM[47], WidthWallHoriB[47], 3,
                                 posXBOTTOM[48], posYBOTTOM[48], WidthWallHoriB[48], 3,
                                 posXBOTTOM[49], posYBOTTOM[49], WidthWallHoriB[49], 3,
                                 posXBOTTOM[50], posYBOTTOM[50], WidthWallHoriB[50], 3,
                                 posXBOTTOM[51], posYBOTTOM[51], WidthWallHoriB[51], 3,
                                 posXBOTTOM[52], posYBOTTOM[52], WidthWallHoriB[52], 3,
                                 posXBOTTOM[53], posYBOTTOM[53], WidthWallHoriB[53], 3,
                                 posXBOTTOM[54], posYBOTTOM[54], WidthWallHoriB[54], 3,
                                 posXBOTTOM[55], posYBOTTOM[55], WidthWallHoriB[55], 3,
                                 posXBOTTOM[56], posYBOTTOM[56], WidthWallHoriB[56], 3,
                                 posXBOTTOM[57], posYBOTTOM[57], WidthWallHoriB[57], 3,
                                 posXBOTTOM[58], posYBOTTOM[58], WidthWallHoriB[58], 3,
                                 posXBOTTOM[59], posYBOTTOM[59], WidthWallHoriB[59], 3,
                                 posXBOTTOM[60], posYBOTTOM[60], WidthWallHoriB[60], 3,
                                 posXBOTTOM[61], posYBOTTOM[61], WidthWallHoriB[61], 3,
                                 posXBOTTOM[62], posYBOTTOM[62], WidthWallHoriB[62], 3};

    Rectangle WallsTOP[59] = { posXTOP[0], posYTOP[0], WidthWallHoriT[0], 3,
                              posXTOP[1], posYTOP[1], WidthWallHoriT[1], 3,
                              posXTOP[2], posYTOP[2], WidthWallHoriT[2], 3,
                              posXTOP[3], posYTOP[3], WidthWallHoriT[3], 3,
                              posXTOP[4], posYTOP[4], WidthWallHoriT[4], 3,
                              posXTOP[5], posYTOP[5], WidthWallHoriT[5], 3,
                              posXTOP[6], posYTOP[6], WidthWallHoriT[6], 3,
                              posXTOP[7], posYTOP[7], WidthWallHoriT[7], 3,
                              posXTOP[8], posYTOP[8], WidthWallHoriT[8], 3,
                              posXTOP[9], posYTOP[9], WidthWallHoriT[9], 3,
                              posXTOP[10], posYTOP[10], WidthWallHoriT[10], 3,
                              posXTOP[11], posYTOP[11], WidthWallHoriT[11], 3,
                              posXTOP[12], posYTOP[12], WidthWallHoriT[12], 3,
                              posXTOP[13], posYTOP[13], WidthWallHoriT[13], 3,
                              posXTOP[14], posYTOP[14], WidthWallHoriT[14], 3,
                              posXTOP[15], posYTOP[15], WidthWallHoriT[15], 3,
                              posXTOP[16], posYTOP[16], WidthWallHoriT[16], 3,
                              posXTOP[17], posYTOP[17], WidthWallHoriT[17], 3,
                              posXTOP[18], posYTOP[18], WidthWallHoriT[18], 3,
                              posXTOP[19], posYTOP[19], WidthWallHoriT[19], 3,
                              posXTOP[20], posYTOP[20], WidthWallHoriT[20], 3,
                              posXTOP[21], posYTOP[21], WidthWallHoriT[21], 3,
                              posXTOP[22], posYTOP[22], WidthWallHoriT[22], 3,
                              posXTOP[23], posYTOP[23], WidthWallHoriT[23], 3,
                              posXTOP[24], posYTOP[24], WidthWallHoriT[24], 3,
                              posXTOP[25], posYTOP[25], WidthWallHoriT[25], 3,
                              posXTOP[26], posYTOP[26], WidthWallHoriT[26], 3,
                              posXTOP[27], posYTOP[27], WidthWallHoriT[27], 3,
                              posXTOP[28], posYTOP[28], WidthWallHoriT[28], 3,
                              posXTOP[29], posYTOP[29], WidthWallHoriT[29], 3,
                              posXTOP[30], posYTOP[30], WidthWallHoriT[30], 3,
                              posXTOP[31], posYTOP[31], WidthWallHoriT[31], 3,
                              posXTOP[32], posYTOP[32], WidthWallHoriT[32], 3,
                              posXTOP[33], posYTOP[33], WidthWallHoriT[33], 3,
                              posXTOP[34], posYTOP[34], WidthWallHoriT[34], 3,
                              posXTOP[35], posYTOP[35], WidthWallHoriT[35], 3,
                              posXTOP[36], posYTOP[36], WidthWallHoriT[36], 3,
                              posXTOP[37], posYTOP[37], WidthWallHoriT[37], 3,
                              posXTOP[38], posYTOP[38], WidthWallHoriT[38], 3,
                              posXTOP[39], posYTOP[39], WidthWallHoriT[39], 3,
                              posXTOP[40], posYTOP[40], WidthWallHoriT[40], 3,
                              posXTOP[41], posYTOP[41], WidthWallHoriT[41], 3,
                              posXTOP[42], posYTOP[42], WidthWallHoriT[42], 3,
                              posXTOP[43], posYTOP[43], WidthWallHoriT[43], 3,
                              posXTOP[44], posYTOP[44], WidthWallHoriT[44], 3,
                              posXTOP[45], posYTOP[45], WidthWallHoriT[45], 3,
                              posXTOP[46], posYTOP[46], WidthWallHoriT[46], 3,
                              posXTOP[47], posYTOP[47], WidthWallHoriT[47], 3,
                              posXTOP[48], posYTOP[48], WidthWallHoriT[48], 3,
                              posXTOP[49], posYTOP[49], WidthWallHoriT[49], 3,
                              posXTOP[50], posYTOP[50], WidthWallHoriT[50], 3,
                              posXTOP[51], posYTOP[51], WidthWallHoriT[51], 3,
                              posXTOP[52], posYTOP[52], WidthWallHoriT[52], 3,
                              posXTOP[53], posYTOP[53], WidthWallHoriT[53], 3,
                              posXTOP[54], posYTOP[54], WidthWallHoriT[54], 3,
                              posXTOP[55], posYTOP[55], WidthWallHoriT[55], 3,
                              posXTOP[56], posYTOP[56], WidthWallHoriT[56], 3,
                              posXTOP[57], posYTOP[57], WidthWallHoriT[57], 3,
                              posXTOP[58], posYTOP[58], WidthWallHoriT[58], 3};

    Rectangle WallsLEFT[58] = { posXLEFT[0], posYLEFT[0], 3, HeightWallVertL[0],
                               posXLEFT[1], posYLEFT[1], 3, HeightWallVertL[1],
                               posXLEFT[2], posYLEFT[2], 3, HeightWallVertL[2],
                               posXLEFT[3], posYLEFT[3], 3, HeightWallVertL[3],
                               posXLEFT[4], posYLEFT[4], 3, HeightWallVertL[4],
                               posXLEFT[5], posYLEFT[5], 3, HeightWallVertL[5],
                               posXLEFT[6], posYLEFT[6], 3, HeightWallVertL[6],
                               posXLEFT[7], posYLEFT[7], 3, HeightWallVertL[7],
                               posXLEFT[8], posYLEFT[8], 3, HeightWallVertL[8],
                               posXLEFT[9], posYLEFT[9], 3, HeightWallVertL[9],
                               posXLEFT[10], posYLEFT[10], 3, HeightWallVertL[10],
                               posXLEFT[11], posYLEFT[11], 3, HeightWallVertL[11],
                               posXLEFT[12], posYLEFT[12], 3, HeightWallVertL[12],
                               posXLEFT[13], posYLEFT[13], 3, HeightWallVertL[13],
                               posXLEFT[14], posYLEFT[14], 3, HeightWallVertL[14],
                               posXLEFT[15], posYLEFT[15], 3, HeightWallVertL[15],
                               posXLEFT[16], posYLEFT[16], 3, HeightWallVertL[16],
                               posXLEFT[17], posYLEFT[17], 3, HeightWallVertL[17],
                               posXLEFT[18], posYLEFT[18], 3, HeightWallVertL[18],
                               posXLEFT[19], posYLEFT[19], 3, HeightWallVertL[19],
                               posXLEFT[20], posYLEFT[20], 3, HeightWallVertL[20],
                               posXLEFT[21], posYLEFT[21], 3, HeightWallVertL[21],
                               posXLEFT[22], posYLEFT[22], 3, HeightWallVertL[22],
                               posXLEFT[23], posYLEFT[23], 3, HeightWallVertL[23],
                               posXLEFT[24], posYLEFT[24], 3, HeightWallVertL[24],
                               posXLEFT[25], posYLEFT[25], 3, HeightWallVertL[25],
                               posXLEFT[26], posYLEFT[26], 3, HeightWallVertL[26],
                               posXLEFT[27], posYLEFT[27], 3, HeightWallVertL[27],
                               posXLEFT[28], posYLEFT[28], 3, HeightWallVertL[28],
                               posXLEFT[29], posYLEFT[29], 3, HeightWallVertL[29],
                               posXLEFT[30], posYLEFT[30], 3, HeightWallVertL[30],
                               posXLEFT[31], posYLEFT[31], 3, HeightWallVertL[31],
                               posXLEFT[32], posYLEFT[32], 3, HeightWallVertL[32],
                               posXLEFT[33], posYLEFT[33], 3, HeightWallVertL[33],
                               posXLEFT[34], posYLEFT[34], 3, HeightWallVertL[34],
                               posXLEFT[35], posYLEFT[35], 3, HeightWallVertL[35],
                               posXLEFT[36], posYLEFT[36], 3, HeightWallVertL[36],
                               posXLEFT[37], posYLEFT[37], 3, HeightWallVertL[37],
                               posXLEFT[38], posYLEFT[38], 3, HeightWallVertL[38],
                               posXLEFT[39], posYLEFT[39], 3, HeightWallVertL[39],
                               posXLEFT[40], posYLEFT[40], 3, HeightWallVertL[40],
                               posXLEFT[41], posYLEFT[41], 3, HeightWallVertL[41],
                               posXLEFT[42], posYLEFT[42], 3, HeightWallVertL[42],
                               posXLEFT[43], posYLEFT[43], 3, HeightWallVertL[43],
                               posXLEFT[44], posYLEFT[44], 3, HeightWallVertL[44],
                               posXLEFT[45], posYLEFT[45], 3, HeightWallVertL[45],
                               posXLEFT[46], posYLEFT[46], 3, HeightWallVertL[46],
                               posXLEFT[47], posYLEFT[47], 3, HeightWallVertL[47],
                               posXLEFT[48], posYLEFT[48], 3, HeightWallVertL[48],
                               posXLEFT[49], posYLEFT[49], 3, HeightWallVertL[49],
                               posXLEFT[50], posYLEFT[50], 3, HeightWallVertL[50],
                               posXLEFT[51], posYLEFT[51], 3, HeightWallVertL[51],
                               posXLEFT[52], posYLEFT[52], 3, HeightWallVertL[52],
                               posXLEFT[53], posYLEFT[53], 3, HeightWallVertL[53],
                               posXLEFT[54], posYLEFT[54], 3, HeightWallVertL[54],
                               posXLEFT[55], posYLEFT[55], 3, HeightWallVertL[55],
                               posXLEFT[56], posYLEFT[56], 3, HeightWallVertL[56],
                               posXLEFT[57], posYLEFT[57], 3, HeightWallVertL[57]};

    Rectangle WallsRIGHT[63] = { posXRIGHT[0], posYRIGHT[0], 3, HeightWallVertR[0],
                                posXRIGHT[1], posYRIGHT[1], 3, HeightWallVertR[1],
                                posXRIGHT[2], posYRIGHT[2], 3, HeightWallVertR[2],
                                posXRIGHT[3], posYRIGHT[3], 3, HeightWallVertR[3],
                                posXRIGHT[4], posYRIGHT[4], 3, HeightWallVertR[4],
                                posXRIGHT[5], posYRIGHT[5], 3, HeightWallVertR[5],
                                posXRIGHT[6], posYRIGHT[6], 3, HeightWallVertR[6],
                                posXRIGHT[7], posYRIGHT[7], 3, HeightWallVertR[7],
                                posXRIGHT[8], posYRIGHT[8], 3, HeightWallVertR[8],
                                posXRIGHT[9], posYRIGHT[9], 3, HeightWallVertR[9],
                                posXRIGHT[10], posYRIGHT[10], 3, HeightWallVertR[10],
                                posXRIGHT[11], posYRIGHT[11], 3, HeightWallVertR[11],
                                posXRIGHT[12], posYRIGHT[12], 3, HeightWallVertR[12],
                                posXRIGHT[13], posYRIGHT[13], 3, HeightWallVertR[13],
                                posXRIGHT[14], posYRIGHT[14], 3, HeightWallVertR[14],
                                posXRIGHT[15], posYRIGHT[15], 3, HeightWallVertR[15],
                                posXRIGHT[16], posYRIGHT[16], 3, HeightWallVertR[16],
                                posXRIGHT[17], posYRIGHT[17], 3, HeightWallVertR[17],
                                posXRIGHT[18], posYRIGHT[18], 3, HeightWallVertR[18],
                                posXRIGHT[19], posYRIGHT[19], 3, HeightWallVertR[19],
                                posXRIGHT[20], posYRIGHT[20], 3, HeightWallVertR[20],
                                posXRIGHT[21], posYRIGHT[21], 3, HeightWallVertR[21],
                                posXRIGHT[22], posYRIGHT[22], 3, HeightWallVertR[22],
                                posXRIGHT[23], posYRIGHT[23], 3, HeightWallVertR[23],
                                posXRIGHT[24], posYRIGHT[24], 3, HeightWallVertR[24],
                                posXRIGHT[25], posYRIGHT[25], 3, HeightWallVertR[25],
                                posXRIGHT[26], posYRIGHT[26], 3, HeightWallVertR[26],
                                posXRIGHT[27], posYRIGHT[27], 3, HeightWallVertR[27],
                                posXRIGHT[28], posYRIGHT[28], 3, HeightWallVertR[28],
                                posXRIGHT[29], posYRIGHT[29], 3, HeightWallVertR[29],
                                posXRIGHT[30], posYRIGHT[30], 3, HeightWallVertR[30],
                                posXRIGHT[31], posYRIGHT[31], 3, HeightWallVertR[31],
                                posXRIGHT[32], posYRIGHT[32], 3, HeightWallVertR[32],
                                posXRIGHT[33], posYRIGHT[33], 3, HeightWallVertR[33],
                                posXRIGHT[34], posYRIGHT[34], 3, HeightWallVertR[34],
                                posXRIGHT[35], posYRIGHT[35], 3, HeightWallVertR[35],
                                posXRIGHT[36], posYRIGHT[36], 3, HeightWallVertR[36],
                                posXRIGHT[37], posYRIGHT[37], 3, HeightWallVertR[37],
                                posXRIGHT[38], posYRIGHT[38], 3, HeightWallVertR[38],
                                posXRIGHT[39], posYRIGHT[39], 3, HeightWallVertR[39],
                                posXRIGHT[40], posYRIGHT[40], 3, HeightWallVertR[40],
                                posXRIGHT[41], posYRIGHT[41], 3, HeightWallVertR[41],
                                posXRIGHT[42], posYRIGHT[42], 3, HeightWallVertR[42],
                                posXRIGHT[43], posYRIGHT[43], 3, HeightWallVertR[43],
                                posXRIGHT[44], posYRIGHT[44], 3, HeightWallVertR[44],
                                posXRIGHT[45], posYRIGHT[45], 3, HeightWallVertR[45],
                                posXRIGHT[46], posYRIGHT[46], 3, HeightWallVertR[46],
                                posXRIGHT[47], posYRIGHT[47], 3, HeightWallVertR[47],
                                posXRIGHT[48], posYRIGHT[48], 3, HeightWallVertR[48],
                                posXRIGHT[49], posYRIGHT[49], 3, HeightWallVertR[49],
                                posXRIGHT[50], posYRIGHT[50], 3, HeightWallVertR[50],
                                posXRIGHT[51], posYRIGHT[51], 3, HeightWallVertR[51],
                                posXRIGHT[52], posYRIGHT[52], 3, HeightWallVertR[52],
                                posXRIGHT[53], posYRIGHT[53], 3, HeightWallVertR[53],
                                posXRIGHT[54], posYRIGHT[54], 3, HeightWallVertR[54],
                                posXRIGHT[55], posYRIGHT[55], 3, HeightWallVertR[55],
                                posXRIGHT[56], posYRIGHT[56], 3, HeightWallVertR[56],
                                posXRIGHT[57], posYRIGHT[57], 3, HeightWallVertR[57],
                                posXRIGHT[58], posYRIGHT[58], 3, HeightWallVertR[58],
                                posXRIGHT[59], posYRIGHT[59], 3, HeightWallVertR[59],
                                posXRIGHT[60], posYRIGHT[60], 3, HeightWallVertR[60],
                                posXRIGHT[61], posYRIGHT[61], 3, HeightWallVertR[61],
                                posXRIGHT[62], posYRIGHT[62], 3, HeightWallVertR[62]};
/*-----------------------------------------------------------------------------*/

/*------------------------------POWER HITBOX-------------------------*/
    Rectangle PowerCircle = {PosXPower, PosYPower, 30, 25};
/*-------------------------------------------------------------------*/

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
    for(i = 0; i < QWallsBottom; i++)
    {
        WallsBOTTOM[i].x = posXBOTTOM[i];
        WallsBOTTOM[i].y = posYBOTTOM[i];
        WallsBOTTOM[i].width = WidthWallHoriB[i];
        CollisionBOTTOM = CheckCollisionRecs(Player, WallsBOTTOM[i]);
        if(CollisionBOTTOM)
            break;
    }
    for(i = 0; i < QWallsTop; i++)
    {
        WallsTOP[i].x = posXTOP[i];
        WallsTOP[i].y = posYTOP[i];
        WallsTOP[i].width = WidthWallHoriT[i];
        CollisionTOP = CheckCollisionRecs(Player, WallsTOP[i]);
        if(CollisionTOP)
            break;
    }
    for(i = 0; i < QWallsLeft; i++)
    {
        WallsLEFT[i].x = posXLEFT[i];
        WallsLEFT[i].y = posYLEFT[i];
        WallsLEFT[i].height = HeightWallVertL[i];
        CollisionRIGHT = CheckCollisionRecs(Player, WallsLEFT[i]);
        if(CollisionRIGHT)
            break;
    }
    for(i = 0; i < QWallsRight; i++)
    {
        WallsRIGHT[i].x = posXRIGHT[i];
        WallsRIGHT[i].y = posYRIGHT[i];
        WallsRIGHT[i].height = HeightWallVertR[i];
        CollisionLEFT = CheckCollisionRecs(Player, WallsRIGHT[i]);
        if(CollisionLEFT)
            break;
    }
    CollisionPower = CheckCollisionRecs(Player, PowerCircle);
/*-----------------------------------------------------------------------------------*/

    


    if((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && !CollisionLEFT)
    {
        for(i = 0; i < MostWallsQuantity; i++)
        {
            if(i < QWallsTop)
                posXTOP[i] -= PlayerSpeed*GetFrameTime();
            if(i < QWallsBottom)
                posXBOTTOM[i] -= PlayerSpeed*GetFrameTime();
            if(i < QWallsLeft)
                posXLEFT[i] -= PlayerSpeed*GetFrameTime();
            if(i < QWallsRight)
                posXRIGHT[i] -= PlayerSpeed*GetFrameTime();
        }
        PosXPower -= PlayerSpeed*GetFrameTime();
        fundo.x -= PlayerSpeed*GetFrameTime();
        screenPosX += PlayerSpeed*GetFrameTime();
        BRightIdle = true;
        BLeftIdle = false;
        BUpIdle = false;
        BDownIdle = false;
    }


    if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && !CollisionRIGHT)
    {
        for(i = 0; i < MostWallsQuantity; i++)
        {
            if(i < QWallsTop)
                posXTOP[i] += PlayerSpeed*GetFrameTime();
            if(i < QWallsBottom)
                posXBOTTOM[i] += PlayerSpeed*GetFrameTime();
            if(i < QWallsLeft)
                posXLEFT[i] += PlayerSpeed*GetFrameTime();
            if(i < QWallsRight)
                posXRIGHT[i] += PlayerSpeed*GetFrameTime();
        }
        PosXPower += PlayerSpeed*GetFrameTime();
        fundo.x += PlayerSpeed*GetFrameTime();
        screenPosX -= PlayerSpeed*GetFrameTime();
        BLeftIdle = true;
        BRightIdle = false;
        BUpIdle = false;
        BDownIdle = false;
    }


    if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && !CollisionTOP)
    {
        for(i = 0; i < MostWallsQuantity; i++)
        {
            if(i < QWallsTop)
                posYTOP[i] += PlayerSpeed*GetFrameTime();
            if(i < QWallsBottom)
                posYBOTTOM[i] += PlayerSpeed*GetFrameTime();
            if(i < QWallsLeft)
                posYLEFT[i] += PlayerSpeed*GetFrameTime();
            if(i < QWallsRight)
                posYRIGHT[i] += PlayerSpeed*GetFrameTime();
        }
        PosYPower += PlayerSpeed*GetFrameTime();
        fundo.y += PlayerSpeed*GetFrameTime();
        screenPosY -= PlayerSpeed*GetFrameTime();
        BUpIdle = true;
        BLeftIdle = false;
        BRightIdle = false;
        BDownIdle = false;
    }


    if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && !CollisionBOTTOM)
    {
        for(i = 0; i < MostWallsQuantity; i++)
        {
            if(i < QWallsTop)
                posYTOP[i] -= PlayerSpeed*GetFrameTime();
            if(i < QWallsBottom)
                posYBOTTOM[i] -= PlayerSpeed*GetFrameTime();
            if(i < QWallsLeft)
                posYLEFT[i] -= PlayerSpeed*GetFrameTime();
            if(i < QWallsRight)
                posYRIGHT[i] -= PlayerSpeed*GetFrameTime();
        }
        PosYPower -= PlayerSpeed*GetFrameTime();
        fundo.y -= PlayerSpeed*GetFrameTime();
        screenPosY += PlayerSpeed*GetFrameTime();
        BDownIdle = true;
        BLeftIdle = false;
        BRightIdle = false;
        BUpIdle = false;
    }


    if (IsKeyDown(KEY_SPACE) && GetBigger && CollisionPower)
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
        fundo.y += 25;
        PosXPower += 25;
        PosYPower += 25;
        for(i = 0; i < MostWallsQuantity; i++)
        {
            if(i < QWallsTop)
            {
                posXTOP[i] += 25;
                posYTOP[i] += 25;
            }
            if(i < QWallsBottom)
            {
                posXBOTTOM[i] += 25;
                posYBOTTOM[i] += 25;
            }
            if(i < QWallsLeft)
            {
                posXLEFT[i] += 25;
                posYLEFT[i] += 25;
            }
            if(i < QWallsRight)
            {
                posXRIGHT[i] += 25;
                posYRIGHT[i] += 25;
            }
        }
        GetBigger = false;
    }

    BeginDrawing();
    DrawTextureV(Fundo[0], fundo, WHITE);
    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        PlayerSprite[0].x = PlayerAnimation(PlayerSprites[0],PlayerSprite[0], 6);
        DrawTextureRec(PlayerSprites[0], PlayerSprite[0], PlayerPosition, WHITE);
    }


    else if(!(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && BLeftIdle)
    {
        PlayerSprite[1].x = PlayerAnimation(PlayerSprites[1],PlayerSprite[1], 5);
        DrawTextureRec(PlayerSprites[1], PlayerSprite[1], PlayerPosition, WHITE);
    }


    else if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        PlayerSprite[2].x = PlayerAnimation(PlayerSprites[2],PlayerSprite[2], 6);
        DrawTextureRec(PlayerSprites[2], PlayerSprite[2], PlayerPosition, WHITE);
    }


    else if(!(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && BRightIdle)
    {
        PlayerSprite[3].x = PlayerAnimation(PlayerSprites[3],PlayerSprite[3], 5);
        DrawTextureRec(PlayerSprites[3], PlayerSprite[3], PlayerPosition, WHITE);
    }


    else if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        PlayerSprite[4].x = PlayerAnimation(PlayerSprites[4],PlayerSprite[4], 6);
        DrawTextureRec(PlayerSprites[4], PlayerSprite[4], PlayerPosition, WHITE);
    }


    else if(!(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && BUpIdle)
    {
        PlayerSprite[5].x = PlayerAnimation(PlayerSprites[5],PlayerSprite[5], 5);
        DrawTextureRec(PlayerSprites[5], PlayerSprite[5], PlayerPosition, WHITE);
    }


    else if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        PlayerSprite[6].x = PlayerAnimation(PlayerSprites[6],PlayerSprite[6], 6);
        DrawTextureRec(PlayerSprites[6], PlayerSprite[6], PlayerPosition, WHITE);
    }


    else if(!(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && BDownIdle)
    {
        PlayerSprite[7].x = PlayerAnimation(PlayerSprites[7],PlayerSprite[7], 5);
        DrawTextureRec(PlayerSprites[7], PlayerSprite[7], PlayerPosition, WHITE);
    }


    DrawTextureV(Fundo[1], fundo, WHITE);
    /*for(i = 0; i < MostWallsQuantity; i++)
    {
        if(i < QWallsTop)
            DrawRectangleRec(WallsTOP[i],YELLOW);
        if(i < QWallsBottom)
            DrawRectangleRec(WallsBOTTOM[i],RED);
        if(i < QWallsLeft)
            DrawRectangleRec(WallsLEFT[i],DARKPURPLE);
        if(i < QWallsRight)
            DrawRectangleRec(WallsRIGHT[i],DARKBLUE);
    }*/
    if(GetBigger && CollisionPower)
    {
        if(TextBlinkingAmination < 70)
        {
        DrawRectangle(0,172,200,28,BLACK);
        DrawText("PRESS SPACE",13,175,25, WHITE);
        }
        if(TextBlinkingAmination >= 100)
            TextBlinkingAmination = 0;
        TextBlinkingAmination += 1;
    }

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