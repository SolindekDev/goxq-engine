#include <core/color.h>

#include <SDL2/SDL.h>

color_t create_color(u8 r, u8 g, u8 b, u8 a)
{
    return ((color_t){ r, g, b, a });
}

SDL_Color to_sdl_color(color_t color)
{
    return (SDL_Color){ color.r, color.g, color.b, color.a };
}