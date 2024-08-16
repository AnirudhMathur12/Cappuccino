// Copyright (C) 2024 Anirudh Mathur

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

void freeStack(struct Stack *stack) {
    for (int i = 0; i < STACK_SIZE; i++) {
        free(stack->arr[i]);
    }
    free(stack->arr);
    free(stack);
}

char *read_file(char *filename) {
    FILE *source;

    source = fopen(filename, "r");
    if (source == NULL) {
        printf("Error: File not found or could not open it.\n");
        return NULL;
    }

    fseek(source, 0, SEEK_END);
    size_t file_size_bytes = ftell(source);
    fseek(source, 0, SEEK_SET);

    char *buffer = (char *)malloc(file_size_bytes + 1);

    fread(buffer, 1, file_size_bytes, source);
    buffer[file_size_bytes] = '\0';

    fclose(source);

    return buffer;
}

int isAlpha(char ch) {
    return ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122));
}
