// Copyright (C) 2024 Anirudh Mathur

#pragma once
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

namespace n_Tokenizer
{

enum token_type
{
    TOK_IDENTIFIER,
    TOK_SPCL,
    TOK_OPERATOR,
    TOK_CONSTANT,
    TOK_KEYWORD,
    TOK_NEWLINE,
    TOK_DATATYPE,
    TOK_BRACKET_START,
    TOK_BRACKET_END
};

class Token
{
public:
    enum token_type tok_type;
    std::string tok_name;

    void printData();
    Token(std::string _tok_name, token_type _tok_type);
    Token createToken(std::string data);
};

class Tokenizer
{
public:
    Tokenizer(const Tokenizer &) = delete;
    static Tokenizer &GetInstance();
    void Tokenize(std::string);
    Token assignToken(std::string data);

    std::vector<Token> tokens;

private:
    Tokenizer();
};

};  // namespace n_Tokenizer
