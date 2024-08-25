// Copyright (C) 2024 Anirudh Mathur

#include <stdlib.h>

#include <iostream>
#include <vector>

#include "ast.hpp"
#include "parser.hpp"
#include "tokenizer.hpp"
#include "utils.hpp"

int main(int argc, char **argv)
{
    std::string file_content = read_file(argv[1]);
    std::cout << file_content << std::endl;

    n_Tokenizer::Tokenizer &instance = n_Tokenizer::Tokenizer::GetInstance();

    instance.Tokenize(file_content);
    std::vector<n_Tokenizer::Token>::iterator it;

    for (std::vector<n_Tokenizer::Token>::iterator it = instance.tokens.begin();
         it != instance.tokens.end(); ++it)
    {
        it->printData();
    }

    n_Parser::Parser::GetInstance().Parse(instance.tokens);
    AbstractSyntaxTree::PrintVisitor p;

    n_Parser::Parser::GetInstance().abstract_syntax_tree.at(0)->accept(p);

    /*
    struct Token *head = tokenize(file_content);
    struct Token *iter = head;
    while (iter != NULL)
    {
        printf("Name: %s, Type: %d\n", iter->tok_name, iter->tok_type);
        iter = iter->next;
    }

    AST *ast = parse(head);
    std::cout << "Data type: " <<
    ast->data.AST_VARIABLE_DECLARATION.data_type
              << "\nVariable name: "
              << ast->data.AST_VARIABLE_DECLARATION.variable_name <<
    std::endl; ast = parse(NULL
    init_emitter();
    emit(*ast);

    free_tokens(head);
    */

    return 0;
}
