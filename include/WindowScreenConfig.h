/*---------------WINDOW SIZE OF THE GAME---------------*/
    float ViewSizeWidth = 200;
    float ViewSizeHeight = 200;
/*-----------------------------------------------------*/


/*-------GETTING PLAYER MONITOR WIDTH AND HEIGHT-------*/
    float PlayerWidthScreen;
    float PlayerHeightScreen;
/*-----------------------------------------------------*/


/*CENTRALIZING THE GAME WINDOW IN THE MIDDLE OF THE SCREEN*/
    float screenPosX;
    float screenPosY;
/*--------------------------------------------------------*/

void SetupScreen(void)
{
    PlayerWidthScreen = GetMonitorWidth(0);
    PlayerHeightScreen = GetMonitorHeight(0);
    //screenPosX = PlayerWidthScreen/2-ViewSizeWidth/2;
    //screenPosY = PlayerHeightScreen/2-ViewSizeHeight/2;
    screenPosX = PlayerWidthScreen/2;
    screenPosY = PlayerHeightScreen/2;
}