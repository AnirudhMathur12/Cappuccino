#include "tokenizer.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

#define KEYWORD_QUANTITY 3

char brackets[4][2] = {{'(', ')'}, {'{', '}'}, {'[', ']'}, {'<', '>'}};

char *keywords[KEYWORD_QUANTITY] = {"int", "str", "char"};

struct Token *createToken(char *tok_name, enum token_type tok_type) {
    struct Token *temp = (struct Token *)malloc(sizeof(struct Token));
    temp->tok_name = malloc(2048);
    temp->tok_name = tok_name;
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
        if (data[i] == ' ') {
            buffer_reset = i + 1;
            buffer[i - buffer_reset] = '\0';
            for (int i = 0; i < KEYWORD_QUANTITY; i++) {
                if (!strcmp(buffer, keywords[i])) {
                    if (head == NULL) {
                        head = createToken(buffer, TOK_KEYWORD);
                        current = head;
                        break;
                    }
                    struct Token *temp = createToken(buffer, TOK_KEYWORD);
                    current->next = temp;
                    current = current->next;
                }

                continue;
            }
            free(buffer);
            buffer = malloc(2048);
        }
        buffer[i - buffer_reset] = data[i];
    }
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
        return 0;
    }
    return 1;
}
