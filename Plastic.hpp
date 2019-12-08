#pragma once
#include <iostream>
#include "Trash.hpp"

class Plastic : public Trash
{
private:
public:
    Plastic();
    Plastic(LTexture *bodyImg, float x, float y);
    virtual ~Plastic();
    virtual void Render(long int &frame, SDL_Renderer *gRenderer, bool debug);
    virtual void Move();
};