#include <stdio.h>
#include <stdlib.h>

int string_len(char* string);

int string_len(char* string) {
        static int len = 0;
        if (string==NULL) {
          printf("Not a string\n");
          return -1;
        }
        if (*string == '\0') {
                return len;
        }
        len++;
        string++;
        string_len(string);
        return len;
}

int main(void) {
        char str[] = "Hello";
        char* string = NULL;
        printf("%d\n", string_len(string));
        return 0;
}
