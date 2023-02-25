#ifndef GSTRING_H
#define GSTRING_H

#include <core/types.h>

extern char* strdup(char* cpy);

str append(const str str, i8 c);

str char_to_str(i8 c);

#endif /* GSTRING_H */