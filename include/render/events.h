#ifndef EVENTS_H
#define EVENTS_H

#include <SDL2/SDL.h>

#include <render/window.h>

void window_event_handler(window_t* window, SDL_Event event);

#endif /* EVENTS_H */