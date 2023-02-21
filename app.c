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

void main_draw_function(window_t* window) 
{
    draw_components(window);
}

void test_button_callback(component_ui_t* component, window_t* window, SDL_Event event, component_event_type_t type)
{
    if (type == onclick_EVENT)
        get_compontent_by_id(1)->component_text.text = "Button has been clicked";
    else if (type == onhover_EVENT)
        component->component_button.bg_color = DEFAULT_HOVER_BTN_BG_COLOR;
    else if (type == outhover_EVENT)
        component->component_button.bg_color = DEFAULT_BTN_BG_COLOR;
}

void test_input_callback(component_ui_t* component, window_t* window, SDL_Event event, component_event_type_t type)
{
    if (type == onclick_EVENT)
        get_compontent_by_id(1)->component_text.text = "Input has been clicked";
    else if (type == onhover_EVENT)
        component->component_input.bg_color = DEFAULT_HOVER_INPUT_BG_COLOR;
    else if (type == outhover_EVENT)
        component->component_input.bg_color = DEFAULT_INPUT_BG_COLOR;
    else if (type == onchange_EVENT)
        printf("Input value changed\n");
}

void main_init_function(window_t* window) 
{
    append_component(create_component_button(
        "Hello Button", create_vec2(10, 10), 15, DEFAULT_BTN_BORDER_COLOR,
        DEFAULT_BTN_BG_COLOR, (color_t){ 255, 255, 255, 255 }, 10, 25, 25, 10,
        0, 0, 0, 0, 24, test_button_callback));

    append_component(create_component_text(
        "What's your name", create_vec2(10, 60), 24, (color_t){ 255, 255, 255, 255 }, 0, 0, 0, 0,
        0, 0, 0, 0));

    append_component(create_component_input(
        "Bruno", create_vec2(10, 90), 15, DEFAULT_BTN_BORDER_COLOR,
        DEFAULT_BTN_BG_COLOR, (color_t){ 255, 255, 255, 255 }, 10, 20, 20, 10,
        10, 0, 0, 0, 24, true, -1, test_input_callback));
} 

void main_event_function(window_t* window, SDL_Event event) 
{
    call_events_components(window, event);
}