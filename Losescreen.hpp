#include <iostream>
#pragma once
#include "Endscreen.hpp"

class LoseScreen : public EndScreen
{
    public:
        LoseScreen();
        LoseScreen(LTexture*);
        ~LoseScreen();
        void Render(LTexture*, SDL_Rect*);

};