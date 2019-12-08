#include "Player.hpp"

Player::Player()
{
}

Player::Player(LTexture *image, float x, float y) : Unit(image, x, y)
{
    spriteSheetTexture = image;

    //Frame 0
    spriteClips[0].x = 0;
    spriteClips[0].y = 520;
    spriteClips[0].w = 62;
    spriteClips[0].h = 62;

    //Frame 1
    spriteClips[1].x = 64;
    spriteClips[1].y = 520;
    spriteClips[1].w = 62;
    spriteClips[1].h = 62;

    //Frame 2
    spriteClips[2].x = 128;
    spriteClips[2].y = 520;
    spriteClips[2].w = 62;
    spriteClips[2].h = 64;
    //Frame 3
    spriteClips[3].x = 192;
    spriteClips[3].y = 520;
    spriteClips[3].w = 62;
    spriteClips[3].h = 64;
    //Frame 4
    spriteClips[4].x = 256;
    spriteClips[4].y = 520;
    spriteClips[4].w = 62;
    spriteClips[4].h = 64;
    //Frame 5
    spriteClips[5].x = 320;
    spriteClips[5].y = 520;
    spriteClips[5].w = 62;
    spriteClips[5].h = 64;
    //Frame 6
    spriteClips[6].x = 384;
    spriteClips[6].y = 520;
    spriteClips[6].w = 62;
    spriteClips[6].h = 64;
    //Frame 7
    spriteClips[7].x = 448;
    spriteClips[7].y = 520;
    spriteClips[7].w = 62;
    spriteClips[7].h = 64;
    //Frame 8
    spriteClips[8].x = 512;
    spriteClips[8].y = 520;
    spriteClips[8].w = 62;
    spriteClips[8].h = 64;
    this->width = spriteClips[0].w;
    this->height = spriteClips[0].h;
    cout << "Player constructor called";
}

Player::~Player()
{
    spriteSheetTexture = NULL;
}

void Player::Move(int direction)
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

void Player::Move()
{
    // speedx = speedx * friction;
    // speedy = speedy * friction;

    // x = x + speedx;
    // y = y + speedy;
}

void Player::Render(long int &frame, SDL_Renderer *gRenderer, bool debug)
{
    spriteSheetTexture->Render(x - width / 2, y - height / 2, &spriteClips[frame % MOVING_FRAMES], 0.0, NULL, SDL_FLIP_NONE, gRenderer, 50);
    if (debug == true)
    {
        SDL_Rect rect = {x - width / 2, y - height / 2, width, height};
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderDrawRect(gRenderer, &rect);
    }
}
