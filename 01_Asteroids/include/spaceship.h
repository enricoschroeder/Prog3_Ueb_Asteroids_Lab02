#pragma once

#include <raylib-cpp.hpp>

class Spaceship
{
private:
    inline static const std::string _texturePath = "./resources/spaceship.png";
    const float _movementSpeed = 4.0f;
    const float _rotationSpeed = 4.5f;

    raylib::Vector2 _pos;
    raylib::Texture2D _tex;
    float _rot;

public:
    Spaceship(raylib::Vector2 initialPos);

    void draw();
    void update();
    void rotate(float deg);
    void move(raylib::Vector2 moveVec);
};
