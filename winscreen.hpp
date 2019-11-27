#include <iostream>
#pragma once
#include "Endscreen.hpp"

class WinScreen : public EndScreen
{
    public:
        WinScreen();
        WinScreen(LTexture*);
        ~WinScreen();
        void Render(LTexture*, SDL_Rect*);

};