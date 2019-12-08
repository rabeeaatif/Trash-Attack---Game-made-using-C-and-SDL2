
#include "Unit.hpp"

Unit::Unit()
{
}
Unit::~Unit()
{
}
Unit::Unit(LTexture *image, float x, float y)
{
    spriteSheetTexture = image;

    this->x = x;
    this->y = y;
    speedx = 0;
    speedy = 0;
    alive = true;
    cout << "Unit constructor called";
}

void Unit::SetAlive(bool alive)
{
    this->alive = alive;
}

bool Unit::GetAlive()
{
    return alive;
}

void Unit::Move()
{
    // speedx = speedx * friction;
    // speedy = speedy * friction;

    // x = x + speedx;
    // y = y + speedy;
}
void Unit::Move(int direction)
{

    if (direction == LEFT)
    {
        speedx = -5;
        x += speedx;
        if (x <= 50)
        {
            x = 50;
        }
    }

    if (direction == RIGHT)
    {
        speedx = 5;
        x += speedx;
        if (x > 1024 - 64)
        {
            x = 1024 - 64;
        }
    }
}

int Unit::GetWidth()
{
    return width;
}

int Unit::GetHeight()
{
    return height;
}

float Unit::GetX()
{
    return x;
}
float Unit::GetY()
{
    return y;
}
