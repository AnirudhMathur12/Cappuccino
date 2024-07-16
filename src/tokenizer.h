#ifndef TOKENIZER_H_
#define TOKENIZER_H_

enum token_type {
    TOK_IDENTIFIER,
    TOK_SPCL,
    TOK_OPERATOR,
    TOK_CONSTANT,
    TOK_KEYWORD,
    TOK_NEWLINE,
    TOK_END
};

struct Token {
    enum token_type tok_type;
    char *tok_name;
    struct Token *next;
};

struct Token *createToken(char *tok_name, enum token_type tok_type);
struct Token *detectToken(char *str);

struct Token *tokenize(char *data);
int check_brackets(char *data);
#endif
