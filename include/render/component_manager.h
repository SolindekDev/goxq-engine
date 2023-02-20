#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <render/window.h>

#include <core/color.h>
#include <core/types.h>

#include <SDL2/SDL.h>

struct component_ui_t;

typedef void (*DRAW_COMPONENT_FUNCTION)(struct component_ui_t*, window_t*);
typedef void (*INIT_COMPONENT_FUNCTION)(struct component_ui_t*, window_t*);
typedef void (*EVENT_COMPONENT_FUNCTION)(struct component_ui_t*, window_t*, SDL_Event);

typedef enum component_type_t {
    component_BUTTON,
    component_INPUT,
    component_TEXT
} component_type_t;

typedef struct component_ui_t {
    str component_name;
    i32 component_id;

    component_type_t type;

    DRAW_COMPONENT_FUNCTION draw_function;
    INIT_COMPONENT_FUNCTION init_function;
    EVENT_COMPONENT_FUNCTION event_function;

    struct {
        str text;
        bool hover;
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
    } component_button;

    struct {
        str text;
        i32 font_size;
        color_t fg_color;
        vec2_t pos;
    } component_text;

    struct {

    } component_input;
} component_ui_t;

#include <render/components/button.h>
#include <render/components/input.h>
#include <render/components/text.h>

component_ui_t create_component_input  (/* args */);

component_ui_t create_component_button(str text, vec2_t pos, i32 font_size, color_t border_color,  color_t bg_color, color_t fg_color, i32 padding_top, 
                                       i32 padding_left, i32 padding_right, i32 padding_bottom, i32 margin_top, i32 margin_left, i32 margin_right, i32 margin_bottom,
                                       i32 border_radius);

component_ui_t create_component_text(str text, vec2_t pos, i32 font_size, color_t fg_color, i32 padding_top, i32 padding_left, i32 padding_right, 
                                     i32 padding_bottom, i32 margin_top, i32 margin_left, i32 margin_right, i32 margin_bottom);

void append_component(component_ui_t component);

void draw_components(window_t* window);

void call_events_components(window_t* window, SDL_Event event);

#endif /* COMPONENT_MANAGER_H */