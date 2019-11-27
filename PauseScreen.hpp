#include <iostream>
#include "Screen.hpp"

class PauseScreen: public Screen
{
    public:
    PauseScreen();
    PauseScreen(LTexture*);
    ~PauseScreen();
    void Render(LTexture*, SDL_Rect*);

};