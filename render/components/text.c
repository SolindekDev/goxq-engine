#include <render/components/text.h>

#include <render/drawing.h>

void text_draw_function(component_ui_t* component, window_t* window)
{
    printf("what\n");
    draw_text_raw(window, component->component_text.pos, component->component_text.fg_color, get_window_size(window).x,
                  component->component_text.font_size, component->component_text.text);
    printf("what\n");
}

void text_init_function(component_ui_t* component, window_t* window)
{
    // We don't need to initialize anything
}

void text_event_function(component_ui_t* component, window_t* window, SDL_Event event)
{

}
