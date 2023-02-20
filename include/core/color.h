#ifndef COLOR_H
#define COLOR_H

#include <core/types.h>

#include <SDL2/SDL.h>

typedef struct color_t {
    u8 r, g, b, a;
} color_t;

color_t create_color(u8 r, u8 g, u8 b, u8 a);

SDL_Color to_sdl_color(color_t color);

#endif /* COLOR_H */