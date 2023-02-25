#include <core/includes.h>
#include <core/gstring.h>

str append(const str str, i8 c)
{
    long len = strlen(str);
    char* res = malloc(len + 2);
    strcpy(res, str);
    res[len + 0] = c;
    res[len + 1] = '\0';
    return res;
}

str char_to_str(i8 c)
{
    const i8 s[2] = { c, '\0' };
    return strdup((str)s);
}