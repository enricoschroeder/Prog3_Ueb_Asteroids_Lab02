#pragma once

#include <raylib-cpp.hpp>

class Spaceship
{
private:
    inline static const std::string texturePath_ = "./resources/spaceship.png";
    const float movementSpeed_ = 4.0;
    const float rotationSpeed_ = 4.5;

    raylib::Vector2 pos_;
    raylib::Texture2D tex_;
    float rot_;

public:
    Spaceship(raylib::Vector2 initialPos);

    void draw();
    void update();
    void rotate(float deg);
    void move(raylib::Vector2 moveVec);
};
