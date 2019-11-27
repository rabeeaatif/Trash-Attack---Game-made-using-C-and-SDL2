#pragma once
#include <iostream>

struct Point
{
    float m_x;
    float m_y;
    Point() : m_x(0), m_y(0){}
    Point (float x, float y) : m_x(x), m_y(y) {}
    float GetX() {return m_x;}
    float GetY() {return m_y;}
};