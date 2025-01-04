#include<stdio.h>
#include <stdlib.h>

int fib(int n){
    if(n<=1){
            return n;
    }
    int *F = (int *)malloc((n + 1) * sizeof(int));
    if (F == NULL) {
        printf("Memory allocation failed\n");
        return -1; // Return -1 to indicate failure
    }
    F[0]=0;
    F[1]=1;
    for(int i=2; i<=n; i++){
        F[i]= F[i-2] + F[i-1];
    }
    int result = F[n];

    // Free the allocated memory
    free(F);

    return result;
}

int main() {
    int n;
    printf("Enter the position of the Fibonacci number to be printed: \n");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    int fibNumber = fib(n);
    if (fibNumber != -1) {
        printf("Fibonacci number at position %d is: %d\n", n, fibNumber);
    }

    return 0;
}