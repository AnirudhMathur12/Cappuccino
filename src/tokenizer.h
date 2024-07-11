#ifndef UTILS_H_
#define UTILS_H_
struct Token {
    enum {
        TOK_IDENTIFIER,
        TOK_SPCL,
        TOK_OPERATOR,
        TOK_CONSTANT,
        TOK_KEYWORD,
        TOK_NEWLINE,
        TOK_END
    } tok_type;
    char *tok_name;
    struct Token *next;
};

struct Token *tokenize(char *data);
#endif
