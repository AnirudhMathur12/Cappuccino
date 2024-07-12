#ifndef UTILS_H_
#define UTILS_H_
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 1000

struct Stack {
    char **arr;
    size_t len;
};

struct Stack *createStack();
void push(struct Stack *stack, char *data);
char *pop(struct Stack *stack);

char *charToStr(char c);
#endif
