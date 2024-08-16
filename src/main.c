// Copyright (C) 2024 Anirudh Mathur

#include "parser.h"
#include "tokenizer.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char *file_content = read_file(argv[1]);
    struct Token *head = tokenize(file_content);
    struct Token *iter = head;
    while (iter != NULL) {
        printf("Name: %s, Type: %d\n", iter->tok_name, iter->tok_type);
        iter = iter->next;
    }

    AST *ast = parse(head);
    printf("Data type: %s\nIdentifier name: %s\n",
           ast->data.AST_VARIABLE_DECLARATION.data_type,
           ast->data.AST_VARIABLE_DECLARATION.variable_name);

    free_tokens(head);

    return 0;
}
