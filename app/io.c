#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_FAILIURE 1

char* readFile(const char* path, const int buffer_size) {
  if (buffer_size <= 0) {
    fprintf(stderr, "buffer size must be positive and nonzero\n");
    exit(EXIT_FAILIURE);
  }
  FILE* file = fopen(path, "r");
  if (!file) {
    perror("failed to open file");
    fclose(file);
    exit(EXIT_FAILURE);
  }

  char* buffer = (char*)malloc(sizeof(char) * buffer_size);
  if (!buffer) {
    perror("memory allocation failed");
    fclose(file);
    exit(EXIT_FAILIURE);
  }

  size_t bytes_read = fread(buffer, 1, buffer_size - 1, file);
  if (bytes_read < buffer_size - 1) {
    buffer[bytes_read] = '\0'; 
    } else {
    buffer[buffer_size - 1] = '\0';
  }
  fclose(file);
  return buffer;
}

void writeFile(const char* path, const char data) {
  FILE* file = fopen(path,"w");
  if (!file) {
    perror("file failed to open");
    exit(EXIT_FAILIURE);
  }
  int count =
  fwrite(data,sizeof(char),)
}

int main(int argc, char** argv) {
  char* filecontent = readFile(argv[1],1024);
  printf("File content:\n%s\n",filecontent);
  free(filecontent);
}
