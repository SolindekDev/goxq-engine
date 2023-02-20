#ifndef FONT_H
#define FONT_H

#include <core/types.h>

#include <SDL2/SDL_ttf.h>

#define FONT_PATH "./assets/OpenSans.ttf"

void font_init();

TTF_Font* get_font_by_size(i32 size);

void font_quit();

#endif /* FONT_H */