#ifndef COMPONENT_INPUT_H
#define COMPONENT_INPUT_H

#include <core/color.h>

#include <render/component_manager.h>
#include <render/window.h>

#include <SDL2/SDL.h>

#define DEFAULT_INPUT_BORDER_COLOR   (color_t){ 72,  78,  84,  255 }
#define DEFAULT_HOVER_INPUT_BG_COLOR (color_t){ 45,  45,  45,  255 }
#define DEFAULT_INPUT_BG_COLOR       (color_t){ 38,  38,  38,  255 }

typedef void (*INPUT_CALLBACK)(component_ui_t* component, window_t* window, SDL_Event event, component_event_type_t type);

void input_draw_function(component_ui_t* component, window_t* window);
void input_init_function(component_ui_t* component, window_t* window);
void input_event_function(component_ui_t* component, window_t* window, SDL_Event event);

#endif /* COMPONENT_INPUT_H */