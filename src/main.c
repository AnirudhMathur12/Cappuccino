#include "tokenizer.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *loadFromFile(const char *fileName);
char **splitLines(char *buffer, char *delim);

int main(int argv, char **argc) {
    char *buffer = loadFromFile(argc[1]);

    char **lines = splitLines(buffer, "\n");

    struct Token *tokens;
    for (char **iter = lines; *iter != NULL; ++iter) {
        tokens = tokenizer(*iter);
        struct Token *temp = tokens;
        printf("\n");
        do {
            printf("Type: %d, Name: %s\n", temp->tok_type, temp->tok_name);
            temp++;
        } while (temp->tok_type != tok_end);
    }
    // free(temp);

    free(tokens);
    free(lines);

    free(buffer);
    return 0;
}

char *loadFromFile(const char *filename) {
    FILE *fp = fopen(filename, "r");

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    char *buffer = (char *)malloc((file_size + 1) * sizeof(char));
    if (!buffer) {
        perror("Buffer allocation failed!");
        fclose(fp);
        return NULL;
    }

    size_t bytes_read = fread(buffer, sizeof(char), file_size, fp);
    if (bytes_read != file_size) {
        perror("File reading failed");
        free(buffer);
        fclose(fp);
        return NULL;
    }

    buffer[file_size] = '\0';

    return buffer;
}

char **splitLines(char *buffer, char *delim) {
    char *buffer_cpy = (char *)malloc(strlen(buffer) * sizeof(char));
    strcpy(buffer_cpy, buffer);
    strtok(buffer_cpy, delim);
    int size = 1;
    while (strtok(NULL, delim))
        size++;
    free(buffer_cpy);

    int char_limit = 80;
    char **lines = (char **)malloc((size + 1) * sizeof(char *));
    for (int i = 0; i < size; i++) {
        lines[i] = malloc(char_limit * sizeof(char));
    }

    lines[0] = strtok(buffer, delim);
    for (int i = 1; i < size; i++) {
        lines[i] = strtok(NULL, delim);
    }
    lines[size] = NULL;

    return lines;
}
