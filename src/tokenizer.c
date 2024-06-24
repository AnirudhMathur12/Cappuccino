#include "tokenizer.h"
#include <string.h>

char *instructions[10] = {"define", "load"};
int instructions_size = 2;

char *trim(char *str) {
    char *end;
    char *str_copy = malloc(strlen(str) * sizeof(char));
    strcpy(str_copy, str);

    // Trim leading spaces
    while (isspace((unsigned char)*str_copy)) {
        str_copy++;
    }
    // All spaces?
    if (*str_copy == 0) {
        return str_copy;
    }

    // Trim trailing spaces
    end = str_copy + strlen(str_copy) - 1;
    while (end > str_copy && isspace((unsigned char)*end))
        end--;

    // Write new null terminator
    *(end + 1) = '\0';
    return str_copy;
}

int isNumber(const char *str) {
    // Handle empty string
    if (*str == '\0' || str == NULL) {
        return 0;
    }

    // Handle negative numbers
    if (*str == '-' || *str == '+') {
        str++;
    }

    // Check if each character is a digit
    while (*str != '\0') {
        if (!isdigit((unsigned char)*str)) {
            printf("this%c", *str);
            return 0;
        }
        str++;
    }
    return 1;
}

struct Token *tokenizer(char *instruction) {
    printf("Where's that damn error!\n");
    char *args, *args_copy = (char *)malloc(strlen(args) + 1);
    char *command = strtok(instruction, " ");
    args = strtok(NULL, "");
    printf("Jeez-loize\n");
    strcpy(args_copy, args);
    args_copy[strlen(args) + 1] = '\0';
    printf("This\n");
    int size = 1;
    char *arg = strtok(args, ",");
    printf("Huh??\n");
    while (strtok(NULL, ",")) {
        size++;
    }
    struct Token *tokens =
        (struct Token *)malloc((size + 1) * sizeof(struct Token));

    tokens[0] = (struct Token){tok_instruction, command};
    arg = NULL;
    tokens[1] = (struct Token){tok_identifier, strtok(args_copy, ",")};
    int iter = 2;
    while (1) {
        arg = strtok(NULL, ",");
        if (arg == NULL) {
            break;
        }
        arg = trim(arg);
        printf("heh%s\n", arg);
        printf("%d\n", isNumber(arg));
        int i = 0;
        if (isNumber(arg)) {
            tokens[iter++] = (struct Token){tok_const, arg};
        } else {
            tokens[iter++] = (struct Token){tok_identifier, arg};
        }
    }
    tokens[size + 1] = (struct Token){tok_end, NULL};

    return tokens;
}
