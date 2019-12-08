#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <cstdio>
#include <iostream>
#include "Unit.hpp"
#include "LTexture.hpp"

using namespace std;

class Player : public Unit
{
private:
    enum ANIMATION_FRAMES
    {
        MOVING_FRAMES = 9
    };
    SDL_Rect spriteClips[MOVING_FRAMES];

public:
    Player(LTexture *image, float x, float y);
    Player();
    virtual ~Player();
    virtual void Move(int direction);
    void Move();
    void Render(long int &frame, SDL_Renderer *gRenderer, bool debug);
};
