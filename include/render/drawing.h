#ifndef DRAWING_H
#define DRAWING_H

#include <render/window.h>

#include <core/types.h>
#include <core/vec2.h>

void draw_rect(window_t* window, vec2_t pos, vec2_t size, color_t color);
void draw_fill_rect(window_t* window, vec2_t pos, vec2_t size, color_t color);

void draw_rect_with_rounded_corners_custom(window_t* window, vec2_t pos, vec2_t size, color_t color,
                                    i32 border_radius_left_top, i32 border_radius_right_top,
                                    i32 border_radius_left_bottom, i32 border_radius_right_bottom);
void draw_fill_rect_with_rounded_corners_custom(window_t* window, vec2_t pos, vec2_t size, color_t color,
                                         i32 border_radius_left_top, i32 border_radius_right_top,
                                         i32 border_radius_left_bottom, i32 border_radius_right_bottom);

void draw_rect_with_rounded_corners(window_t* window, vec2_t pos, vec2_t size, color_t color, i32 radius);
void draw_fill_rect_with_rounded_corners(window_t* window, vec2_t pos, vec2_t size, color_t color, i32 radius);

void draw_circle(window_t* window, vec2_t pos, i32 radius, color_t color);
void draw_fill_circle(window_t* window, vec2_t pos, i32 radius, color_t color);

void draw_triangle(window_t* window, vec2_t point1, vec2_t point2, vec2_t point3, color_t color);
void draw_fill_triangle(window_t* window, vec2_t point1, vec2_t point2, vec2_t point3, color_t color);

void draw_line(window_t* window, vec2_t start, vec2_t end, color_t color);
void draw_thick_line(window_t* window, vec2_t start, vec2_t end, color_t color, i32 thickness);

vec2_t draw_text_raw_format(window_t* window, vec2_t pos, color_t color_fg, i32 newline, i32 font_size, str text, ...);
vec2_t draw_text_raw(window_t* window, vec2_t pos, color_t color_fg, i32 newline, i32 font_size, str text);

vec2_t get_font_size(window_t* window, i32 newline, i32 font_size, str text);

void draw_arc(window_t* window, color_t color, i32 x, i32 y, i32 radius, i32 start, i32 end);

void draw_pixel(window_t* window, vec2_t pos, color_t color);

#endif /* DRAWING_H */