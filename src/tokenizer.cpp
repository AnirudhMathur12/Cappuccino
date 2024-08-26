// Copyright (C) 2024 Anirudh Mathur

#include "tokenizer.hpp"

#include <array>
#include <cctype>
#include <stack>
#include <vector>

using namespace n_Tokenizer;

// Tokenizer
std::array<std::string, 3> brackets_start = {"(", "{", "["};
std::array<std::string, 3> brackets_end = {")", "}", "]"};
std::array<std::string, 4> keywords = {"int", "float", "string"};
std::array<std::string, 10> operators = {"="};

Tokenizer &Tokenizer::GetInstance()
{
    static Tokenizer t_instance;
    return t_instance;
}

void Tokenizer::Tokenize(std::string data_stream)
{
    if (data_stream.length() == 0)
    {
        tokens = {};
    }

    std::stringstream buffer;

    std::stack<char> bracket_stack;

    for (std::string::const_iterator i = data_stream.cbegin();
         i != data_stream.cend(); ++i)
    {
        if (!std::isalnum(*i))
        {
            if (buffer.str().length() != 0)
                tokens.push_back(assignToken(buffer.str()));
            buffer.str("");
            buffer.clear();
        }
        if (!std::isspace(*i))
        {
            buffer << *i;
        }
    }
}

Token Tokenizer::assignToken(std::string data)
{
    if (std::find(keywords.begin(), keywords.end(), data) != keywords.end())
    {
        return Token(data, TOK_KEYWORD);
    }
    else if (std::all_of(data.begin(), data.end(), ::isdigit))
    {
        return Token(data, TOK_CONSTANT);
    }
    else if (std::find(operators.begin(), operators.end(), data) !=
             operators.end())
    {
        return Token(data, TOK_OPERATOR);
    }
    else if (data == ";")
    {
        return Token(data, TOK_NEWLINE);
    }
    return Token(data, TOK_IDENTIFIER);
}

Tokenizer::Tokenizer() {}

// Token
Token::Token(std::string _tok_name, token_type _tok_type)
    : tok_name(_tok_name), tok_type(_tok_type)
{
}

void Token::printData()
{
    std::cout << "Token Name: " << tok_name << "\t Token Type: " << tok_type
              << std::endl;
}

/*
std::array<std::string, 3> brackets = {"()", "{}", "[]"};

char special_symbols[SPECIAL_SYMBOL_SIZE] = {'(', ')', '{', '}',
                                             '[', ']', ':', '.'};
char operators[OPERATOR_QUANTITY] = {'+', '-', '*', '/', '='};
char *keywords[KEYWORD_QUANTITY] = {"int",   "str",    "char",
                                    "float", "return", "void"};
char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

struct Token *createToken(char *tok_name, enum token_type tok_type)
{
    struct Token *temp = (struct Token *)malloc(sizeof(struct Token));
    temp->tok_name = malloc(2048);
    strcpy(temp->tok_name, tok_name);
    temp->tok_type = tok_type;
    temp->next = NULL;

    return temp;
}

struct Token *tokenize(char *data)
{
    if (!strcmp(data, ""))
    {
        return NULL;
    }
    struct Token *head = NULL;
    struct Token *current = NULL;
    if (!check_brackets(data))
    {
        printf("\033[0;31m Error: All brackets aren't closed.\n\033[0m");
        return NULL;
    }

    char *buffer = malloc(2048);
    int buffer_reset = 0;

    for (int i = 0; data[i] != '\0'; i++)
    {
        if (!isAlpha(data[i]) && (data[i - 1] != ' ') && (data[i - 1] != '\n'))
        {
            buffer[i - buffer_reset] = '\0';
            struct Token *tok = detectToken(buffer);
            if (head == NULL)
            {
                head = tok;
                current = head;
            }
            else
            {
                while (current->next != NULL)
                {
                    current = current->next;
                }
                current->next = tok;
            }
            buffer_reset = i;
        }
        if (data[i] == ' ' || data[i] == '\n')
        {
            buffer_reset++;
            continue;
        }
        buffer[i - buffer_reset] = data[i];
        // printf("%c\n", buffer[i - buffer_reset]);
    }

    return head;
}

struct Token *detectToken(char *str)
{
    if (!strcmp(str, charToStr(';')))
    {
        return createToken(";", TOK_NEWLINE);
    }
    for (int i = 0; i < KEYWORD_QUANTITY; i++)
    {
        if (!strcmp(str, keywords[i]))
        {
            return createToken(str, TOK_KEYWORD);
        }
    }
    for (int i = 0; i < OPERATOR_QUANTITY; i++)
    {
        if (!strcmp(str, charToStr(operators[i])))
        {
            return createToken(str, TOK_OPERATOR);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (!strcmp(str, charToStr(digits[i])))
        {
            return createToken(str, TOK_CONSTANT);
        }
    }
    for (int i = 0; i < SPECIAL_SYMBOL_SIZE; i++)
    {
        if (!strcmp(str, charToStr(special_symbols[i])))
        {
            return createToken(str, TOK_SPCL);
        }
    }
    return createToken(str, TOK_IDENTIFIER);
}

int check_brackets(std::string data)
{
    std::stack<char> bracket_stack;

    for (std::string::const_iterator it = data.cbegin(); it != data.cend();
         ++it)
    {
        if
    }
}

void free_tokens(struct Token *head)
{
    if (head == NULL)
    {
        return;
    }

    struct Token *current = head;
    struct Token *prev = head;

    while (prev == NULL)
    {
        prev = current;
        current = current->next;
        free(prev);
    }
}
*/
