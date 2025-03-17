#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>

extern int window_width;
extern int window_height;
extern const char* title;
extern int fps;
extern SDL_Window* window;
extern SDL_Renderer* renderer;

class Obj;

class Game
{
private:
    bool running = false;
    int lastTick;
    void handleEvent(SDL_Event &e);
    void update();
    void render();
    int max_objs_count;
    std::vector<Obj*> objs;
public:
    int init();
    int run();
    int quit();
};