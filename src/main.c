#include "tokenizer.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char *file_content = read_file(argv[1]);
    struct Token *head = tokenize(file_content);
    struct Token *iter = head;
    while (iter != NULL) {
        printf("Name: %s, Type: %d\n", iter->tok_name, iter->tok_type);
        iter = iter->next;
    }

    free_tokens(head);

    return 0;
}
