#ifndef TODO_H
#define TODO_H

#include <stdio.h>
#include <stdlib.h>

#define TODO(todo_content) {                                                                             \
    printf("%s in file %s: TODO: \x1B[1;31m%s\x1B[0;0m\n", __FILE__, __PRETTY_FUNCTION__, todo_content); \
    exit(1);                                                                                             \
}                                                                             

#endif /* TODO_H */