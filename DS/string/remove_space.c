#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_spaces(char *str);

void remove_spaces(char *str) {
  int count = 0;
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i]!=' ') {
      str[count] = str[i];
      count++;
    }
  }
  str[count] = '\0';
}

int main(int argc, char const *argv[]) {
  char *string = (char*) malloc(19*sizeof(char));
  strcpy(string, "Andro meda Str ain");
  remove_spaces(string);
  printf("%s\n", string);
  return 0;
}
