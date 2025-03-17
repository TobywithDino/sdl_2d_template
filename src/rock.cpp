#include "rock.h"
#include "game.h"

Rock::Rock() : Obj()
{
}

void Rock::handleEvent(SDL_Event &e)
{
}

void Rock::update()
{
    pos.x += vel.x;
    pos.y += vel.y;
}

void Rock::render()
{
    SDL_SetRenderDrawColor(renderer, 150, 0, 0, 255);
    SDL_Rect r = {this->pos.x, this->pos.y, 20, 20};
    SDL_RenderFillRect(renderer, &r);
}
