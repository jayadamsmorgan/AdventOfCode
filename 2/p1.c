#include "string.h"
#include "../lib/file.h"

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
  open_file();
  int sum = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    int numParts = 0;
    char** colon = splitStr(line, ":", &numParts);
    int gameNumber = atoi(&colon[0][5]);
    char** semicolon = splitStr(colon[1], ";", &numParts);
    int possible = 1;
    for (int i = 0; i < numParts; i++) {
      int commaParts = 0;
      char** comma = splitStr(semicolon[i], ",", &commaParts);
      for (int j = 0; j < commaParts; j++) {
        struct ColorAmount colorAmount = getColorAmount(comma[j]);
        switch (colorAmount.color) {
          case RED:
            if (colorAmount.amount > RED_MAX) {
              possible = 0;
            }
            break;
          case GREEN:
            if (colorAmount.amount > GREEN_MAX) {
              possible = 0;
            }
            break;
          case BLUE:
            if (colorAmount.amount > BLUE_MAX) {
              possible = 0;
            }
            break;
        }
      }
    }
    if (possible != 0) {
      sum += gameNumber;
    }
  }
  printf("%d\n", sum);
  exit(EXIT_SUCCESS);
}

