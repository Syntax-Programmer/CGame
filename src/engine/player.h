#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL_rect.h>
#include "physics.h"

typedef struct StatBar {
    // We don't need more than 255 most of the times.
    Uint8 max, curr;
} StatBar;
typedef struct Player {
    SDL_Rect rect;
    StatBar health, hunger;
    int vel;
} Player;

extern Uint8 getStatBarMax(const StatBar* bar);
extern Uint8 getStatBarCurr(const StatBar* bar);
extern StatBar createStatBar(Uint8 max);
extern void setStatBarMax(StatBar* bar, Uint8 max);
extern void setStatBarCurr(StatBar* bar, Uint8 change);
extern Player createPlayer(int x, int y, int w, int h, Uint8 max_health, Uint8 max_hunger, int max_vel);

#endif