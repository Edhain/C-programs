#include <stdio.h>

int main() {
    int n1 = 0;
    int n2 = 1;
    int n3;
    int i;
    int number;

    printf("Enter the number of Fibonacci series to be printed: \n");
    scanf("%d", &number);

    if (number <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    } else if (number == 1) {
        printf("%d\n", n1);
        return 0;
    }

    printf("%d\n%d\n", n1, n2);

    for(i = 2; i < number; i++) {
        n3 = n2 + n1;
        printf("%d\n", n3);
        n1 = n2;
        n2 = n3;
    }

    return 0;
}
