#include <render/components/input.h>
#include <render/drawing.h>

#include <core/box_collider.h>

#include <SDL2/SDL.h>

void input_draw_function(component_ui_t* component, window_t* window)
{
    i32 input_pos_x = (i32)component->component_input.pos.x + (i32)component->component_input.margin_left;
    i32 input_pos_y = (i32)component->component_input.pos.y + (i32)component->component_input.margin_top;

    vec2_t font_size = strcmp(component->component_input.value, "") == 0 != true 
                            ? get_font_size(window, get_window_size(window).x, component->component_input.font_size, component->component_input.value)
                            : create_vec2(component->component_input.font_size, component->component_input.font_size);

    i32 input_size_w = component->component_input.padding_left + component->component_input.padding_right  + (i32)font_size.x;
    i32 input_size_h = component->component_input.padding_top  + component->component_input.padding_bottom + (i32)font_size.y;
        
    i32 input_text_btn_x = input_pos_x + (input_size_w / 2 - font_size.x / 2);
    i32 input_text_btn_y = input_pos_y + (input_size_h / 2 - font_size.y / 2);

    if (component->component_input.border_radius <= 1)
    {
        draw_fill_rect(window, create_vec2(input_pos_x, input_pos_y), create_vec2(input_size_w, input_size_h),
                                            component->component_input.bg_color);
        draw_rect(window, create_vec2(input_pos_x, input_pos_y), create_vec2(input_size_w, input_size_h),
                                            component->component_input.border_color);
    }
    else
    {
        draw_fill_rect_with_rounded_corners(window, create_vec2(input_pos_x, input_pos_y), create_vec2(input_size_w, input_size_h),
                                            component->component_input.bg_color, 15);

        draw_rect_with_rounded_corners(window, create_vec2(input_pos_x, input_pos_y), create_vec2(input_size_w, input_size_h),
                                            component->component_input.border_color, 15);
    }

    draw_text_raw(window, create_vec2(input_text_btn_x, input_text_btn_y), component->component_input.fg_color, 
                  get_window_size(window).x, component->component_input.font_size,  component->component_input.value);
}

void input_init_function(component_ui_t* component, window_t* window)
{

}

void input_event_function(component_ui_t* component, window_t* window, SDL_Event event)
{
    i32 input_pos_x = (i32)component->component_input.pos.x + (i32)component->component_input.margin_left;
    i32 input_pos_y = (i32)component->component_input.pos.y + (i32)component->component_input.margin_top;

    vec2_t font_size = strcmp(component->component_input.value, "") == 0 != true 
                            ? get_font_size(window, get_window_size(window).x, component->component_input.font_size, component->component_input.value)
                            : create_vec2(component->component_input.font_size, component->component_input.font_size);

    i32 input_size_w = component->component_input.padding_left + component->component_input.padding_right  + (i32)font_size.x;
    i32 input_size_h = component->component_input.padding_top  + component->component_input.padding_bottom + (i32)font_size.y;

    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if (check_box_collision(input_pos_x, input_pos_y, input_size_w, input_size_h,
                                event.button.x, event.button.y, 2, 2 ))
        {
            component->component_input.input_callback(component, window, event, onclick_EVENT);
            component->last_event = onclick_EVENT;
        }
    } 
    else if (event.type == SDL_MOUSEMOTION)
    {
        printf("%d %d\n", event.motion.x, event.motion.y);
        if (check_box_collision(input_pos_x, input_pos_y, input_size_w, input_size_h,
                                event.motion.x, event.motion.y, 2, 2 ))
        {
            component->component_input.input_callback(component, window, event, onhover_EVENT);
            component->last_event = onhover_EVENT;
        }
        else
            if (component->last_event != outhover_EVENT)
            {
                component->component_input.input_callback(component, window, event, outhover_EVENT);
                component->last_event = outhover_EVENT;
            }
    }
}
