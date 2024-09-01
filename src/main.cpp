// Copyright (C) 2024 Anirudh Mathur

#include <cstdlib>
#include <iostream>
#include <vector>

#include "ast.hpp"
#include "parser.hpp"
#include "tokenizer.hpp"
#include "utils.hpp"

int main(int argc, char **argv)
{
    std::string file_content = read_file(argv[1]);

    n_Tokenizer::Tokenizer &s_instance = n_Tokenizer::Tokenizer::GetInstance();
    n_Parser::Parser &p_instance = n_Parser::Parser::GetInstance();

    s_instance.Tokenize(file_content);
    std::vector<n_Tokenizer::Token>::iterator it;

    for (std::vector<n_Tokenizer::Token>::iterator it =
             s_instance.tokens.begin();
         it != s_instance.tokens.end(); ++it)
    {
        (*it).printData();
    }
    std::cout << std::endl;
    /*

    p_instance.Parse(s_instance.tokens);
    AbstractSyntaxTree::PrintVisitor p;
    AbstractSyntaxTree::Emitter &e_Instance =
        AbstractSyntaxTree::Emitter::GetInstance();
    AbstractSyntaxTree::EmitVisitor e;

    for (std::vector<AbstractSyntaxTree::ASTNodePtr>::iterator it =
             p_instance.abstract_syntax_tree.begin();
         it != p_instance.abstract_syntax_tree.end(); ++it)
    {
        (*it)->accept(p);
        (*it)->accept(e);
    }

    e_Instance.close_buf();

    system("clang -c -o main.o main.s");
    system("clang main.o utils.o -o a.out");
    */

    return 0;
}
