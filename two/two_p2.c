#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define RED_MAX       12
#define GREEN_MAX     13
#define BLUE_MAX      14

enum Colors {
  RED,
  GREEN,
  BLUE
};

struct ColorAmount {
  int amount;
  enum Colors color;
};

char** splitStr(char* str, const char* delimiter, int* numParts) {
  *numParts = 0;
  char* temp = strdup(str);
  char* token = strtok(temp, delimiter);
  while (token != NULL) {
    (*numParts)++;
    token = strtok(NULL, delimiter);
  }
  free(temp);
  char** parts = malloc(*numParts * sizeof(char*));
  int i = 0;
  token = strtok(str, delimiter);
  while (token != NULL) {
    parts[i] = strdup(token);
    token = strtok(NULL, delimiter);
    i++;
  }
  return parts;
}

struct ColorAmount getColorAmount(const char* ca) {
  struct ColorAmount colorAmount;
  int numParts;
  char** split = splitStr((char*) ca, " ", &numParts);
  int num = atoi(split[0]);
  if (strncmp("red", split[1], 3) == 0) {
    colorAmount.color = RED;
  } else if (strncmp("green", split[1], 5) == 0) {
    colorAmount.color = GREEN;
  } else if (strncmp("blue", split[1], 4) == 0) {
    colorAmount.color = BLUE;
  }
  colorAmount.amount = num;
  return colorAmount;
}

int main(void) {
  FILE* fp;
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  fp = fopen("two_input.txt", "r");
  if (fp == NULL) {
    printf("Input file 'two_input.txt' was not found.\n");
    exit(EXIT_FAILURE);
  }
  int sum = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    int numParts = 0;
    char** colon = splitStr(line, ":", &numParts);
    int gameNumber = atoi(&colon[0][5]);
    char** semicolon = splitStr(colon[1], ";", &numParts);
    int minRed = 0;
    int minGreen = 0;
    int minBlue = 0;
    for (int i = 0; i < numParts; i++) {
      int commaParts = 0;
      char** comma = splitStr(semicolon[i], ",", &commaParts);
      for (int j = 0; j < commaParts; j++) {
        struct ColorAmount colorAmount = getColorAmount(comma[j]);
        switch (colorAmount.color) {
          case RED:
            if (colorAmount.amount > minRed) {
              minRed = colorAmount.amount;
            }
            break;
          case GREEN:
            if (colorAmount.amount > minGreen) {
              minGreen = colorAmount.amount;
            }
            break;
          case BLUE:
            if (colorAmount.amount > minBlue) {
              minBlue = colorAmount.amount;
            }
            break;
        }
      }
    }
    printf("minRed: %d\n", minRed);
    printf("minGreen: %d\n", minGreen);
    printf("minBlue: %d\n", minBlue);
    sum += (minRed * minGreen * minBlue);
  }
  printf("%d\n", sum);
  exit(EXIT_SUCCESS);
}

