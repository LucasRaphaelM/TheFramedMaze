#include "raylib.h"

int main(void)
{
    Image Exportar = LoadImage("Maps/FundoMapaAcimaPlayer.png");
    ExportImageAsCode(Exportar,"Maps.h/FundoMapaAcimaPlayer.h");
    UnloadImage(Exportar);
    return 0;
}