#include <iostream>
#pragma once
#include "Screen.hpp"

class StartScreen : public Screen
{
    public:
        StartScreen();
        StartScreen(LTexture*);
        ~StartScreen();
        void render(LTexture*, SDL_Rect*);

};