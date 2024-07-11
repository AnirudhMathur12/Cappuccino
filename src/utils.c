#include "utils.h"

char *charToStr(char c) {
    char *ch = (char *)malloc(sizeof(char) * 2);
    ch[0] = c;
    ch[1] = '\0';
    return ch;
}

struct Stack *createStack() {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->arr = calloc(sizeof(char), STACK_SIZE);
    stack->len = -1;

    return stack;
}

void push(struct Stack *stack, char *data) {
    if (stack->len == STACK_SIZE - 1) {
        printf("Stack size exceeded!\n");
        return;
    }
    stack->arr[++stack->len] = data;
}

char *pop(struct Stack *stack) {
    if (stack->len == -1) {
        printf("Stack is empty!\n");
    }

    char *data = stack->arr[stack->len];
    stack->arr[stack->len--] = NULL;
    return data;
}
