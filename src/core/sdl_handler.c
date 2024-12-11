#include "sdl_handler.h"

static void handleKeyboard(Player* player, double delta_time);

extern void destroyContext(Context* to_destroy) {
    if (to_destroy == NULL) {
        puts("WARNING: Got a NULL context to destroy.");
        return;
    }
    if (to_destroy->renderer != NULL) {
        SDL_DestroyRenderer(to_destroy->renderer);
        to_destroy->renderer = NULL;
    }
    if (to_destroy->renderer != NULL) {
        SDL_DestroyWindow(to_destroy->win);
        to_destroy->win = NULL;
    }
}

extern Context createContext(int x, int y, int w, int h, char* title, Uint32 flags) {
    Context context = (Context){NULL, NULL};

    context.win = SDL_CreateWindow(title, x, y, w, h, flags);
    if (context.win == NULL) {
        printf("ERROR: Can't create window for a context with title: %s\n", title);
        return context;
    }
    context.renderer = SDL_CreateRenderer(context.win, -1, SDL_RENDERER_PRESENTVSYNC);  
    if (context.renderer == NULL) {
        printf("ERROR: Can't create renderer for a context with title: %s\n", title);
        destroyContext(&context);
    }
    return context;
}

int initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        puts("ERROR: Can't initialize SDL. WTF!");
        return 1;
    }
    return 0;
}

void quitSDL(Context* main_context) {
    destroyContext(main_context);
    SDL_Quit();
}

void render(const Context* to_render, Player* player) {
    if (to_render == NULL) {
        puts("WARNING: Got a NULL context to render.");
        return;
    }
    if (to_render->renderer == NULL) {
        puts("WARNING: The provided context has a NULL renderer.");
        return;
    }
    SDL_SetRenderDrawColor(to_render->renderer, 255, 255, 255, 255);
    SDL_RenderClear(to_render->renderer);
    SDL_SetRenderDrawColor(to_render->renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(to_render->renderer, &(player->rect));
    SDL_RenderPresent(to_render->renderer);
}

static void handleKeyboard(Player* player, double delta_time) {
    //* This can be a performance bottleneck.
    const Uint8* state = SDL_GetKeyboardState(NULL);
    float x_component = 0, y_component = 0;
    if (state[SDL_SCANCODE_A]) {
        x_component = -1;
    } if (state[SDL_SCANCODE_S]) {
        y_component = 1;
    } if (state[SDL_SCANCODE_D]) {
        x_component = 1;
    } if (state[SDL_SCANCODE_W]) {
        y_component = -1;
    }
    moveRect(&(player->rect), x_component, y_component, delta_time, player->vel);
}

int handleEvents(Player* player, double delta_time) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return 1;
        }
    }
    handleKeyboard(player, delta_time);
    return 0;
}