// Copyright (C) 2024 Anirudh Mathur

#pragma once
#include <iostream>
#include <sstream>
#include <vector>

namespace n_Tokenizer
{

class Token;

enum token_type : unsigned char
{
    TOK_IDENTIFIER,
    TOK_SPCL,
    TOK_OPERATOR,
    TOK_CONSTANT,
    TOK_KEYWORD,
    TOK_NEWLINE
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

class Token
{
public:
    enum token_type tok_type;
    std::string tok_name;
    struct Token *next;

    void printData();
    Token(std::string _tok_name, token_type _tok_type);
    Token createToken(std::string data);
};

};  // namespace n_Tokenizer
