#ifndef SDL_HANDLER_H
#define SDL_HANDLER_H

#include "../engine/player.h"
#include <SDL2/SDL.h>

typedef struct Context {
    SDL_Window* win;
    SDL_Renderer* renderer;
} Context;

extern void destroyContext(Context* to_destroy);
extern Context createContext(int x, int y, int w, int h, char* title, Uint32 flags);
extern int initSDL();
extern void quitSDL(Context* main_context);
extern void render(const Context* to_render, Player* player);
extern int handleEvents(Player* player, double delta_time);

#endif