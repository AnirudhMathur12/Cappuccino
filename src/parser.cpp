// Copyright (C) 2024 Anirudh Mathur
#include "parser.hpp"

#include <any>
#include <memory>

#include "ast.hpp"
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
         it != tokens.end(); ++it)
    {
        buffer.push_back(*it);
        // it->printData();
        if (it->tok_type != n_Tokenizer::TOK_NEWLINE) continue;
        buffer.pop_back();

        if (buffer.size() == 2 &&
            buffer.at(0).tok_type == n_Tokenizer::TOK_KEYWORD &&
            buffer.at(1).tok_type == n_Tokenizer::TOK_IDENTIFIER)
        {
            // std::cout << "VariableDeclaration detected\n";
            AbstractSyntaxTree::ASTNodePtr ptr =
                std::make_unique<AbstractSyntaxTree::VariableDeclaration>(
                    (buffer.at(0).tok_name), (buffer.at(1).tok_name));
            abstract_syntax_tree.push_back(std::move(ptr));
            if (buffer.at(0).tok_name == "int")
            {
                int_count += 4;
            }
            std::cout << "Variable Declared.\n";
        }
        else if (buffer.size() == 3 &&
                 buffer.at(0).tok_type == n_Tokenizer::TOK_IDENTIFIER &&
                 buffer.at(1).tok_type == n_Tokenizer::TOK_OPERATOR)
        {
            // std::cout << "VariableDefinition detected\n";
            AbstractSyntaxTree::ASTNodePtr ptr =
                std::make_unique<AbstractSyntaxTree::VariableDefinition>(
                    buffer.at(0).tok_name,
                    std::make_unique<AbstractSyntaxTree::IntegerLiteral>(
                        std::stoi(buffer.at(2).tok_name)));
            abstract_syntax_tree.push_back(std::move(ptr));
            std::cout << "Variable Defined\n";
        }
        buffer.clear();
    }
}

int Parser::GetByteCount() { return int_count; }

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
