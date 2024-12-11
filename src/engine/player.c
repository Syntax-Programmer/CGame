#include "player.h"

Uint8 getStatBarMax(const StatBar* bar) {
    return bar->max;
}

Uint8 getStatBarCurr(const StatBar* bar) {
    return bar->curr;
}

StatBar createStatBar(Uint8 max) {
    return (StatBar){max, max};
}

void setStatBarMax(StatBar* bar, Uint8 max) {
    if (max == 0) {
        puts("WARNING: Tried to set stat bar max to 0.");
        return;
    }
    bar->max = max;
    if (bar->curr > bar->max) {
        bar->curr = bar->max;
    }
}

void setStatBarCurr(StatBar* bar, Uint8 change) {
    // Use int rather than Uint8 to avoid overflow/underflow issues.
    int new_val = bar->curr + change;

    if (new_val > bar->max) {
        new_val = bar->max;
    } else if (new_val < 0) {
        new_val = 0;
    }
    bar->curr = new_val;
}

Player createPlayer(int x, int y, int w, int h, Uint8 max_health, Uint8 max_hunger, int max_vel) {
    Player player;

    player.rect = createSDLRect(x, y, w, h);
    player.health = createStatBar(max_health);
    player.hunger = createStatBar(max_hunger);
    player.vel = max_vel;
    return player;
}