#include <string.h>
#include "../lib/file.h"

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

int main(void) {
  open_file();
  int sum = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    int num = 0;
    for (int i = 0; i < len; i++) {
      num = charToInt(line[i]) * 10;
      if (num != 0) {
        break;
      }
    }
    for (int i = strlen(line); i >= 0; i--) {
      int num2 = charToInt(line[i]);
      if (num2 != 0) {
        num += num2;
        break;
      }
    }
    sum += num;
  }
  printf("%d\n", sum);
  fclose(fp);
  if (line) free(line);
  exit(EXIT_SUCCESS);
}

