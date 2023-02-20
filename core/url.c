#include <core/includes.h>
#include <core/todo.h>
#include <core/url.h>

const str url_regex = "((http|https)://)(www.)?" 
                      "[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]"
                      "{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)";

bool is_url(str url_value)
{
    if (url_value[0] == '\0') return false;

    regex_t regex;
    i32 regex_ret = regcomp(&regex, url_regex, REG_EXTENDED);

    if (regex_ret != 0) return false;

    regex_ret = regexec(&regex, url_value, 0, NULL, 0);
    regfree(&regex);

    return regex_ret == 0 
        ? true 
        : false;
}

char* strdup(char* cpy);

url_t parse_url(str url_value)
{
    str protocol  = NULL; 
    str domain    = NULL; 
    str path      = NULL; 
    str query     = NULL;

    str url_value_copy = strdup(url_value);
    protocol = strtok(url_value_copy, ":");

    if (protocol == NULL)
        return (url_t){ .domain = domain,     .path = path, 
                        .protocol = protocol, .query = query };

    domain = strtok(NULL, "/");
    if (domain == NULL)
        return (url_t){ .domain = domain,     .path = path, 
                        .protocol = protocol, .query = query };

    path = strtok(NULL, "?");
    if (path == NULL)
        return (url_t){ .domain = domain,     .path = path, 
                        .protocol = protocol, .query = query };

    query = strtok(NULL, "\0");
    if (query == NULL)
        return (url_t){ .domain = domain,     .path = path, 
                        .protocol = protocol, .query = query };

    return (url_t){ .domain = domain,     .path = path, 
                    .protocol = protocol, .query = query };
}