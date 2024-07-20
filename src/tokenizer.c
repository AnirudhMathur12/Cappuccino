#include "tokenizer.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

#define KEYWORD_QUANTITY 6
#define OPERATOR_QUANTITY 6
#define SPECIAL_SYMBOL_SIZE 8

char brackets[4][2] = {{'(', ')'}, {'{', '}'}, {'[', ']'}, {'<', '>'}};

char special_symbols[SPECIAL_SYMBOL_SIZE] = {'(', ')', '{', '}',
                                             '[', ']', ':', '.'};
char operators[OPERATOR_QUANTITY] = {'+', '-', '*', '/', '='};
char *keywords[KEYWORD_QUANTITY] = {"int",   "str",    "char",
                                    "float", "return", "void"};
char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

struct Token *createToken(char *tok_name, enum token_type tok_type) {
    struct Token *temp = (struct Token *)malloc(sizeof(struct Token));
    temp->tok_name = malloc(2048);
    strcpy(temp->tok_name, tok_name);
    temp->tok_type = tok_type;
    temp->next = NULL;

    return temp;
}

struct Token *tokenize(char *data) {
    if (!strcmp(data, "")) {
        return NULL;
    }
    struct Token *head = NULL;
    struct Token *current = NULL;
    if (!check_brackets(data)) {
        printf("\033[0;31m Error: All brackets aren't closed.\n\033[0m");
        return NULL;
    }

    char *buffer = malloc(2048);
    int buffer_reset = 0;

    for (int i = 0; data[i] != '\0'; i++) {
        if (!isAlpha(data[i]) && (data[i - 1] != ' ') &&
            (data[i - 1] != '\n')) {
            buffer[i - buffer_reset] = '\0';
            struct Token *tok = detectToken(buffer);
            if (head == NULL) {
                head = tok;
                current = head;
            } else {
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = tok;
            }
            buffer_reset = i;
        }
        if (data[i] == ' ' || data[i] == '\n') {
            buffer_reset++;
            continue;
        }
        buffer[i - buffer_reset] = data[i];
        // printf("%c\n", buffer[i - buffer_reset]);
    }

    return head;
}

struct Token *detectToken(char *str) {
    if (!strcmp(str, charToStr(';'))) {
        return createToken(";", TOK_NEWLINE);
    }
    for (int i = 0; i < KEYWORD_QUANTITY; i++) {
        if (!strcmp(str, keywords[i])) {
            return createToken(str, TOK_KEYWORD);
        }
    }
    for (int i = 0; i < OPERATOR_QUANTITY; i++) {
        if (!strcmp(str, charToStr(operators[i]))) {
            return createToken(str, TOK_OPERATOR);
        }
    }
    for (int i = 0; i < 10; i++) {
        if (!strcmp(str, charToStr(digits[i]))) {
            return createToken(str, TOK_CONSTANT);
        }
    }
    for (int i = 0; i < SPECIAL_SYMBOL_SIZE; i++) {
        if (!strcmp(str, charToStr(special_symbols[i]))) {
            return createToken(str, TOK_SPCL);
        }
    }
    return createToken(str, TOK_IDENTIFIER);
}

int check_brackets(char *data) {

    struct Stack *bracket_stack = createStack();

    for (int i = 0; data[i] != '\0'; i++) {
        for (int j = 0; j < 4; j++) {
            if (data[i] == brackets[j][0]) {
                push(bracket_stack, charToStr(data[i]));
            } else if (data[i] == brackets[j][1]) {
                char *bracket = pop(bracket_stack);
                if (charToStr(brackets[j][0]) == bracket) {
                    push(bracket_stack, bracket);
                }
            }
        }
    }
    if (bracket_stack->len != -1) {
        freeStack(bracket_stack);
        return 0;
    }
    freeStack(bracket_stack);
    return 1;
}
