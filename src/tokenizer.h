#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum token_type {
    tok_instruction,
    tok_identifier,
    tok_const,
    tok_string,
    tok_spclsymbol,
    tok_end
};

struct Token {
    enum token_type tok_type;
    char *tok_name;
};

struct Token *tokenizer(char *instruction);
char *trim(char *str);
int isNumber(const char *str);
#endif // !TOKENIZER_H
