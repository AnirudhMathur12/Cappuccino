// Copyright (C) 2024 Anirudh Mathur
#pragma once

#include "ast.hpp"
#include "tokenizer.hpp"

namespace n_Parser
{

class Parser
{
public:
    Parser(const Parser &) = delete;
    static Parser &GetInstance();
    void Parse(std::vector<n_Tokenizer::Token> tokens);
    std::vector<AbstractSyntaxTree::ASTNodePtr> abstract_syntax_tree;
    int GetByteCount();

private:
    Parser();
    int int_count;
};

// emitter to be defined here

};  // namespace n_Parser
