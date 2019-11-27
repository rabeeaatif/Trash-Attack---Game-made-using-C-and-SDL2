#pragma once
#include <iostream>
#include "Unit.hpp"
#include "Object.hpp"

class  Collision
{
    private:

        bool collided;

    public:
        Collision();
        ~Collision();
        bool collided(Unit*, Object*);

};