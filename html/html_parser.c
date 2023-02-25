#include <html/html_parser.h>
#include <html/html_lexer.h>

html_attr_t* html_create_attribute(str attr_name, str attr_value)
{
    html_attr_t* attr = (html_attr_t*)malloc(sizeof(html_attr_t));
    attr->attr_name  = attr_name;
    attr->attr_value = attr_value;
    attr->attr_next  = NULL;
    return attr;
}

void html_add_attribute(html_node_t* node, html_attr_t* attr)
{
    if (node->attributes == NULL)
    {
        node->attributes = attr;
        return;
    }

    html_attr_t* current_attr = node->attributes;
    while (current_attr->attr_next != NULL)
    {
        current_attr = current_attr->attr_next;
    }
    current_attr->attr_next = attr;
}

void html_add_child(html_node_t* parent, html_node_t* child)
{
    if (parent->children == NULL)
    {
        parent->children = child;
        return;
    }

    html_node_t* current_node = parent->children;
    while (current_node->sibling != NULL)
    {
        current_node = current_node->sibling;
    }
    current_node->sibling = child;
}

void html_add_sibling(html_node_t* sibling1, html_node_t* sibling2)
{
    sibling1->sibling = sibling2;
}

html_node_t* html_create_node(str tag_name, str tag_text)
{
    html_node_t* node = (html_node_t*)malloc(sizeof(html_node_t));
    node->tag_name   = tag_name;
    node->tag_text   = tag_text;
    node->attributes = NULL;
    node->children   = NULL;
    node->sibling    = NULL;
    return node;
}

html_parser_t* html_parse_tokens(html_lexer_t* lexer)
{
    html_parser_t* parser = malloc(sizeof(html_parser_t));
    parser->index     = 0;
    parser->lexer     = lexer;
    parser->root_node = NULL;
    parser->curr_node = NULL;

    for (i32 i = 0; i < parser->lexer->tokens_len; i++)
    {
        html_token_t* curr_token = parser->lexer->tokens[i];

        switch (curr_token->type)
        {
            case tag_type_TAG_START:
                html_node_t* node = html_create_node(curr_token->value, "");
                if (parser->curr_node == NULL)
                    parser->root_node = node;
                else
                    html_add_child(parser->curr_node, node);
                parser->curr_node = node;
                break;
            // case tag_type_TAG_END:

            default: 
                break;
        }
    }

    html_print_nodes(parser);
    return parser;
}

void html_print_node(html_node_t* node)
{
    if (node == NULL) return;

    printf("tag_name: \"%s\", tag_text: \"%s\"\n", node->tag_name, node->tag_text);

    html_node_t* current_node = node->children;
    while (current_node != NULL)
    {
        html_print_node(current_node);
        current_node = current_node->sibling;
    }
}

void html_print_nodes(html_parser_t* parser)
{
    html_print_node(parser->root_node);
}