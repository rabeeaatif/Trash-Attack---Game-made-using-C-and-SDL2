#pragma once
#include "Unit.hpp"
#include "LTexture.hpp"

class Trash: public Unit
{
protected:
    enum ANIMATION_FRAMES
    {
        MOVING_FRAMES = 1
    };
    
    SDL_Rect spriteClips[MOVING_FRAMES];

public:
    Trash();
    Trash(LTexture* bodyImg,  float x, float y);
    virtual ~Trash();
    void Draw(SDL_Renderer* gRenderer);
    virtual void Move();
    virtual void Render(long int &frame, SDL_Renderer *gRenderer, bool debug);

};
