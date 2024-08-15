#include "parser.h"
#include "tokenizer.h"

struct AST parse(struct Token *head) {
    struct Token *iter = NULL;
    *iter = *head;
    int count = 0;
    do {
        count++;
        iter = iter->next;
    } while (iter->tok_type != TOK_NEWLINE);
    struct Token tok_arr[count];
}
