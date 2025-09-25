#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_FAILIURE 1

//reads from a file given the path or name of the file and the size of the buffer to create for the read text
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

//writes to a file given the data to write and the path of the file to write to
void writeFile(const char* path, const char data[]) {
  FILE* file = fopen(path,"w");
  if (!file) {
    perror("file failed to open");
    exit(EXIT_FAILIURE);
  }

  int count = strlen(data);
  fwrite(data,sizeof(char),count,file);
}

// tests out the writeFile and readFile functions
int main(int argc, char** argv) {
  char command;
  command = *argv[1];
  if (command == 'w') {
    writeFile(argv[2],argv[3]);
  } else if (command == 'r') {
    char* filecontent = readFile(argv[1],1024);
    printf("File content:\n%s\n",filecontent);
    free(filecontent);
  } else {
    fprintf(stderr, "command must be r or w\n");
    exit(EXIT_FAILIURE);
  }
}
