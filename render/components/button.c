#include <render/components/button.h>
#include <render/drawing.h>

#include <core/box_collider.h>

#include <SDL2/SDL.h>

void button_draw_function(component_ui_t* component, window_t* window)
{
    i32 button_pos_x = (i32)component->component_button.pos.x + (i32)component->component_button.margin_left;
    i32 button_pos_y = (i32)component->component_button.pos.y + (i32)component->component_button.margin_top;

    vec2_t font_size = get_font_size(window, get_window_size(window).x, component->component_button.font_size, component->component_button.text);

    i32 button_size_w = component->component_button.padding_left + component->component_button.padding_right  + (i32)font_size.x;
    i32 button_size_h = component->component_button.padding_top  + component->component_button.padding_bottom + (i32)font_size.y;

    i32 button_text_btn_x = button_pos_x + (button_size_w / 2 - font_size.x / 2);
    i32 button_text_btn_y = button_pos_y + (button_size_h / 2 - font_size.y / 2);

    if (component->component_button.border_radius <= 1)
    {
        draw_fill_rect(window, create_vec2(button_pos_x, button_pos_y), create_vec2(button_size_w, button_size_h),
                                            component->component_button.bg_color);
        draw_rect(window, create_vec2(button_pos_x, button_pos_y), create_vec2(button_size_w, button_size_h),
                                            component->component_button.border_color);
    }
    else
    {
        draw_fill_rect_with_rounded_corners(window, create_vec2(button_pos_x, button_pos_y), create_vec2(button_size_w, button_size_h),
                                            component->component_button.bg_color, 15);

        draw_rect_with_rounded_corners(window, create_vec2(button_pos_x, button_pos_y), create_vec2(button_size_w, button_size_h),
                                            component->component_button.border_color, 15);
    }

    draw_text_raw(window, create_vec2(button_text_btn_x, button_text_btn_y), component->component_button.fg_color, 
                  get_window_size(window).x, component->component_button.font_size,  component->component_button.text);
}

void button_init_function(component_ui_t* component, window_t* window)
{
    // We don't need to initialize anything
}

void button_event_function(component_ui_t* component, window_t* window, SDL_Event event)
{
    i32 button_pos_x = (i32)component->component_button.pos.x + (i32)component->component_button.margin_left;
    i32 button_pos_y = (i32)component->component_button.pos.y + (i32)component->component_button.margin_top;

    vec2_t font_size = get_font_size(window, get_window_size(window).x, component->component_button.font_size, 
                                     component->component_button.text);

    i32 button_size_w = component->component_button.padding_left + component->component_button.padding_right  + (i32)font_size.x;
    i32 button_size_h = component->component_button.padding_top  + component->component_button.padding_bottom + (i32)font_size.y;

    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if (check_box_collision(button_pos_x, button_pos_y, button_size_w, button_size_h,
                                event.button.x, event.button.y, 2, 2 ))
        {
            component->component_button.btn_callback(component, window, event, onclick_EVENT);
            component->last_event = onclick_EVENT;
        }
    } 
    else if (event.type == SDL_MOUSEMOTION)
    {
        if (check_box_collision(button_pos_x, button_pos_y, button_size_w, button_size_h,
                                event.motion.x, event.motion.y, 2, 2 ))
        {
            component->component_button.btn_callback(component, window, event, onhover_EVENT);
            component->last_event = onhover_EVENT;
        }
        else
            if (component->last_event != outhover_EVENT)
            {
                component->component_button.btn_callback(component, window, event, outhover_EVENT);
                component->last_event = outhover_EVENT;
            }
    }
}
