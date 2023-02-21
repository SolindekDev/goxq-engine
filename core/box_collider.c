#include <core/box_collider.h>
#include <core/types.h>

bool check_box_collision(i16 x1, i16 y1, i16 w1, i16 h1, i16 x2, i16 y2, i16 w2, i16 h2) 
{
    return x1 + w1 > x2 && x1 < x2 + w2 && y1 + h1 > y2 && y1 < y2 + h2;
}