#include <stdio.h>

int main() {
    int n;
    int r;
    int sum = 0;
    int temp;

    printf("Enter number to check if it is a palindrome:\n");
    scanf("%d", &n);

    temp = n;
    while (n > 0) {
        r = n % 10;
        sum = (sum * 10) + r;
        n = n / 10;
    }

    if (temp == sum) {
        printf("Number is a palindrome\n");
    } else {
        printf("Number is NOT a palindrome\n");
    }

    return 0;
}
