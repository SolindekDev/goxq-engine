#include <core/includes.h>
#include <core/todo.h>

#include <render/gradient.h>
#include <render/drawing.h>

#include <SDL2/SDL.h>

void draw_gradient(window_t* window, gradient_type_t gradient_type, color_t start_color, color_t end_color, vec2_t pos, vec2_t size)
{
    switch (gradient_type)
    {
        case gradient_HORIZONTAL:
            draw_horizontal_gradient(window, start_color, end_color, pos, size);
            break;
        case gradient_LINEAR:
            draw_linear_gradient(window, start_color, end_color, pos, size);
            break;
        case gradient_RADIAL:
            TODO("implement radial gradient");
            break;
        case gradient_ANGLED:
            TODO("implement angled gradient");
            break;
    }
}

void draw_horizontal_gradient(window_t* window, color_t start_color, color_t end_color, vec2_t pos, vec2_t size)
{
    f32 r_step = (f32)(end_color.r - start_color.r) / (f32)size.x;
    f32 g_step = (f32)(end_color.g - start_color.g) / (f32)size.x;
    f32 b_step = (f32)(end_color.b - start_color.b) / (f32)size.x;
    f32 a_step = (f32)(end_color.a - start_color.a) / (f32)size.x;

    for (i32 i = 0; i < size.x; i++)
    {
        draw_fill_rect(window, create_vec2(pos.x + i, pos.y), create_vec2(1, size.y), 
                       create_color(
                            (u8)((i32)start_color.r + (i32)(r_step * (f32)i)),
                            (u8)((i32)start_color.g + (i32)(g_step * (f32)i)),
                            (u8)((i32)start_color.b + (i32)(b_step * (f32)i)),
                            (u8)((i32)start_color.a + (i32)(a_step * (f32)i))
                       ));
    }
}

void draw_linear_gradient(window_t* window, color_t start_color, color_t end_color, vec2_t pos, vec2_t size)
{
    f32 r_step = (f32)(end_color.r - start_color.r) / (f32)size.y;
    f32 g_step = (f32)(end_color.g - start_color.g) / (f32)size.y;
    f32 b_step = (f32)(end_color.b - start_color.b) / (f32)size.y;
    f32 a_step = (f32)(end_color.a - start_color.a) / (f32)size.y;

    for (i32 i = 0; i < size.y; i++)
    {
        draw_fill_rect(window, create_vec2(pos.x, pos.y + i), create_vec2(size.x, 1), 
                       create_color(
                            (u8)((i32)start_color.r + (i32)(r_step * (f32)i)),
                            (u8)((i32)start_color.g + (i32)(g_step * (f32)i)),
                            (u8)((i32)start_color.b + (i32)(b_step * (f32)i)),
                            (u8)((i32)start_color.a + (i32)(a_step * (f32)i))
                       ));
    }
}

void draw_radial_gradient(window_t* window, color_t start_color, color_t end_color, vec2_t pos, vec2_t size)
{
    
}

void draw_multicolor_gradient(window_t* window, gradient_type_t gradient_type, color_t colors[], i32 num_colors, vec2_t pos, vec2_t size)
{
    switch (gradient_type)
    {
        case gradient_HORIZONTAL:
            draw_multicolor_horizontal_gradient(window, colors, num_colors, pos, size);
            break;
        case gradient_LINEAR:
            draw_multicolor_horizontal_gradient(window, colors, num_colors, pos, size);
            break;
        case gradient_RADIAL:
            TODO("implement multicolor radial gradient");
            break;
        case gradient_ANGLED:
            TODO("implement multicolor angled gradient");
            break;
    }
}

void draw_multicolor_horizontal_gradient(window_t* window, color_t colors[], i32 num_colors, vec2_t pos, vec2_t size)
{
    f32 color_step = (f32)1.0 / (f32)(num_colors - 1);
    f32 x_step = (f32)1.0 / (f32)size.x;

    for (i32 i = 0; i < size.x; i++) {
        f32 p = i * x_step;
        i32 c1 = p / color_step;
        i32 c2 = c1 + 1;
        f32 weight = (p - (c1 * color_step)) / color_step;

        draw_fill_rect(window, create_vec2(pos.x + i, pos.y), create_vec2(1, size.y), 
                create_color(
                        (i32)(colors[c1].r + (f32)(colors[c2].r - colors[c1].r) * weight),
                        (i32)(colors[c1].g + (f32)(colors[c2].g - colors[c1].g) * weight),
                        (i32)(colors[c1].b + (f32)(colors[c2].b - colors[c1].b) * weight),
                        (i32)(colors[c1].a + (f32)(colors[c2].a - colors[c1].a) * weight)
                ));
    }
}

void draw_multicolor_linear_gradient(window_t* window, color_t colors[], i32 num_colors, vec2_t pos, vec2_t size)
{
    f32 color_step = 1.0 / (f32)(num_colors - 1);
    f32 x_step = 1.0 / (f32)size.x;

    for (i32 i = 0; i < size.y; i++) {
        f32 p = i * x_step;
        i32 c1 = p / color_step;
        i32 c2 = c1 + 1;
        f32 weight = (p - (c1 * color_step)) / color_step;

        draw_fill_rect(window, create_vec2(pos.x, pos.y + i), create_vec2(size.x, 1), 
                create_color(
                        (i32)(colors[c1].r + (f32)(colors[c2].r - colors[c1].r) * weight),
                        (i32)(colors[c1].g + (f32)(colors[c2].g - colors[c1].g) * weight),
                        (i32)(colors[c1].b + (f32)(colors[c2].b - colors[c1].b) * weight),
                        (i32)(colors[c1].a + (f32)(colors[c2].a - colors[c1].a) * weight)
                ));
    }
}