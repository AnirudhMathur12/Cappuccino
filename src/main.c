#include "tokenizer.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char *file_content = read_file(argv[1]);
    struct Token *head = tokenize(file_content);
    while (head != NULL) {
        printf("Name: %s, Type: %d\n", head->tok_name, head->tok_type);
        head = head->next;
    }
    return 0;
}
