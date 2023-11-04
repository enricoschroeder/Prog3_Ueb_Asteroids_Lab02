#include <raylib-cpp.hpp>

#include <spaceship.h>

int main()
{
    int screenWidth = 1280;
    int screenHeight = 1024;

    raylib::Window window(screenWidth, screenHeight, "B:ME PROG3 Asteroids");
    raylib::Texture background("resources/background.png");

    SetTargetFPS(60);

    Spaceship ship(raylib::Vector2(screenWidth / 2, screenHeight / 2));

    while (!window.ShouldClose())
    {
        BeginDrawing();
        window.ClearBackground(RAYWHITE);
        background.Draw(raylib::Vector2(0, 0));

        ship.update();
        ship.draw();

        EndDrawing();
    }

    return 0;
}