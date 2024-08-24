// Copyright (C) 2024 Anirudh Mathur
#ifndef PARSER_H_
#define PARSER_H_

#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.hpp"

typedef struct AST AST;

struct AST {
    enum tag { AST_ASSIGNMENT, AST_VARIABLE_DECLARATION, AST_EXPRESSION } tag;
    union {
        struct AST_EXPRESSION {
            union {
                int data_in;
                // str, float, other stuff
            };
        } AST_EXPRESSION;
        struct AST_VARIABLE_DECLARATION {
            char *data_type;
            char *variable_name;
        } AST_VARIABLE_DECLARATION;
        struct AST_ASSIGNMENT {
            char *variable_name;
            struct AST_EXPRESSION data;
        } AST_ASSIGNMENT;

    } data;
};

struct AST *parse(struct Token *token);

#endif
