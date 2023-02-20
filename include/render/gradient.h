#ifndef GRADIENT_H
#define GRADIENT_H

#include <core/color.h>
#include <core/vec2.h>

#include <render/window.h>

typedef enum gradient_type_t {
    gradient_HORIZONTAL,
    gradient_LINEAR,    
    gradient_RADIAL,     // TODO: create radial gradient implementation
    gradient_ANGLED,     // TODO: create diagonal gradient implementation
} gradient_type_t;

void draw_gradient(window_t* window, gradient_type_t gradient_type, color_t start_color, color_t end_color, vec2_t pos, vec2_t size);

void draw_multicolor_gradient(window_t* window, gradient_type_t gradient_type, color_t colors[], i32 num_colors, vec2_t pos, vec2_t size);

void draw_horizontal_gradient(window_t* window, color_t start_color, color_t end_color, vec2_t pos, vec2_t size);

void draw_radial_gradient(window_t* window, color_t start_color, color_t end_color, vec2_t pos, vec2_t size);

void draw_multicolor_horizontal_gradient(window_t* window, color_t colors[], i32 num_colors, vec2_t pos, vec2_t size);

void draw_linear_gradient(window_t* window, color_t start_color, color_t end_color, vec2_t pos, vec2_t size);

void draw_multicolor_linear_gradient(window_t* window, color_t colors[], i32 num_colors, vec2_t pos, vec2_t size);

#endif /* GRADIENT_H */