#include "../lib/file.h"
#include <string.h>

const char* symbols = "~!@#$%&*()_+-=[]{}'\";:,><?/";

int main(void) {
  open_file();
  int sum = 0;
  char read_lines[140][141];
  int i = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    strcpy(read_lines[i], line);
    i++;
  }
  for (int j = 0; j < 140; j++) {
    for (int k = 0; k < 140; k++) {
      int num = atoi(&read_lines[j][k]);
    }
  }
  printf("%d", sum);
  exit(EXIT_SUCCESS);
}
