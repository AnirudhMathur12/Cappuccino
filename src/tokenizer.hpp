// Copyright (C) 2024 Anirudh Mathur

#pragma once
#include <iostream>
#include <sstream>
#include <vector>

namespace n_Tokenizer
{

class Token;

enum token_type
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
    std::vector<Token> GetTokens();
    Token assignToken(std::string data);

private:
    Tokenizer();
    std::vector<Token> tokens;
};

class Token
{
    enum token_type tok_type;
    std::string tok_name;
    struct Token *next;

public:
    void printData();
    Token(std::string _tok_name, token_type _tok_type);
    Token createToken(std::string data);
};

};  // namespace n_Tokenizer
