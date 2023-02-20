#include <render/font.h>

#include <core/includes.h>
#include <core/types.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

TTF_Font* fonts[100];

void font_init()
{
    if (TTF_Init() == 0)
    {
        printf("Couldn't initialize SDL_ttf");
        exit(1);
    }

    for (i32 i = 0; i < 100; i++)
    {
        fonts[i] = TTF_OpenFont(FONT_PATH, i + 4);
        if (fonts[i] == NULL)
        {
            printf("Couldn't load %s with size %d", FONT_PATH, i + 4);
            exit(1);
        }
    }
}

TTF_Font* get_font_by_size(i32 size)
{
    return fonts[size - 3];
}

void font_quit()
{
    for (i32 i = 0; i < 100; i++)
        TTF_CloseFont(fonts[i]);

    TTF_Quit();
}