#include <core/vec2.h>

vec2_t create_vec2(i64 x, i64 y)
{
    return ((vec2_t){ x, y });
}

i64 get_vec_x(vec2_t vec)
{
    return vec.x;
}

i64 get_vec_y(vec2_t vec)
{
    return vec.y;
}