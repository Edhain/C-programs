#include <stdio.h>

int main() {
    int n;
    int i;
    int m;

    printf("Enter number to check if it is prime or not:\n");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Number is NOT prime\n");
        return 0;
    }

    m = n / 2;
    for (i = 2; i <= m; i++) {
        if (n % i == 0) {
            printf("Number is NOT prime\n");
            return 0;
        }
    }
    printf("Number is prime\n");
    return 0;
}
