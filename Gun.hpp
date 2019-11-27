#pragma once
#include <iostream>
#include "Unit.hpp"
#include "Point.hpp"
#include "LTexture.hpp"

class Gun: public Unit
{
    public:
    Gun(LTexture*, Point);
    ~Gun();
    void moveleft();
    void moveright();


};