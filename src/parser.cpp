// Copyright (C) 2024 Anirudh Mathur
#include "parser.hpp"

#include "tokenizer.hpp"

using namespace n_Parser;

Parser& Parser::GetInstance()
{
    static Parser p_Instance;
    return p_Instance;
}

Parser::Parser() {}

void Parser::Parse(std::vector<n_Tokenizer::Token> tokens)
{
    std::vector<n_Tokenizer::Token> buffer;
    for (std::vector<n_Tokenizer::Token>::iterator it = tokens.begin();
         it->tok_type != n_Tokenizer::TOK_NEWLINE; ++it)
    {
        buffer.push_back(*it);
    }
    if (buffer.size() == 2 &&
        buffer.at(0).tok_type == n_Tokenizer::TOK_KEYWORD &&
        buffer.at(1).tok_type == n_Tokenizer::TOK_IDENTIFIER)
    {
        AST temp;
        temp.tag = AST::AST_VARIABLE_DECLARATION;
        temp.data.AST_VARIABLE_DECLARATION.data_type = buffer.at(0).tok_name;
        abstract_syntax_tree.push_back();
    }
}
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
