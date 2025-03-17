#pragma once
#include <SDL.h>
#include "object.h"

class Rock : public Obj
{
public:
    Rock();
    void handleEvent(SDL_Event &e) override;
    void update() override;
    void render() override;
private:
    int hp;
};
