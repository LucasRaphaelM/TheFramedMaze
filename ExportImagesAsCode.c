#include "raylib.h"

int main(void)
{
    Image Exportar = LoadImage("resources/Keybinds.png");
    ExportImageAsCode(Exportar,"resources.h/Keybinds.h");
    UnloadImage(Exportar);
    return 0;
}