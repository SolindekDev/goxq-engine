#ifndef URL_H
#define URL_H

#include <core/includes.h>
#include <core/types.h>

typedef struct url_t {
    str protocol, domain, path, query;
} url_t;

bool is_url(str url_value);

url_t parse_url(str url_value);

#endif /* URL_H */