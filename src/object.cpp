#include "object.h"
#include <iostream>

Obj::Obj()
{
}

void Obj::setPos(int x, int y)
{
    this->pos.x = x;
    this->pos.y = y;
}

void Obj::setVel(int x, int y)
{
    this->vel.x = x;
    this->vel.y = y;    
}

Coord2D Obj::getPos()
{
    return pos;
}

Coord2D Obj::getVel()
{
    return vel;
}
