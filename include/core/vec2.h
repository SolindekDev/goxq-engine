#ifndef VEC2_H
#define VEC2_H

#include <core/types.h>

typedef struct vec2_t {
    i64 x, y;
} vec2_t;

vec2_t create_vec2(i64 x, i64 y);

i64 get_vec_x(vec2_t vec);

i64 get_vec_y(vec2_t vec);

#endif /* VEC2_H */