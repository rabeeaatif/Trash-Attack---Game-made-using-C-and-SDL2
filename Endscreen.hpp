#include <iostream>
#pragma once
#include "Screen.hpp"

class EndScreen : public Screen
{
    public:
        EndScreen();
        EndScreen(LTexture*);
        ~EndScreen();
        void Render(LTexture*, SDL_Rect*);

};
