#ifndef PHYSICS_H
#define PHYSICS_H

#include <time.h>
#include <SDL2/SDL_rect.h>

extern void getDeltaTime(time_t* start, double* delta_time, int* frame_c);
extern int AABBCollision(const SDL_Rect obj1, const SDL_Rect obj2);
extern SDL_Rect createSDLRect(int x, int y, int w, int h);
extern void setRectPos(SDL_Rect* rect, int x, int y);
extern void setRectSize(SDL_Rect* rect, int w, int h);
extern void moveRect(SDL_Rect* rect, float x_component, float y_component, double delta_time, int vel);

#endif