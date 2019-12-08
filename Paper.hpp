#include <iostream>
#include "Trash.hpp"

class Paper : public Trash
{
private:
public:
    Paper();
    Paper(LTexture *bodyImg, float x, float y);
    virtual ~Paper();
    virtual void Render(long int &frame, SDL_Renderer *gRenderer, bool debug);
    virtual void Move();
    void Draw(SDL_Renderer *gRenderer);
};
