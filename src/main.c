#include <stdio.h>
#include <game.h>

#define TITLE "Chess"
#define WIDTH 800
#define HEIGHT 600

int main(int argc, char* argv[])
{
    App app = { NULL, NULL, MAIN_MENU };

    create_window(&app, TITLE, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    game_loop(&app);

    close_window(&app);
}