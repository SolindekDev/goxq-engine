#ifndef APP_H
#define APP_H

#include <render/window.h>

#include <SDL2/SDL.h>

void main_draw_function(window_t* window);

void main_init_function(window_t* window);

void main_event_function(window_t* window, SDL_Event event);

#endif /* APP_H */