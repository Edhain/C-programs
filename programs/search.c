#include<cs50>
#include<stdio.h>
// #include<string.h>

int main (void){
    int numbers[]={1, 2, 3, 4, 5, 6, 7};

    int n = get_int("Number: ");
    for (int i=0; i<7; i++){
        if (numbers[i] == n){
            printf("found\n");
            return 0;
        }
    }
    printf("not found\n");
    return 1;
}