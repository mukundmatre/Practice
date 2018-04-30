#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* max_consec_char(const char* in_string);

char* max_consec_char(const char* in_string) {
        static char *desired_char = NULL;
        desired_char = (char*) malloc(sizeof(char));
        int current_count = 1;
        int max_count = 1;
        for (size_t i = 0; i < strlen(in_string); i++) {
                for (size_t j = (i+1); j < strlen(in_string); j++) {
                        if(in_string[i] == in_string[j]) {
                                current_count++;
                                i = j;
                        }
                }
                if (current_count > max_count) {
                        max_count = current_count;
                        *desired_char = in_string[i];
                }
                current_count = 1;
        }
        return desired_char;
}

int main(void) {
        const char *string = "uaaaooooaaalllllllllllbbbbbbb";
        char *ptr = max_consec_char(string);
        printf("Maximum consecutive character in string:%c\n", *ptr);
        return 0;
}
