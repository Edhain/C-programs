#include <stdio.h>
#include <string.h>

int main(void) {
    char s[100];
    char t[100];

    printf("s: ");
    scanf("%99s", s);  // Read a string of up to 99 characters
    printf("t: ");
    scanf("%99s", t);  // Read a string of up to 99 characters

    if (strcmp(s, t) == 0) {
        printf("Same\n");
    } else {
        printf("Different\n");
    }
    return 0;
}
