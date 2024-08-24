// Copyright (C) 2024 Anirudh Mathur
#include "parser.hpp"

#include "tokenizer.hpp"

struct Token *bookmark = NULL;
int int_count = 0;

/*

struct AST *parse(struct Token *head)
{
    struct Token *iter = NULL;
    if (head == NULL)
    {
        head = bookmark;
    }
    iter = head;
    int count = 0;
    while (iter->tok_type != TOK_NEWLINE)
    {
        count++;
        iter = iter->next;
    }
    struct AST *ast = (struct AST *)malloc(sizeof(struct AST));
    switch (count)
    {
    case 2:
        // it is a variable decl;
        ast->tag = AST_VARIABLE_DECLARATION;
        ast->data.AST_VARIABLE_DECLARATION = (struct AST_VARIABLE_DECLARATION){
            head->tok_name, (head = head->next)->tok_name};
        int_count++;
    case 3:
        ast->tag = AST_ASSIGNMENT;
        ast->data.ast
    }
    if (head->next->tok_type == TOK_NEWLINE)
    {
        head = head->next->next;
    }
    bookmark = head;
    return ast;
}
*/
