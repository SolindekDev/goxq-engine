#include <html/html_lexer.h>

#include <core/gstring.h>

void html_append_token(html_lexer_t* html_lexer, html_token_t* token)
{
    // Reallocate the memory for tokens by one more, set the token
    // and increment token list length
    html_lexer->tokens = (html_token_t**)realloc(html_lexer->tokens, sizeof(html_token_t*) * (html_lexer->tokens_len + 1));
    html_lexer->tokens[html_lexer->tokens_len] = token;
    html_lexer->tokens_len++;
}

html_token_t* html_create_token(tag_type_t type, str value)
{
    // Allocate error for single token and set the type
    html_token_t* token = (html_token_t*)malloc(sizeof(html_token_t));
    token->type = type;

    // Allocate memory for token value safely so we don't have
    // any crazy segmentation fault errors
    token->value = (str)malloc(sizeof(i8) * (strlen(value) + 1));
    strcpy(token->value, value);
    
    return token;
}

html_lexer_t* start_html_lexer(str value)
{
    html_lexer_t* html_lexer = (html_lexer_t*)malloc(sizeof(html_lexer_t));
    html_lexer->index      = 0;
    html_lexer->tokens_len = 0;
    html_lexer->tokens     = (html_token_t**)malloc(sizeof(html_token_t*) * 1);
    html_lexer->value      = value;
    html_lexer->curr_char  = '\0';

    while (html_lexer->value[html_lexer->index] != '\0')
    {
        html_lexer->curr_char = html_lexer->value[html_lexer->index];

        if (html_lexer->curr_char == '<')
        {
            html_append_token(html_lexer, html_create_token(tag_type_TAG_START, "<"));
            html_lexer->tag_opened = true;
            html_lexer->index++;
            continue;
        }
        if (html_lexer->curr_char == '/' && html_lexer->tag_opened)
        {
            html_append_token(html_lexer, html_create_token(tag_type_TAG_START_END, "/"));
            html_lexer->index++;
            continue;
        }
        else if (html_lexer->curr_char == '>')
        {
            html_append_token(html_lexer, html_create_token(tag_type_TAG_END, ">"));
            html_lexer->tag_opened = false;
            html_lexer->index++;
            continue;
        }
        else if (html_lexer->tag_opened == true && html_lexer->expecting_attrs == true)
        {
            if (html_lexer->tokens[html_lexer->tokens_len - 1]->type == tag_type_TAG_NAME)
            {
                if (html_lexer->curr_char == '=')
                    html_append_token(html_lexer, html_create_token(
                        tag_type_ATTR_VALUE, ""));
                else
                    html_append_token(html_lexer, html_create_token(
                        tag_type_ATTR_NAME, char_to_str(html_lexer->curr_char)));
            }
            else if (html_lexer->tokens[html_lexer->tokens_len - 1]->type == tag_type_ATTR_NAME ||
                     html_lexer->tokens[html_lexer->tokens_len - 1]->type == tag_type_ATTR_VALUE)
            {
                str last_token_str = html_lexer->tokens[html_lexer->tokens_len - 1]->value;
                last_token_str = realloc(last_token_str, sizeof(i8) * (strlen(last_token_str) + 2));
                last_token_str[strlen(last_token_str) + 0] = html_lexer->curr_char;
                last_token_str[strlen(last_token_str) + 1] = '\0';
            }
        }
        else if (html_lexer->tag_opened == true)
        {
            if (html_lexer->curr_char == ' ')
            {
                html_lexer->expecting_attrs = true;
                html_lexer->index++;
                continue;
            }

            if (html_lexer->tokens[html_lexer->tokens_len - 1]->type == tag_type_TAG_START ||
                html_lexer->tokens[html_lexer->tokens_len - 1]->type == tag_type_TAG_START_END)
            {
                html_append_token(html_lexer, html_create_token(
                    tag_type_TAG_NAME, char_to_str(html_lexer->curr_char)));
            }
            else if (html_lexer->tokens[html_lexer->tokens_len - 1]->type == tag_type_TAG_NAME)
            {
                str last_token_str = html_lexer->tokens[html_lexer->tokens_len - 1]->value;
                last_token_str = realloc(last_token_str, sizeof(i8) * (strlen(last_token_str) + 2));
                last_token_str[strlen(last_token_str) + 0] = html_lexer->curr_char;
                last_token_str[strlen(last_token_str) + 1] = '\0';
            }
        } 
        else 
        {            
            if (html_lexer->tokens[html_lexer->tokens_len - 1]->type != tag_type_TEXT)
            {
                html_append_token(html_lexer, html_create_token(
                    tag_type_TEXT, char_to_str(html_lexer->curr_char)));
            }
            else if (html_lexer->tokens[html_lexer->tokens_len - 1]->type == tag_type_TEXT)
            {
                str last_token_str = html_lexer->tokens[html_lexer->tokens_len - 1]->value;
                last_token_str = realloc(last_token_str, sizeof(i8) * (strlen(last_token_str) + 2));
                last_token_str[strlen(last_token_str) + 0] = html_lexer->curr_char;
                last_token_str[strlen(last_token_str) + 1] = '\0';
            }
        }

        html_lexer->index++;
    }

    // html_print_tokens(html_lexer);
}

void html_get_next_char(html_lexer_t* html_lexer)
{
    html_lexer->curr_char = html_lexer->value[html_lexer->index];
    html_lexer->index++;
}

void html_print_tokens(html_lexer_t* html_lexer)
{
    for (i32 i = 0; i < html_lexer->tokens_len; i++)
    {
        switch (html_lexer->tokens[i]->type)
        {
            case tag_type_TAG_START:
                printf("{ type: tag_type_TAG_START, value: %s },\n", html_lexer->tokens[i]->value);
                break;
            case tag_type_TAG_NAME:
                printf("{ type: tag_type_TAG_NAME, value: %s },\n", html_lexer->tokens[i]->value);
                break;
            case tag_type_TAG_END:
                printf("{ type: tag_type_TAG_END, value: %s },\n", html_lexer->tokens[i]->value);
                break;
            case tag_type_TAG_START_END:
                printf("{ type: tag_type_TAG_START_END, value: %s },\n", html_lexer->tokens[i]->value);
                break;
            case tag_type_ATTR_NAME:
                printf("{ type: tag_type_ATTR_NAME, value: %s },\n", html_lexer->tokens[i]->value);
                break;
            case tag_type_ATTR_VALUE:
                printf("{ type: tag_type_ATTR_VALUE, value: %s },\n", html_lexer->tokens[i]->value);
                break;
            case tag_type_TEXT:
                printf("{ type: tag_type_TEXT, value: %s },\n", html_lexer->tokens[i]->value);
                break;
            case tag_type_NONE:
                printf("{ type: tag_type_NONE },\n");
                break;
        }
    }
}