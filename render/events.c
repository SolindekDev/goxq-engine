#include <render/events.h>

void window_event_handler(window_t* window, SDL_Event event)
{
    switch (event.type) {
        case SDL_QUIT:
            window->exit = true;
            break;
    }
}
