#pragma once

#include <SDL.h>
#include <iostream>
#include "Point.hpp"

class LTexture
{
private:
    SDL_Texture* texture;
    int width;
    int height;

public:
    LTexture();
    ~LTexture();
    
    bool LoadFromFile(std::string, SDL_Renderer*);
    void Render(Point, SDL_Rect* clip = NULL, double angle = 0.0,SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE, SDL_Renderer* gRenderer = NULL);


};

