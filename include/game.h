#ifndef _GAME_H
#define _GAME_H

#include <SDL2/SDL.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int curr_screen;
} App;

typedef struct {
    uint32_t x;
    uint32_t y;
} Pos;

enum State {
    RUNNING,
    QUIT
};

enum Screen {
    MAIN_MENU,
    PLAYING,
    PAUSE,
    LOSE
};

void create_window(App *app, const char* title, uint32_t width, uint32_t height, uint32_t flags);
void close_window(App *app);
void game_loop(App *app);

int handle_events();
void update(App *app);
void render(App *app);
void game_loop(App *app);

#endif