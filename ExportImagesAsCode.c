#include "raylib.h"

int main(void)
{
    Image Exportar = LoadImage("Maps/FundoMapa.png");
    ExportImageAsCode(Exportar,"Maps.h/FundoMapa.h");
    UnloadImage(Exportar);
    return 0;
}