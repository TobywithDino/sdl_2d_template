#include <iostream>
#include "game.h"
#include "object.h"
#include "rock.h"

int window_width;
int window_height;
const char* title;
int fps;
SDL_Renderer* renderer;
SDL_Window* window;

void Game::handleEvent(SDL_Event &e)
{
    for(Obj* &obj: objs)
    {
        obj->handleEvent(e);
    }
}

void Game::update()
{
    int deltaTick = (1000 * 1/(float)fps);
    if(SDL_GetTicks() - lastTick < deltaTick)
        return;
    lastTick = SDL_GetTicks();
    for(Obj* &obj: objs)
    {
        obj->update();
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
    SDL_RenderClear(renderer);
    for(Obj* &obj: objs)
    {
        obj->render();
    }
    SDL_RenderPresent(renderer);
}

int Game::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }
    window_width = 1280;
    window_height = 720;
    title = "Handyman";
    fps = 60;
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    running = true;
    max_objs_count = 1;
    objs = std::vector<Obj*>();
    objs.resize(max_objs_count, nullptr);
    for(Obj* &obj : objs)
    {
        Rock *a = new Rock();
        obj = new Rock();
    }
    objs[0]->setPos(50,50);
    objs[0]->setVel(1,1);
    return 0;
}

int Game::run()
{
    if(!running)
    {
        printf("Game has not been initialized yet.\n");
        return 1;
    }
    SDL_Event e;
    while(running)
    {
        SDL_PollEvent(&e);
        if(e.type == SDL_QUIT)
        {
            running = false;
            std::printf("Quitting the game\n");
            break;
        }
        handleEvent(e);
        update();
        render();
    }
    return 0;
}

int Game::quit()
{
    for(Obj*& obj : objs)
    {
        delete obj;
    }
    objs.clear();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("Successfully quit\n");
    return 0;
}
