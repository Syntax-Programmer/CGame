#include "physics.h"

void getDeltaTime(time_t* start, double* delta_time, int* frame_c) {
    time_t diff;

    if (*frame_c % 5 == 0 && (diff = time(NULL) - *start) >= 1) {
        *delta_time = 1.0 / (*frame_c / diff);
        *start = time(NULL);
        *frame_c = 0;
    }
}

int AABBCollision(const SDL_Rect obj1, const SDL_Rect obj2) {
    return (obj1.x < obj2.x + obj2.w &&
            obj1.x + obj1.w > obj2.x &&
            obj1.y < obj2.y + obj2.h &&
            obj1.y + obj1.h > obj2.y);
}

SDL_Rect createSDLRect(int x, int y, int w, int h) {
    return (SDL_Rect){x, y, w, h};
}

void setRectPos(SDL_Rect* rect, int x, int y) {
    rect->x = x;
    rect->y = y;
}

void setRectSize(SDL_Rect* rect, int w, int h) {
    rect->w = w;
    rect->h = h;
}

void moveRect(SDL_Rect* rect, float x_component, float y_component, double delta_time, int vel) {
    int delta_dist = vel * delta_time;

    rect->x += delta_dist * x_component;
    rect->y += delta_dist * y_component;
}