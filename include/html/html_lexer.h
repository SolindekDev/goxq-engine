#ifndef HTML_LEXER_H
#define HTML_LEXER_H

#include <core/includes.h>
#include <core/types.h>

typedef enum tag_type_t {
    tag_type_TAG_START,
    tag_type_TAG_START_END,
    tag_type_TAG_NAME,
    tag_type_TAG_END,

    tag_type_ATTR_NAME,
    tag_type_ATTR_VALUE,

    tag_type_TEXT,
    tag_type_NONE
} tag_type_t;

typedef struct html_token_t {
    tag_type_t type;
    str        value;
} html_token_t;

typedef struct html_lexer_t {
    html_token_t** tokens;

    i8  curr_char;
    str value;

    i32 tokens_len;
    i32 index;

    bool tag_opened;
    bool expecting_attrs;
} html_lexer_t;

html_lexer_t* start_html_lexer(str value);

void html_get_next_char(html_lexer_t* html_lexer);

void html_print_tokens(html_lexer_t* html_lexer);

void html_append_token(html_lexer_t* html_lexer, html_token_t* token);

#endif /* HTML_LEXER_H */