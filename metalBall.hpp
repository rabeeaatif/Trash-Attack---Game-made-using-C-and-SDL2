#pragma once

#include "ball.hpp"

class metalBall : public ball
{
public:
  metalBall(LTexture *image, float x, float y);
  metalBall();
  virtual ~metalBall();
  void Move();
  virtual void Render(long int &frame, SDL_Renderer *gRenderer, bool debug);
};