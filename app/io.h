#ifndef IO_H_
#define IO_H_
#include <stdio.h>
#include <stdlib.h>

char* readFile(const char* path, const int buffer_size); // read from files by path
void writeFile(const char* path, const char data[]); // write to files by path

#endif
