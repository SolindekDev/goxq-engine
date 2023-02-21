#include <render/component_manager.h>

#include <render/components/button.h>
#include <render/components/input.h>
#include <render/components/text.h>

#define MAX_COMPONENTS (1024)

// TODO: make components an dynamic array
component_ui_t components[MAX_COMPONENTS];
i32 components_length = 0;

component_ui_t create_component_input  (str value, vec2_t pos, i32 font_size, color_t border_color,  color_t bg_color, color_t fg_color, i32 padding_top, 
                                       i32 padding_left, i32 padding_right, i32 padding_bottom, i32 margin_top, i32 margin_left, i32 margin_right, i32 margin_bottom,
                                       i32 border_radius, bool only_numbers, i32 max_length, INPUT_CALLBACK input_callback)
{
    return (component_ui_t){
        .component_name = "Input", .component_id = components_length + 1,
        .type = component_INPUT, .draw_function = input_draw_function,
        .init_function = input_init_function, .event_function = input_event_function,
        .component_input = {
            .value = value,
            .pos = pos,
            .font_size = font_size,
            .border_color = border_color,
            .bg_color = bg_color,
            .fg_color = fg_color,
            .padding_top = padding_top,
            .padding_left = padding_left,
            .padding_right = padding_right,
            .padding_bottom = padding_bottom,
            .margin_top = margin_top,
            .margin_left = margin_left,
            .margin_right = margin_right,
            .margin_bottom = margin_bottom,
            .border_radius = border_radius,
            .max_length = max_length,
            .value_length = 0,
            .only_numbers = only_numbers,
            .input_callback = input_callback
        }
    };
}                                       

component_ui_t  create_component_button(str text, vec2_t pos, i32 font_size, color_t border_color,  color_t bg_color, color_t fg_color, i32 padding_top, 
                                       i32 padding_left, i32 padding_right, i32 padding_bottom, i32 margin_top, i32 margin_left, i32 margin_right, i32 margin_bottom,
                                       i32 border_radius, BTN_CALLBACK btn_callback)
{
    return (component_ui_t){
        .component_name = "Button", .component_id = components_length + 1,
        .type = component_BUTTON, .draw_function = button_draw_function,
        .init_function = button_init_function, .event_function = button_event_function,
        .component_button = {
            .text = text, .pos = pos, .border_color = border_color,
            .bg_color = bg_color, .fg_color = fg_color, .padding_top = padding_top,
            .padding_left = padding_left, .padding_right = padding_right, 
            .padding_bottom = padding_bottom, .margin_top = margin_top,
            .margin_left = margin_left, .margin_right = margin_right, 
            .margin_bottom = margin_bottom, .font_size = font_size,
            .border_radius = border_radius, .btn_callback = btn_callback
        }
    };
}

component_ui_t create_component_text(str text, vec2_t pos, i32 font_size, color_t fg_color, i32 padding_top, i32 padding_left, i32 padding_right, 
                                     i32 padding_bottom, i32 margin_top, i32 margin_left, i32 margin_right, i32 margin_bottom)
{
    return (component_ui_t){
        .component_name = "Text", .component_id = components_length + 1,
        .type = component_TEXT, .draw_function = text_draw_function,
        .init_function = text_init_function, .event_function = text_event_function,
        .component_text = {
            .text = text, .font_size = font_size, .pos = pos,
            .fg_color = fg_color,
        }
    };
}

void append_component(component_ui_t component)
{
    components[components_length] = component;
    components_length++;
}

void draw_components(window_t* window)
{
    for (i32 i = 0; i < components_length; i++)
        components[i].draw_function(&components[i], window);
}

void call_events_components(window_t* window, SDL_Event event)
{
    for (i32 i = 0; i < components_length; i++)
        components[i].event_function(&components[i], window, event);
}

component_ui_t* get_compontent_by_id(i32 id)
{
    return &components[id];
}