#include <string.h>
#include "stdio.h"
#include "stdlib.h"

int charToInt(const char chr) {
  int num = 0;
  switch (chr) {
    case '1':
      num = 1;
      break;
    case '2':
      num = 2;
      break;
    case '3':
      num = 3;
      break;
    case '4':
      num = 4;
      break;
    case '5':
      num = 5;
      break;
    case '6':
      num = 6;
      break;
    case '7':
      num = 7;
      break;
    case '8':
      num = 8;
      break;
    case '9':
      num = 9;
      break;
    default:
      break;
  }
  return num;
}

int lineToNumStraight(const char* line) {
  int lineLen = strlen(line);
  int i = 0;
  while (i < lineLen) {
    if (strncmp(&line[i], "one", strlen("one")) == 0) {
      return 1;
    }
    if (strncmp(&line[i], "two", strlen("two")) == 0) {
      return 2;
    }
    if (strncmp(&line[i], "three", strlen("three")) == 0) {
      return 3;
    }
    if (strncmp(&line[i], "four", strlen("four")) == 0) {
      return 4;
    }
    if (strncmp(&line[i], "five", strlen("five")) == 0) {
      return 5;
    }
    if (strncmp(&line[i], "six", strlen("six")) == 0) {
      return 6;
    }
    if (strncmp(&line[i], "seven", strlen("seven")) == 0) {
      return 7;
    }
    if (strncmp(&line[i], "eight", strlen("eight")) == 0) {
      return 8;
    }
    if (strncmp(&line[i], "nine", strlen("nine")) == 0) {
      return 9;
    }
    int charInt;
    if ((charInt = charToInt(line[i])) != 0) {
      return charInt;
    }
    i++;
  }
  return 0;
}

int lineToNumBackwards(const char* line) {
  int i = strlen(line);
  while (i >= 0) {
    int charInt;
    if ((charInt = charToInt(line[i])) != 0) {
      return charInt;
    }
    if (i >= 3) {
      if (strncmp(&line[i-3], "one", strlen("one")) == 0) {
        return 1;
      }
      if (strncmp(&line[i-3], "two", strlen("two")) == 0) {
        return 2;
      }
      if (strncmp(&line[i-3], "six", strlen("six")) == 0) {
        return 6;
      }
    }
    if (i >= 4) {
      if (strncmp(&line[i-4], "four", strlen("four")) == 0) {
        return 4;
      }
      if (strncmp(&line[i-4], "five", strlen("five")) == 0) {
        return 5;
      }
      if (strncmp(&line[i-4], "nine", strlen("nine")) == 0) {
        return 9;
      }
    }
    if (i >= 5) {
      if (strncmp(&line[i-5], "three", strlen("three")) == 0) {
        return 3;
      }
      if (strncmp(&line[i-5], "seven", strlen("seven")) == 0) {
        return 7;
      }
      if (strncmp(&line[i-5], "eight", strlen("eight")) == 0) {
        return 8;
      }
    }
    i--;
  }
  return 0;
}

int main(void) {
  FILE* fp;
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  fp = fopen("one_input.txt", "r");
  if (fp == NULL) {
    printf("Input file 'one_input.txt' was not found.\n");
    exit(EXIT_FAILURE);
  }
  int sum = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    int num = lineToNumStraight(line) * 10 + lineToNumBackwards(line);
    sum += num;
  }
  printf("%d\n", sum);
  fclose(fp);
  if (line) free(line);
  exit(EXIT_SUCCESS);
}

