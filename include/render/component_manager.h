#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <render/window.h>

#include <core/color.h>
#include <core/types.h>

#include <SDL2/SDL.h>

struct component_ui_t;

typedef enum component_event_type_t {
    onclick_EVENT,
    onhover_EVENT,
    onchange_EVENT, /* For inputs */
    outhover_EVENT,
} component_event_type_t;

typedef void (*DRAW_COMPONENT_FUNCTION)(struct component_ui_t*, window_t*);
typedef void (*INIT_COMPONENT_FUNCTION)(struct component_ui_t*, window_t*);
typedef void (*EVENT_COMPONENT_FUNCTION)(struct component_ui_t*, window_t*, SDL_Event);

typedef enum component_type_t {
    component_BOX,
    component_TEXT,
    component_INPUT,
    component_BUTTON
} component_type_t;

typedef struct component_ui_t {
    str component_name;
    i32 component_id;

    component_event_type_t last_event;
    component_type_t type;

    DRAW_COMPONENT_FUNCTION draw_function;
    INIT_COMPONENT_FUNCTION init_function;
    EVENT_COMPONENT_FUNCTION event_function;

    struct {
        str text;
        vec2_t pos;

        i32 font_size;

        color_t border_color;
        color_t bg_color; 
        color_t fg_color;

        i32 padding_top;
        i32 padding_left;
        i32 padding_right;
        i32 padding_bottom;
        
        i32 margin_top;
        i32 margin_left;
        i32 margin_right;
        i32 margin_bottom;

        i32 border_radius;

        void (*btn_callback)(struct component_ui_t* component, window_t* window, SDL_Event event, component_event_type_t type);
    } component_button;

    struct {
        str text;
        i32 font_size;
        color_t fg_color;
        vec2_t pos;
    } component_text;

    struct {
        str value;

        vec2_t pos;
        vec2_t size;

        i32 font_size;

        color_t border_color;
        color_t bg_color; 
        color_t fg_color;

        i32 padding_top;
        i32 padding_left;
        i32 padding_right;
        i32 padding_bottom;
        
        i32 margin_top;
        i32 margin_left;
        i32 margin_right;
        i32 margin_bottom;

        i32 border_radius;

        i32 max_length;
        i32 value_length;

        bool only_numbers;
        bool focus;

        void (*input_callback)(struct component_ui_t* component, window_t* window, SDL_Event event, component_event_type_t type);
    } component_input;

    struct {
        vec2_t pos;
        vec2_t size;

        color_t bg_color; 

        i32 padding_top;
        i32 padding_left;
        i32 padding_right;
        i32 padding_bottom;
        
        i32 margin_top;
        i32 margin_left;
        i32 margin_right;
        i32 margin_bottom;

        i32 border_radius;
    } component_box;
} component_ui_t;

typedef void (*BTN_CALLBACK)(component_ui_t* component, window_t* window, SDL_Event event, component_event_type_t type);
typedef void (*INPUT_CALLBACK)(component_ui_t* component, window_t* window, SDL_Event event, component_event_type_t type);

component_ui_t create_component_input  (str value, vec2_t pos, i32 font_size, color_t border_color,  color_t bg_color, color_t fg_color, i32 padding_top, 
                                       i32 padding_left, i32 padding_right, i32 padding_bottom, i32 margin_top, i32 margin_left, i32 margin_right, i32 margin_bottom,
                                       i32 border_radius, bool only_numbers, i32 max_length, INPUT_CALLBACK input_callback, vec2_t size);

// TODO: add size to buttons ui component
component_ui_t  create_component_button(str text, vec2_t pos, i32 font_size, color_t border_color,  color_t bg_color, color_t fg_color, i32 padding_top, 
                                       i32 padding_left, i32 padding_right, i32 padding_bottom, i32 margin_top, i32 margin_left, i32 margin_right, i32 margin_bottom,
                                       i32 border_radius, BTN_CALLBACK btn_callback);

component_ui_t create_component_text(str text, vec2_t pos, i32 font_size, color_t fg_color, i32 padding_top, i32 padding_left, i32 padding_right, 
                                     i32 padding_bottom, i32 margin_top, i32 margin_left, i32 margin_right, i32 margin_bottom);

component_ui_t create_component_box(vec2_t pos, vec2_t size, color_t bg_color,  i32 padding_top, i32 padding_left, i32 padding_right, i32 padding_bottom, 
                                    i32 margin_top, i32 margin_left, i32 margin_right, i32 margin_bottom, i32 border_radius);

void append_component(component_ui_t component);

void draw_components(window_t* window);

void call_events_components(window_t* window, SDL_Event event);

component_ui_t* get_compontent_by_id(i32 id);

#endif /* COMPONENT_MANAGER_H */