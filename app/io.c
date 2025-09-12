#include "io.h"
#include <stdio.h>
#include <stdlib.h>


char* readFile(const char* path, size_t* buffer_size) {
    FILE* file = fopen(path, "r");
    if (!file) {
        perror("failed to open file");
        exit(EXIT_FAILURE);
    }

    char *buffer = NULL;
    size_t buffer_capacity = 1024;
    buffer = (char *)malloc(buffer_capacity * sizeof(char));
    if (!buffer) {
        perror("memory allocation failed");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    int c;
    size_t size = 0;
    while ((c = fgetc(file)) != EOF) {
        if (size >= buffer_capacity) {
            buffer_capacity *= 2;
            buffer = (char*) realloc(buffer, buffer_capacity * sizeof(char));
            if (!buffer) {
                perror("memory allocation failed");
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
        buffer[size++] = (char)c;
    }

    fclose(file);
    buffer[size] = '\0';
    *buffer_size = size;
    return buffer;
}
