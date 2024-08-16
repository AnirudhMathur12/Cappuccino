// Copyright (C) 2024 Anirudh Mathur

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
void freeStack(struct Stack *stack);

char *charToStr(char c);

char *read_file(char *filename);
int isAlpha(char ch);
#endif
