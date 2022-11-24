#ifndef _UTILS_H
#define _UTILS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "log.h"
#include "game.h"

TTF_Font* load_font(const char* name, uint32_t size)
{
    TTF_Font* font;
    font = TTF_OpenFont(name, size);

    if (!font)
    {
        log_error("Font Loading Failed");
    }
    return font;
}

void render_font_solid(App *app, TTF_Font* font, const char* text, SDL_Color color, Pos *pos)
{
    SDL_Surface* text_surf;
    text_surf = TTF_RenderText_Solid(font, text, color);
    if (!text)
    {
        log_error("Text Rendering Failed");
    }

    SDL_Texture* text_texture;
    text_texture = SDL_CreateTextureFromSurface(app->renderer, text);

    SDL_Rect dest = { pos->x, pos->y, text_surf->w, text_surf->h };
    SDL_RenderCopy(app->renderer, text_texture, NULL, &dest);

    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(text);
}

#endif
