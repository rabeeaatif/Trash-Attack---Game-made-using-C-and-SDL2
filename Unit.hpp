#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <cstdio>
#include <iostream>
#include "LTexture.hpp"

using namespace std;
enum MOTION
{
    RIGHT,
    LEFT
};
class Unit
{
protected:
    bool alive;
    int x;
    int y;
    float speedx;
    float speedy;
    int width;
    int height;
    LTexture *spriteSheetTexture;

public:
    Unit();
    Unit(LTexture *image, float x, float y);
    virtual ~Unit();
    void SetAlive(bool);
    bool GetAlive();
    int GetWidth();
    int GetHeight();
    float GetX();
    float GetY();
    virtual void Move(int direction);
    virtual void Move() = 0;
    virtual void Render(long int &frame, SDL_Renderer *gRenderer, bool debug) = 0;
};
