#include "tokenizer.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

char brackets[4][2] = {{'(', ')'}, {'{', '}'}, {'[', ']'}, {'<', '>'}};

struct Token *tokenize(char *data) {
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
        printf("ERROR: Brackets have not been closed");
    }

    return NULL;
}
