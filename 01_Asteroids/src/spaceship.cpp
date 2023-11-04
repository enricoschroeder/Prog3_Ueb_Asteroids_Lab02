#include <spaceship.h>

Spaceship::Spaceship(raylib::Vector2 initialPos)
: _pos(initialPos)
, _rot(0.0f)
{
    _tex.Load(_texturePath);
}

void Spaceship::draw()
{
    // Easy version: Draw object with rotation around origin (top left)
    //_tex.Draw(_pos, _rot);

    // Slightly more advanced version: Draw object with rotation around center
    raylib::Vector2 origin = raylib::Vector2(_tex.GetWidth() / 2, _tex.GetWidth() / 2);
    raylib::Rectangle sourceRect = { 0.f, 0.f, static_cast<float>(_tex.GetWidth()), static_cast<float>(_tex.GetHeight()) };
    raylib::Rectangle destRect = { _pos.GetX(), _pos.GetY(), static_cast<float>(_tex.GetWidth()), static_cast<float>(_tex.GetHeight()) };
    _tex.Draw(sourceRect, destRect, origin, _rot);
}

void Spaceship::update()
{
    if(IsKeyDown(KEY_W))
        move(raylib::Vector2{0.f, -_movementSpeed}.Rotate(DEG2RAD * _rot)); // Attention: Rotate parameter is radians, not degrees!
    if(IsKeyDown(KEY_A))
        rotate(-_rotationSpeed);
    if(IsKeyDown(KEY_D))
        rotate(_rotationSpeed);
}

void Spaceship::rotate(float deg)
{
    _rot += deg;
}

void Spaceship::move(raylib::Vector2 moveVec)
{
    _pos += moveVec;
}
