#include "screens.h"

void main_menu_screen(App *app)
{
    SDL_RenderClear(app->renderer);
    // SDL_SetRenderDrawColor(app->renderer, 255, 255, 255, 255);

    TTF_Font* font = load_font("first.ttf", 24);
    TTF_CloseFont(font);
}
