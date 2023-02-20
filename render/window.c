#include <render/window.h>
#include <render/events.h>
#include <render/font.h>

#include <core/includes.h>
#include <core/vec2.h>
#include <core/color.h>

#include <SDL2/SDL.h>

#define DEFAULT_WINDOW_FLAGS   (SDL_WINDOW_RESIZABLE)
#define DEFAULT_RENDERER_FLAGS (SDL_RENDERER_ACCELERATED)

static bool is_sdl2_initialized = false;

void init_window()
{
    i32 status = SDL_Init(SDL_INIT_EVERYTHING);
    if (status != 0)
    {
        printf("Couldn't initialize SDL");
        return;
    }

    font_init();

    is_sdl2_initialized = true;
}

window_t* create_window(vec2_t default_window_size, vec2_t default_window_pos, str default_window_title,
                       color_t default_background_color, color_t default_foreground_color)
{
    window_t* window = malloc(sizeof(window_t));

    window->default_window_size      = default_window_size;  
    window->default_window_pos       = default_window_pos;  
    window->default_window_title     = default_window_title;  
    window->default_background_color = default_background_color;
    window->default_foreground_color = default_foreground_color;
    window->exit                     = false;

    window->sdl_window  = SDL_CreateWindow(window->default_window_title, (i32)window->default_window_pos.x, 
                                          (i32)window->default_window_pos.y, (i32)window->default_window_size.x, 
                                          (i32)window->default_window_size.y, DEFAULT_WINDOW_FLAGS);
    window->sdl_main_renderer = SDL_CreateRenderer(window->sdl_window, -1, DEFAULT_RENDERER_FLAGS);

    return window;
}

vec2_t get_window_size(window_t* window)
{
    vec2_t vec_window_size = create_vec2(0, 0);
    SDL_GetWindowSize(window->sdl_window, ((i32*)&vec_window_size.x), 
                                          ((i32*)&vec_window_size.y));
    return vec_window_size;
}

vec2_t get_window_pos(window_t* window)
{
    vec2_t vec_window_pos = create_vec2(0, 0);
    SDL_GetWindowPosition(window->sdl_window, ((i32*)&vec_window_pos.x), 
                                              ((i32*)&vec_window_pos.y));
    return vec_window_pos;
}

const str get_window_title(window_t* window)
{
    return (const str)SDL_GetWindowTitle(window->sdl_window);
}

void set_window_draw_function(window_t* window, WINDOW_DRAW_FUNC window_draw_func)
{
    window->window_draw_func = window_draw_func;
}

void set_window_init_function(window_t* window, WINDOW_INIT_FUNC window_init_func)
{
    window->window_init_func = window_init_func;
}

void set_window_event_function(window_t* window, WINDOW_EVENT_FUNC window_event_func)
{
    window->window_event_func = window_event_func;
}

void window_start_loop(window_t* window)
{
    window->window_init_func(window);

    while (!window->exit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            window_event_handler(window, event);
            window->window_event_func(window, event);
        }

        SDL_SetRenderDrawColor(window->sdl_main_renderer, window->default_background_color.r,
                               window->default_background_color.g, window->default_background_color.b,
                               window->default_background_color.a);
        SDL_RenderClear(window->sdl_main_renderer);
        window->window_draw_func(window);
        SDL_RenderPresent(window->sdl_main_renderer);
    }

    return;
}

void uninit_window()
{
    SDL_Quit();
}