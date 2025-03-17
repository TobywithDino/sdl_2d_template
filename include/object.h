#pragma once
#include <SDL.h>
#include "coord.h"

class Obj
{
protected:
    Coord2D pos;
    Coord2D vel;
public:
    Obj();
    virtual ~Obj();
    virtual void handleEvent(SDL_Event &e) = 0; // classes that inherit Obj need to implement virtual method
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void setPos(int x, int y);
    virtual void setVel(int x, int y);
    virtual Coord2D getPos();
    virtual Coord2D getVel();
};