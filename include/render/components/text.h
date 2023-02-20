#ifndef COMPONENT_TEXT_H
#define COMPONENT_TEXT_H

#include <core/color.h>

#include <render/component_manager.h>
#include <render/window.h>

#include <SDL2/SDL.h>

void text_draw_function(component_ui_t* component, window_t* window);
void text_init_function(component_ui_t* component, window_t* window);
void text_event_function(component_ui_t* component, window_t* window, SDL_Event event);

#endif /* COMPONENT_TEXT_H */