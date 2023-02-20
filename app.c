#include <app.h>

#include <core/includes.h>
#include <core/vec2.h>
#include <core/url.h>

#include <render/component_manager.h>
#include <render/gradient.h>
#include <render/drawing.h>
#include <render/window.h>

#include <render/components/button.h>

#include <SDL2/SDL.h>

void main_draw_function(window_t* window) 
{
    draw_components(window);
}

void main_init_function(window_t* window) 
{
    append_component(create_component_button(
        "Hello Button", create_vec2(10, 10), 15, DEFAULT_BTN_BORDER_COLOR,
        DEFAULT_BTN_BG_COLOR, (color_t){ 255, 255, 255, 255 }, 10, 25, 25, 10,
        0, 0, 0, 0, 24
    ));

    append_component(create_component_text(
        "Hello, Goxq", create_vec2(10, 100), 24, (color_t){ 255, 255, 255, 255 }, 0, 0, 0, 0,
        0, 0, 0, 0
    ));
} 

void main_event_function(window_t* window, SDL_Event event) 
{
    call_events_components(window, event);
}    