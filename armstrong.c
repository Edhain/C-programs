#include<stdio.h>

int main(){
    int n;
    int r;
    int sum = 0;
    int temp;
    printf("Enter a number\n");
    scanf("%d", &n);
    
    temp = n;
    while(n>0){
        r = n%10;
        sum = sum + (r*r*r);
        n = n/10;
    }
    if (temp==sum){
        printf("Number is a Armstrong number\n");
    } else {
        printf("Number is NOT a Armstrong number\n");
    }
}