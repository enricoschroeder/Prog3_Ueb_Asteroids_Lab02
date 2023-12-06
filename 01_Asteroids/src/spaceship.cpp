#include <spaceship.h>

Spaceship::Spaceship(raylib::Vector2 initialPos)
: pos_(initialPos)
, rot_(0.0f)
{
    tex_.Load(texturePath_);
}

void Spaceship::draw()
{
    // Easy version: Draw object with rotation around origin (top left)
    //_tex.Draw(pos_, rot_);

    // Slightly more advanced version: Draw object with rotation around center
    raylib::Vector2 origin = raylib::Vector2(tex_.GetWidth() / 2, tex_.GetWidth() / 2);
    raylib::Rectangle sourceRect = {0.0, 0.0, static_cast<float>(tex_.GetWidth()), static_cast<float>(tex_.GetHeight()) };
    raylib::Rectangle destRect = {pos_.GetX(), pos_.GetY(), static_cast<float>(tex_.GetWidth()), static_cast<float>(tex_.GetHeight()) };
    tex_.Draw(sourceRect, destRect, origin, rot_);
}

void Spaceship::update()
{
    if(IsKeyDown(KEY_W))
        move(raylib::Vector2{0.0, -movementSpeed_}.Rotate(DEG2RAD * rot_)); // Attention: Rotate parameter is radians, not degrees!
    if(IsKeyDown(KEY_A))
        rotate(-rotationSpeed_);
    if(IsKeyDown(KEY_D))
        rotate(rotationSpeed_);
}

void Spaceship::rotate(float deg)
{
    rot_ += deg;
}

void Spaceship::move(raylib::Vector2 moveVec)
{
    pos_ += moveVec;
}
