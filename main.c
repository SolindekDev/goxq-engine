#include <main.h>
#include <app.h>

#include <core/includes.h>
#include <core/types.h>
#include <core/color.h>

#include <render/component_manager.h>
#include <render/window.h>
#include <render/events.h>
#include <render/drawing.h>
#include <render/screen.h>

#include <html/html_parser.h>
#include <html/html_lexer.h>

#define DEFAULT_WINDOW_TITLE "Toy Browser Engine lol"

i32 main(i32 argc, str* argv)
{
    // init_window();
    // vec2_t screen_size = get_screen_size();
    // window_t* window = create_window(create_vec2(900, 600), 
    //                                  create_vec2(screen_size.x / 2 - 900, screen_size.y / 2 - 600),
    //                                  DEFAULT_WINDOW_TITLE, create_color(255, 255, 255, 255),
    //                                  create_color(255, 255, 255, 255));

    // set_window_draw_function(window, main_draw_function);
    // set_window_init_function(window, main_init_function);
    // set_window_event_function(window, main_event_function);

    // window_start_loop(window);
    // uninit_window();

    html_lexer_t* html_lexer = start_html_lexer("<!DOCTYPE html>\
<html>\
<body>\
<h1>My First Heading</h1>\
<p>My first paragraph.</p>\
</body>\
</html>\
");
    html_parse_tokens(html_lexer);
}