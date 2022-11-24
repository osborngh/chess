#ifndef _LOG_H
#define _LOG_H

#include <stdio.h>

void log_error(const char* msg)
{
    printf("[ERROR]: %s\n", msg);
}

void log_info(const char* msg)
{
    printf("[INFO]: %s\n", msg);
}

void log_sdl_error()
{
    const char* msg = SDL_GetError();
    printf("[SDL_ERROR]: %s\n", msg);
}

#endif