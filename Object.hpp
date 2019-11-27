#include <iostream>
#include "Point.hpp"
#include "Ltexture"

class Object
{
protected:
    Point position;

public:
    Object();
    ~Object();
    Object(Ltexture *, Point);
    virtual void move();
    void Render(long int &, SDL_Renderer *, bool debug);
};