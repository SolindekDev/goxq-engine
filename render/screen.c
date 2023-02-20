#include <render/screen.h>

#include <SDL2/SDL.h>

vec2_t get_screen_size()
{
    SDL_DisplayMode mode;
    SDL_GetDisplayMode(0, 0, &mode);
    return create_vec2(mode.w, mode.h);
}