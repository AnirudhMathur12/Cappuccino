#include "tokenizer.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char *loadFromFile(const char *fileName);


int main(int argv, char **argc) {
    char *buffer = loadFromFile(argc[1]);
    struct Token *tokens = tokenizer(buffer);
    struct Token *temp = tokens;
    printf("Finished tokenizing!\n");
    printf("\n");
    do {
        printf("Type: %d, Name: %s\n", temp->tok_type, temp->tok_name);
        temp++;
    }while (temp->tok_type != tok_end);
    //free(temp);

    free(tokens);

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
