#include <render/drawing.h>
#include <render/window.h>

#include <core/includes.h>
#include <core/color.h>
#include <core/math.h>
#include <core/vec2.h>
#include <core/todo.h>

#include <SDL2/SDL.h>

/* This function does draw a circle but not filled */
void draw_circle(window_t* window, vec2_t pos, i32 radius, color_t color)
{
    i32 offsetx = 0;
    i32 offsety = radius;
    i32 d = radius - 1;

    // Set blend mode and draw color
    SDL_SetRenderDrawBlendMode(window->sdl_main_renderer, 
                               (color.a == 255) 
                                    ? SDL_BLENDMODE_NONE 
                                    : SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window->sdl_main_renderer, color.r, color.g, color.b, color.a);

    // Draw the whole circle
    while (offsety >= offsetx) 
    {
        SDL_RenderDrawPoint(window->sdl_main_renderer, (i32)pos.x + offsetx, (i32)pos.y + offsety);
        SDL_RenderDrawPoint(window->sdl_main_renderer, (i32)pos.x + offsety, (i32)pos.y + offsetx);
        SDL_RenderDrawPoint(window->sdl_main_renderer, (i32)pos.x - offsetx, (i32)pos.y + offsety);
        SDL_RenderDrawPoint(window->sdl_main_renderer, (i32)pos.x - offsety, (i32)pos.y + offsetx);
        SDL_RenderDrawPoint(window->sdl_main_renderer, (i32)pos.x + offsetx, (i32)pos.y - offsety);
        SDL_RenderDrawPoint(window->sdl_main_renderer, (i32)pos.x + offsety, (i32)pos.y - offsetx);
        SDL_RenderDrawPoint(window->sdl_main_renderer, (i32)pos.x - offsetx, (i32)pos.y - offsety);
        SDL_RenderDrawPoint(window->sdl_main_renderer, (i32)pos.x - offsety, (i32)pos.y - offsetx);

        if (d >= 2*offsetx) 
        {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) 
        {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else 
        {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
}

/* This function does draw a circle but a filled one with given color */
void draw_fill_circle(window_t* window, vec2_t pos, i32 radius, color_t color)
{
    i32 offsetx = 0;
    i32 offsety = radius;
    i32 d = radius - 1;

    // Set blend mode and draw color
    SDL_SetRenderDrawBlendMode(window->sdl_main_renderer, 
                               (color.a == 255) 
                                    ? SDL_BLENDMODE_NONE 
                                    : SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window->sdl_main_renderer, color.r, color.g, color.b, color.a);

    // Draw circle
    while (offsety >= offsetx) {

        SDL_RenderDrawLine(window->sdl_main_renderer, (i32)pos.x - offsety, (i32)pos.y + offsetx, (i32)pos.x + offsety, (i32)pos.y + offsetx);
        SDL_RenderDrawLine(window->sdl_main_renderer, (i32)pos.x - offsetx, (i32)pos.y + offsety, (i32)pos.x + offsetx, (i32)pos.y + offsety);
        SDL_RenderDrawLine(window->sdl_main_renderer, (i32)pos.x - offsetx, (i32)pos.y - offsety, (i32)pos.x + offsetx, (i32)pos.y - offsety);
        SDL_RenderDrawLine(window->sdl_main_renderer, (i32)pos.x - offsety, (i32)pos.y - offsetx, (i32)pos.x + offsety, (i32)pos.y - offsetx);

        if (d >= 2*offsetx) 
        {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) 
        {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else 
        {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
}

/* This function does draw a rectangle but not filled */
void draw_rect(window_t* window, vec2_t pos, vec2_t size, color_t color)
{
    // Return because we can't draw anything
    if (size.x == 0 || size.y == 0) return;

    // Just draw a horizontal line because we know that the y is 1
    if (size.y == 1)
    {
        draw_line(window, create_vec2(pos.x, pos.y),
                  create_vec2(pos.x + size.x, pos.y), color);
        return;
    }

    // Just draw a vertical line because we know that the x is 1
    if (size.x == 1)
    {
        draw_line(window, create_vec2(pos.x, pos.y), 
                  create_vec2(pos.x, pos.y + size.y), color);
        return;
    }

    // Turn on Blend Mode if the alpha does not equals 255
    SDL_SetRenderDrawBlendMode(window->sdl_main_renderer, 
                               (color.a == 255) 
                                    ? SDL_BLENDMODE_NONE 
                                    : SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window->sdl_main_renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = { .x = (i32)pos.x, .y = (i32)pos.y, 
                      .w = (i32)size.x, .h = (i32)size.y };
    SDL_RenderDrawRect(window->sdl_main_renderer, &rect);
}

/* This function does draw a filled rectangle with given color */
void draw_fill_rect(window_t* window, vec2_t pos, vec2_t size, color_t color)
{
    // Return because we can't draw anything
    if (size.x == 0 || size.y == 0) return;

    // Turn on Blend Mode if the alpha does not equals 255
    SDL_SetRenderDrawBlendMode(window->sdl_main_renderer, 
                               (color.a == 255) 
                                    ? SDL_BLENDMODE_NONE 
                                    : SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window->sdl_main_renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = { .x = (i32)pos.x, .y = (i32)pos.y, 
                      .w = (i32)size.x, .h = (i32)size.y };
    SDL_RenderFillRect(window->sdl_main_renderer, &rect);
}

/* This whole function "draw_arc" is took from awesome library source code named SDL_gfx thanks 
   a lot this repository is so helpful in writting this render (i'm not that inteligent to write
   something like that) this function is a little bit modified than the original arcRGBA function
   created by SDL_gfx team */
void draw_arc(window_t* window, color_t color, i32 x, i32 y, i32 radius, i32 start, i32 end)
{
    i16 cx = 0;
    i16 cy = (i16)radius;
    i16 df = 1 - (i16)radius;
    i16 d_e = 3;
    i16 d_se = -2 * (i16)radius + 5;
    i16 xpcx, xmcx, xpcy, xmcy;
    i16 ypcy, ymcy, ypcx, ymcx;
    Uint8 drawoct;
    i32 startoct, endoct, oct, stopval_start = 0, stopval_end = 0;
    f64 dstart, dend, temp = 0.;

    if ((i16)radius < 0)
        return;

    if ((i16)radius == 0)
        return draw_pixel(window, create_vec2(x, y), color);

    drawoct = 0; 

    start %= 360;
    end %= 360;
    while (start < 0) start += 360;
    while (end < 0) end += 360;
    start %= 360;
    end %= 360;

    startoct = start / 45;
    endoct = end / 45;
    oct = startoct - 1; 

    do 
    {
        oct = (oct + 1) % 8;

        if (oct == startoct) 
        {
            dstart = (double)start;
            switch (oct) 
            {
                case 0:
                case 3:
                    temp = sin(dstart * gm_PI / 180.);
                    break;
                case 1:
                case 6:
                    temp = cos(dstart * gm_PI / 180.);
                    break;
                case 2:
                case 5:
                    temp = -cos(dstart * gm_PI / 180.);
                    break;
                case 4:
                case 7:
                    temp = -sin(dstart * gm_PI / 180.);
                    break;
            }
            temp *= (i16)radius;
            stopval_start = (int)temp; 

            if (oct % 2) drawoct |= (1 << oct); 
            else             drawoct &= 255 - (1 << oct);
        }
        if (oct == endoct) 
        {
            dend = (double)end;
            switch (oct)
            {
                case 0:
                case 3:
                    temp = sin(dend * gm_PI / 180);
                    break;
                case 1:
                case 6:
                    temp = cos(dend * gm_PI / 180);
                    break;
                case 2:
                case 5:
                    temp = -cos(dend * gm_PI / 180);
                    break;
                case 4:
                case 7:
                    temp = -sin(dend * gm_PI / 180);
                    break;
            }
            temp *= (i16)radius;
            stopval_end = (int)temp;

            if (startoct == endoct) 
            {
                if (start > end) {
                        drawoct = 255;
                } else {
                        drawoct &= 255 - (1 << oct);
                }
            } 
            else if (oct % 2) drawoct &= 255 - (1 << oct);
            else                      drawoct |= (1 << oct);
        } else if (oct != startoct) 
            drawoct |= (1 << oct);
    } while (oct != endoct);

    do 
    {
        ypcy = (i16)y + cy;
        ymcy = (i16)y - cy;
        if (cx > 0) 
        {
            xpcx = (i16)x + cx;
            xmcx = (i16)x - cx;

            if (drawoct & 4)  draw_pixel(window, create_vec2(xmcx, ypcy), color);
            if (drawoct & 2)  draw_pixel(window, create_vec2(xpcx, ypcy), color);
            if (drawoct & 32) draw_pixel(window, create_vec2(xmcx, ymcy), color);
            if (drawoct & 64) draw_pixel(window, create_vec2(xpcx, ymcy), color);
        } else 
        {
            if (drawoct & 96) draw_pixel(window, create_vec2(x, ymcy), color);
            if (drawoct & 6)  draw_pixel(window, create_vec2(x, ypcy), color);
        }

        xpcy = (i16)x + cy;
        xmcy = (i16)x - cy;
        if (cx > 0 && cx != cy) 
        {
            ypcx = (i16)y + cx;
            ymcx = (i16)y - cx;
            if (drawoct & 8)   draw_pixel(window, create_vec2(xmcy, ypcx), color);
            if (drawoct & 1)   draw_pixel(window, create_vec2(xpcy, ypcx), color);
            if (drawoct & 16)  draw_pixel(window, create_vec2(xmcy, ymcx), color);
            if (drawoct & 128) draw_pixel(window, create_vec2(xpcy, ymcx), color);
        } else if (cx == 0) 
        {
            if (drawoct & 24)  draw_pixel(window, create_vec2(xmcy, y), color);
            if (drawoct & 129) draw_pixel(window, create_vec2(xpcy, y), color);
        }

        if (stopval_start == cx) 
        {
            if (drawoct & (1 << startoct)) drawoct &= 255 - (1 << startoct);                
            else                                               drawoct |= (1 << startoct);
        }
        if (stopval_end == cx) 
        {
            if (drawoct & (1 << endoct)) drawoct &= 255 - (1 << endoct);
            else                                             drawoct |= (1 << endoct);
        }

        if (df < 0) 
        {
            df += d_e;
            d_e += 2;
            d_se += 2;
        } 
        else 
        {
            df += d_se;
            d_e += 2;
            d_se += 4;
            cy--;
        }
        cx++;
    } while (cx <= cy);
}

void draw_pixel(window_t* window, vec2_t pos, color_t color)
{
    // Just draw a line that is one length
    draw_line(window, pos, pos, color);
}

void draw_rect_with_rounded_corners_custom(window_t* window, vec2_t pos, vec2_t size, color_t color,
                                    i32 border_radius_left_top, i32 border_radius_right_top,
                                    i32 border_radius_left_bottom, i32 border_radius_right_bottom)
{
    // TODO: create function draw_rect_with_rounded_corners_custom
    TODO("create function draw_rect_with_rounded_corners_custom");
}

void draw_fill_rect_with_rounded_corners_custom(window_t* window, vec2_t pos, vec2_t size, color_t color,
                                         i32 border_radius_left_top, i32 border_radius_right_top,
                                         i32 border_radius_left_bottom, i32 border_radius_right_bottom)
{
    // TODO: create function draw_fill_rect_with_rounded_corners_custom
    TODO("create function draw_fill_rect_with_rounded_corners_custom");
}

void draw_rect_with_rounded_corners(window_t* window, vec2_t pos, vec2_t size, color_t color, i32 radius)
{
    // The border radius is too small
    if (radius == 0)
        return;

    // Return because we can't draw anything
    if (size.x == 0 || size.y == 0) return;

    // No border so we draw a rect
    if (radius <= 1)
    {
        draw_rect(window, pos, size, color);
        return;
    }

    SDL_SetRenderDrawBlendMode(window->sdl_main_renderer, 
                               (color.a == 255) 
                                    ? SDL_BLENDMODE_NONE 
                                    : SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window->sdl_main_renderer, color.r, color.g, color.b, color.a);

    // Draw four lines edges
    SDL_RenderDrawLine(window->sdl_main_renderer, (i32)pos.x + radius, (i32)pos.y, (i32)pos.x + (i32)size.x - radius, (i32)pos.y);
    SDL_RenderDrawLine(window->sdl_main_renderer, (i32)pos.x + (i32)size.x, (i32)pos.y + radius, (i32)pos.x + (i32)size.x, (i32)pos.y + (i32)size.y - radius);
    SDL_RenderDrawLine(window->sdl_main_renderer, (i32)pos.x + (i32)size.x - radius, (i32)pos.y + (i32)size.y, (i32)pos.x + radius, (i32)pos.y + (i32)size.y);
    SDL_RenderDrawLine(window->sdl_main_renderer, (i32)pos.x, (i32)pos.y + (i32)size.y - radius, (i32)pos.x, (i32)pos.y + radius);

    // Draw four corners
    draw_arc(window, color, (i32)pos.x + radius,               (i32)pos.y + radius,                radius, 180, 270);
    draw_arc(window, color, (i32)pos.x + (i32)size.x - radius, (i32)pos.y + radius,                radius, 270, 360);
    draw_arc(window, color, (i32)pos.x + radius,               (i32)pos.y + (i32)size.y - radius,  radius, 90, 180);
    draw_arc(window, color, (i32)pos.x + (i32)size.x - radius, (i32)pos.y + (i32)size.y - radius,  radius, 0, 90);
}

void draw_fill_rect_with_rounded_corners(window_t* window, vec2_t pos, vec2_t size, color_t color, i32 radius)
{
    // The border radius is too small
    if (radius == 0)
        return;

    // Return because we can't draw anything
    if (size.x == 0 || size.y == 0) return;

    // No border so we draw a rect
    if (radius <= 1)
    {
        draw_rect(window, pos, size, color);
        return;
    }

    SDL_SetRenderDrawBlendMode(window->sdl_main_renderer, 
                               (color.a == 255) 
                                    ? SDL_BLENDMODE_NONE 
                                    : SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window->sdl_main_renderer, color.r, color.g, color.b, color.a);

    // Draw four lines edges
    SDL_RenderDrawLine(window->sdl_main_renderer, (i32)pos.x + radius, (i32)pos.y, (i32)pos.x + (i32)size.x - radius, (i32)pos.y);
    SDL_RenderDrawLine(window->sdl_main_renderer, (i32)pos.x + (i32)size.x, (i32)pos.y + radius, (i32)pos.x + (i32)size.x, (i32)pos.y + (i32)size.y - radius);
    SDL_RenderDrawLine(window->sdl_main_renderer, (i32)pos.x + (i32)size.x - radius, (i32)pos.y + (i32)size.y, (i32)pos.x + radius, (i32)pos.y + (i32)size.y);
    SDL_RenderDrawLine(window->sdl_main_renderer, (i32)pos.x, (i32)pos.y + (i32)size.y - radius, (i32)pos.x, (i32)pos.y + radius);

    // Draw four corners
    draw_arc(window, color, (i32)pos.x + radius,               (i32)pos.y + radius,                radius, 180, 270);
    draw_arc(window, color, (i32)pos.x + (i32)size.x - radius, (i32)pos.y + radius,                radius, 270, 360);
    draw_arc(window, color, (i32)pos.x + radius,               (i32)pos.y + (i32)size.y - radius,  radius, 90, 180);
    draw_arc(window, color, (i32)pos.x + (i32)size.x - radius, (i32)pos.y + (i32)size.y - radius,  radius, 0, 90);

    draw_fill_circle(window, create_vec2((i32)pos.x + radius, (i32)pos.y + radius),                             radius, color);
    draw_fill_circle(window, create_vec2((i32)pos.x + (i32)size.x - radius, (i32)pos.y + radius),               radius, color);
    draw_fill_circle(window, create_vec2((i32)pos.x + radius, (i32)pos.y + (i32)size.y - radius),               radius, color);
    draw_fill_circle(window, create_vec2((i32)pos.x + (i32)size.x - radius, (i32)pos.y + (i32)size.y - radius), radius, color);

    draw_fill_rect(window, create_vec2(pos.x + radius, pos.y), create_vec2(size.x - (radius * 2), size.y), color);
    draw_fill_rect(window, create_vec2(pos.x, pos.y + radius), create_vec2(size.x, size.y - (radius * 2)), color);
}

void draw_triangle(window_t* window, vec2_t point1, vec2_t point2, vec2_t point3, color_t color)
{
    // TODO: create function draw_triangle
    TODO("create function draw_triangle");
}

void draw_fill_triangle(window_t* window, vec2_t point1, vec2_t point2, vec2_t point3, color_t color)
{
    // TODO: create function draw_fill_triangle
    TODO("create function draw_fill_triangle");
}

void draw_line(window_t* window, vec2_t start, vec2_t end, color_t color)
{
    // Turn on Blend Mode if the alpha does not equals 255
    SDL_SetRenderDrawBlendMode(window->sdl_main_renderer, 
                               (color.a == 255) 
                                    ? SDL_BLENDMODE_NONE 
                                    : SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window->sdl_main_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(window->sdl_main_renderer, 
                       (i32)start.x, (i32)start.y, (i32)end.x, (i32)end.y);
}

void draw_thick_line(window_t* window, vec2_t start, vec2_t end, color_t color, i32 thickness)
{
    if (thickness == 1)
    {
        draw_line(window, start, end, color);
        return;
    }

    // TODO: create function draw_thick_line
    TODO("create function draw_thick_line");

    // draw_pixel(window, start, color);
    // draw_pixel(window, create_vec2(start.x, start.y + thickness), color);
    // draw_pixel(window, end, color);
    // draw_pixel(window, create_vec2(end.x, end.y + thickness), color);

    // for (i32 i = 0; i < (thickness % 2) == 0 ? thickness : thickness + 1 ; i++)
    //     draw_line(window, create_vec2(start.x, start.y + i), create_vec2(end.x, end.y + i), color);
}


void draw_text_raw(window_t* window, vec2_t pos, color_t color_fg, i32 newline, str text)
{

}