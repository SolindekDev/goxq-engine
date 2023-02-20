#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

#include <core/includes.h>
#include <core/color.h>
#include <core/vec2.h>

struct window_t;

typedef void (*WINDOW_DRAW_FUNC)(struct window_t* window);
typedef void (*WINDOW_INIT_FUNC)(struct window_t* window);
typedef void (*WINDOW_EVENT_FUNC)(struct window_t* window, SDL_Event event);

typedef struct window_t {
    SDL_Window*   sdl_window;
    SDL_Renderer* sdl_main_renderer;

    vec2_t default_window_size;
    vec2_t default_window_pos;

    str default_window_title;

    bool exit;

    color_t default_background_color;
    color_t default_foreground_color;

    WINDOW_DRAW_FUNC window_draw_func;
    WINDOW_INIT_FUNC window_init_func;
    WINDOW_EVENT_FUNC window_event_func;
} window_t;

void init_window();
void uninit_window();

window_t* create_window(vec2_t default_window_size, vec2_t default_window_pos, str default_window_title,
                       color_t default_background_color, color_t default_foreground_color);

vec2_t get_window_size(window_t* window);
vec2_t get_window_pos(window_t* window);

const str get_window_title(window_t* window);

void set_window_draw_function(window_t* window, WINDOW_DRAW_FUNC window_draw_func);
void set_window_init_function(window_t* window, WINDOW_INIT_FUNC window_init_func);
void set_window_event_function(window_t* window, WINDOW_EVENT_FUNC window_event_func);

void window_start_loop(window_t* window);

#endif /* WINDOW_H */