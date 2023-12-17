#ifndef FILE_H
#define FILE_H

#include "stdio.h"
#include "stdlib.h"


static FILE* fp;
static char* line = NULL;
static size_t len = 0;
static ssize_t read;

static void open_file() {
  fp = fopen("input.txt", "r");
  if (fp == NULL) {
    printf("Input file 'input.txt' was not found.\n");
    exit(EXIT_FAILURE);
  }
}

#endif //FILE_H
