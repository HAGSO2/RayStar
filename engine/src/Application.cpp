#include "ProgramFlow/Application.hpp"
#include <raylib.h>

void Application::run()
{
    // Main application loop code here
    InitWindow(screenWidth, screenHeight, ApplicationName.c_str());
    SetTargetFPS(FPs);

    Init();

    while (!WindowShouldClose())
    {
        Update();

        Draw();
    }

    CloseWindow();
}