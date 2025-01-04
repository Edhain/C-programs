#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcome();
int get_number();


int main()
{
    int number = 0, temp = 0, try = 0;
    srand(time(NULL));

    welcome();
    number = rand()%101;
    //printf("%d", number);
    
    do
    {
        temp = get_number();

        if (number > temp)
        {
            printf("Sorry. Guess a LARGER number than %d\n", temp);
            printf("-----------------------------------------------------------------\n");
        }
        else if ( number < temp)
        {
            printf("Sorry. Guess a SMALLER number than %d\n", temp);
            printf("-----------------------------------------------------------------\n");
        }
        else
        {
            printf("Congratulations. You got it in %d try!!\n", try + 1);
        }
        try += 1;
    } while (temp != number);

    printf("Thankyou for playing\n");
    printf("Developed By: Edhain");

    return 0;
}

void welcome()
{
    printf("Welcome to the Game of Guessing\nYou have to guess a number between 0 to 100\n");
}

int get_number()
{
    int temp;

    printf("Enter a number between 0 and 100\n");
    printf("The number you entered: ");
    scanf("%d", &temp);

    return temp;
}