#include "tokenizer.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_size_t.h>

int main(int argc, char **argv) {
    char *file_content = read_file(argv[1]);
    printf("%s\n", file_content);
    struct Token *head = tokenize(file_content);
    do {
        printf("Name: %s, Type: %d\n", head->tok_name, head->tok_type);
        head = head->next;
    } while (head != NULL);
    return 0;
}
