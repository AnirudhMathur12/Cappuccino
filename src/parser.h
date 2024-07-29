#ifndef PARSER_H_
#define PARSER_H_

#include "tokenizer.h"

struct AST {
    enum tag { AST_ASSIGNMENT, AST_VARIABLE_DECLARATION, AST_EXPRESSION } tag;
    union {
        struct AST_EXPRESSION {
            union {
                int data_in;
            };
        };
        struct AST_DECLARATION {
            char *data_type;
            char *variable_name;
        };

    } data;
};

struct AST parse(struct Token *token);

#endif
