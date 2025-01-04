#include<stdio.h>

int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-2) + fib(n-1);
}

int main() {
    int n;
    printf("Enter the position of the Fibonacci number to be printed: \n");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    printf("Fibonacci number at position %d is: %d\n", n, fib(n));

    return 0;
}