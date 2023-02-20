#ifndef COMPONENT_BUTTON_H
#define COMPONENT_BUTTON_H

#include <core/color.h>

#include <render/component_manager.h>
#include <render/window.h>

#include <SDL2/SDL.h>

#define DEFAULT_BTN_BORDER_COLOR (color_t){ 72,  78,  84,  255 }
#define DEFAULT_BTN_BG_COLOR     (color_t){ 38,  38,  38,  255 }

void button_draw_function(component_ui_t* component, window_t* window);
void button_init_function(component_ui_t* component, window_t* window);
void button_event_function(component_ui_t* component, window_t* window, SDL_Event event);

#endif /* COMPONENT_BUTTON_H */