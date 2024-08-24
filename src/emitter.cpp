#include "emitter.hpp"
#include <stdio.h>
#include <stdlib.h>

FILE *asm_file = NULL;
extern int int_count;

void init_emitter() {
    asm_file = fopen("main.s", "w");
    fprintf(asm_file, ".global _main\n.align 4\n\n_main:\n");
    int i;
    for (i = 0; i < int_count; i += 4)
        ;
    fprintf(asm_file, "\tsub sp, sp, %d\n", i * 4);
}

void emit(AST ast) {}
