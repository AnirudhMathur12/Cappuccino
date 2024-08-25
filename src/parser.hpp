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
    std::vector<ASTNodePtr> abstract_syntax_tree;

private:
    Parser();
};

// emitter to be defined here

};  // namespace n_Parser
