#include <app.h>

#include <core/includes.h>
#include <core/vec2.h>
#include <core/url.h>

#include <render/component_manager.h>
#include <render/gradient.h>
#include <render/drawing.h>
#include <render/window.h>

#include <render/components/button.h>
#include <render/components/input.h>

#include <SDL2/SDL.h>

void url_callback(component_ui_t* component, window_t* window, SDL_Event event, component_event_type_t type)
{
    if (type == onhover_EVENT)
        component->component_input.bg_color = DEFAULT_HOVER_INPUT_BG_COLOR;
    else if (type == outhover_EVENT)
        component->component_input.bg_color = DEFAULT_INPUT_BG_COLOR;
    else if (type == onchange_EVENT)
    {
        // AHA
    }
}

void main_draw_function(window_t* window) 
{
    draw_components(window);
}

void main_init_function(window_t* window) 
{
    append_component(create_component_box(create_vec2(0, 0), create_vec2(get_window_size(window).x, 40), create_color(20, 20, 20, 255), 
                     10, 10, 10, 10, 0, 0, 0, 0, 0));
    append_component(create_component_input("https://goxq.dev/", create_vec2(0, 0), 17, DEFAULT_INPUT_BORDER_COLOR, DEFAULT_INPUT_BG_COLOR, 
                                            create_color(255, 255, 255, 255), 10, 10, 0, 0, 10, 10, 0, 0, 12, false, 200,
                                            url_callback, create_vec2(get_window_size(window).x - 30, 30)));
} 

void main_event_function(window_t* window, SDL_Event event) 
{
    if (event.type == SDL_WINDOWEVENT)
    {
        if (event.window.type == SDL_WINDOWEVENT_RESIZED)
        {
            get_compontent_by_id(0)->component_box.size.x   = get_window_size(window).x;
            get_compontent_by_id(1)->component_input.size.x = get_window_size(window).x - 30;
        }
        else if (event.window.type == SDL_WINDOWEVENT_MINIMIZED)
        {
            printf("minimaized\n");
        }
    }    
    call_events_components(window, event);
}