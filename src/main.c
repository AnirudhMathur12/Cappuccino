#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_size_t.h>

char *read_file(char *filename);

int main(int argc, char **argv) {
    char *file_content = read_file(argv[1]);
    return 0;
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
    free(source);

    return buffer;
}
