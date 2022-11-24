#include <stdbool.h>
#include <stdlib.h>

#include "game.h"
#include "log.h"

#include "screens.h"

void create_window(App *app, const char* title, uint32_t width, uint32_t height, uint32_t flags)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        log_error("SDL Initialization Failed");
    }

    if (TTF_Init() != 0)
    {
        log_error("SDL_TTF Initialization Failed");
    }

    app->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    if (app->window == NULL)
    {
        log_error("SDL Window Creation Failed");
    }

    flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    app->renderer = SDL_CreateRenderer(app->window, -1, flags);
    if (app->renderer == NULL)
    {
        log_error("SDL Renderer Creation Failed");
    }
}

void close_window(App *app)
{
    SDL_DestroyRenderer(app->renderer);
    SDL_DestroyWindow(app->window);

    // app->renderer = NULL;
    // app->window = NULL;

    TTF_Quit();
    SDL_Quit();
}

int handle_events()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            return QUIT;
        }
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                {
                    return QUIT;
                }
            }
        }
    }
    return RUNNING;
}

void update(App *app)
{
    switch (app->curr_screen)
    {
        case MAIN_MENU:
            main_menu_screen(app);
        /*
        case PLAYING:
            play_screen(app);
        case PAUSE:
            pause_screen(app);
        case LOSE:
            lose_screen(app);
        */
    }
}

void render(App *app)
{
    SDL_RenderPresent(app->renderer);
}

void game_loop(App *app)
{
    while (true)
    {
        if (handle_events() == QUIT)
        {
            break;
        }
        update(app);
        render(app);
    }
}