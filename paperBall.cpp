#include "paperBall.hpp"

paperBall::paperBall()
{
}

paperBall::~paperBall()
{
    cout << "paper ball Deallocated" << endl;
}

paperBall::paperBall(LTexture *image, float x, float y) : ball(image, x, y)
{
    spriteSheetTexture = image;

    //Frame 0
    spriteClips[0].x = 127;
    spriteClips[0].y = 0;
    spriteClips[0].w = 127;
    spriteClips[0].h = 128;

    //   //Frame 1
    //   spriteClips[ 1 ].x = 128;
    //   spriteClips[ 1 ].y = 96;
    //   spriteClips[ 1 ].w = 32;
    //   spriteClips[ 1 ].h = 32;

    //   //Frame 2
    //   spriteClips[ 2 ].x = 160;
    //   spriteClips[ 2 ].y = 96;
    //   spriteClips[ 2 ].w = 32;
    //   spriteClips[ 2 ].h = 32;

    this->width = spriteClips[0].w;
    this->height = spriteClips[0].h;
}

void paperBall::Move()
{
    y = y - 10;
    if (y < -100)
    {
        SetAlive(false);
    }
}

void paperBall::Render(long int &frame, SDL_Renderer *gRenderer, bool debug)
{
    spriteSheetTexture->Render(x - width / 2, y - height / 2, &spriteClips[frame % BALL_FRAMES], 0.0, NULL, SDL_FLIP_NONE, gRenderer);
    if (debug == true)
    {
        SDL_Rect rect = {x - width / 2, y - height / 2, width, height};
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderDrawRect(gRenderer, &rect);
    }
}
