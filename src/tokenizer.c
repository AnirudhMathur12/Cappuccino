#include "tokenizer.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

#define KEYWORD_QUANTITY 4
#define OPERATOR_QUANTITY 5

char brackets[4][2] = {{'(', ')'}, {'{', '}'}, {'[', ']'}, {'<', '>'}};

char operators[OPERATOR_QUANTITY] = {'+', '-', '*', '/', ':'};
char *keywords[KEYWORD_QUANTITY] = {"int", "str", "char", "float"};

int isAlpha(char ch) {
    return ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122));
}

struct Token *createToken(char *tok_name, enum token_type tok_type) {
    struct Token *temp = (struct Token *)malloc(sizeof(struct Token));
    temp->tok_name = malloc(2048);
    strcpy(temp->tok_name, tok_name);
    temp->tok_type = tok_type;
    temp->next = NULL;

    return temp;
}

struct Token *tokenize(char *data) {
    struct Token *head = NULL;
    struct Token *current = NULL;
    if (!check_brackets(data)) {
        printf("\033[0;31m Error: All brackets aren't closed.\n\033[0m");
        return NULL;
    }

    char *buffer = malloc(2048);
    int buffer_reset = 0;

    for (int i = 0; i < data[i] != '\0'; i++) {
        if (!isAlpha(data[i])) {
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
            buffer_reset = i + 1;
            free(buffer);
            buffer = malloc(2048);
        }
        buffer[i - buffer_reset] = data[i];
    }
    return head;
}

struct Token *detectToken(char *str) {
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
