#include "game.h"

static int initGame(Context* main_context, Player* player); // TODO: Add parameters here that get initialized here while return is running.
static void gameloop(int running, Context* main_context, Player* player);
static void exitGame(Context* main_context);

static int initGame(Context* main_context, Player* player) {
    int status = 0;

    status = initSDL(); //* Use like status = initFoo() || initBar() || initFooBar();
    //* Create all the objects without affecting the status.
    *main_context = createContext(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                  1200, 800, "MyGame", SDL_WINDOW_ALLOW_HIGHDPI);
    *player = createPlayer(200, 200, 50, 50, 100, 100, 200);
    if (main_context->win == NULL) { //* Check like if (foo.isFail() == 1 || bar.rect = NULL) status = 1;
        status = 1;
    }
    return status;
}

static void gameloop(int running, Context* main_context, Player* player) {
    double delta_time = 1.0 / 60;
    int frame_c = 0;
    time_t start = time(NULL);

    while (running) {
        getDeltaTime(&start, &delta_time, &frame_c);
        if (handleEvents(player, delta_time) == 1) {
            return;
        }
        render(main_context, player);
        frame_c++;
    }
}

static void exitGame(Context* main_context) {
    quitSDL(main_context);
}

void game() {
    Context main_context;
    Player player;
    int running = !initGame(&main_context, &player);

    gameloop(running, &main_context, &player);
    exitGame(&main_context);
}