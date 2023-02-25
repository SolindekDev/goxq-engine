#ifndef HTML_PARSER_H
#define HTML_PARSER_H

#include <html/html_lexer.h>

#include <core/types.h>

typedef struct html_attr_t {
    str attr_name;
    str attr_value;

    struct html_attr_t* attr_next;
} html_attr_t;

typedef struct html_node_t {
    str tag_name;
    str tag_text;

    struct html_attr_t* attributes;
    struct html_node_t* children;
    struct html_node_t* sibling;
} html_node_t;

typedef struct html_parser_t {
    html_node_t*  root_node;
    html_node_t*  curr_node;

    html_lexer_t* lexer;

    i32 index;
} html_parser_t;

html_attr_t* html_create_attribute(str attr_name, str attr_value);

void html_add_attribute(html_node_t* node, html_attr_t* attr);

void html_add_child(html_node_t* parent, html_node_t* child);

void html_add_sibling(html_node_t* sibling1, html_node_t* sibling2);

html_node_t* html_create_node(str tag_name, str tag_text);

html_parser_t* html_parse_tokens(html_lexer_t* lexer);

void html_print_nodes(html_parser_t* parser);

void html_print_node(html_node_t* node);

#endif /* HTML_PARSER_H */