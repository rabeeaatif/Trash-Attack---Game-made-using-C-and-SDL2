#pragma once
#include "Node.hpp"
#include "LTexture.hpp"
#include "Point.hpp"

class Unit
{
    protected:
    Point position;
    LTexture* spritetexture;
    bool alive;
    SDL_Rect mover;
    float width;
    float height;

    public:
    Unit(LTexture* , Point);
    Unit();
    ~Unit();
    //virtual ~Unit();
    void SetAlive(bool);
    bool GetAlive();
    int GetWidth();
    int GetHeight();
    float GetX();
    float GetY();
    void moveleft();
    void moveright();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    
};



