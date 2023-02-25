#ifndef COMPONENT_BOX_H
#define COMPONENT_BOX_H

#include <core/color.h>

#include <render/component_manager.h>
#include <render/window.h>

#include <SDL2/SDL.h>

void box_draw_function(component_ui_t* component, window_t* window);
void box_init_function(component_ui_t* component, window_t* window);
void box_event_function(component_ui_t* component, window_t* window, SDL_Event event);

#endif /* COMPONENT_BOX_H */