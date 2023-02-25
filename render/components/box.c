#include <render/components/box.h>
#include <render/drawing.h>

#include <core/box_collider.h>
#include <core/gstring.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void box_draw_function(component_ui_t* component, window_t* window)
{
    i32 box_x = component->component_box.margin_left + component->component_box.margin_right  + component->component_box.pos.x;
    i32 box_y = component->component_box.margin_top  + component->component_box.margin_bottom + component->component_box.pos.y;

    i32 box_w = component->component_box.padding_left + component->component_box.padding_right  + component->component_box.size.x;
    i32 box_h = component->component_box.padding_top  + component->component_box.padding_bottom + component->component_box.size.y;

    if (component->component_box.border_radius == 0)
        draw_fill_rect(window, create_vec2(box_x, box_y), create_vec2(box_w, box_h), component->component_box.bg_color);
    else
        draw_fill_rect_with_rounded_corners(window, create_vec2(box_x, box_y), create_vec2(box_w, box_h), 
                                            component->component_box.bg_color, component->component_box.border_radius);
}

void box_init_function(component_ui_t* component, window_t* window)
{

}

void box_event_function(component_ui_t* component, window_t* window, SDL_Event event)
{

}