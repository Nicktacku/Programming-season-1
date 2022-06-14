#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void printStartScreen();
void option1();
void option2();

int main()
{
    char inp;
    int ctr = 0;
    option1();

    while (inp != 'e')
    {
        inp = getch();
        if (ctr == 1)
        {
            option1();
            if (inp == 's')
            {
                ctr++;
                ctr %= 2;
            }
            else if (inp == 'w')
            {
                ctr -= 2;
                ctr %= 2;
                ctr += 1;
            }
        }
        else if (ctr == 0)
        {
            option2();
            if (inp == 's')
            {
                ctr++;
                ctr %= 2;
            }
            else if (inp == 'w')
            {
                ctr -= 2;
                ctr %= 2;
                ctr += 1;
            }
        }
    }
    return 0;
}

void printStartScreen()
{
    printf("Welcome to game hub\n");
    printf("What do you want to do?:");
}

void option1()
{
    system("cls");
    printStartScreen();
    printf("\n\nLog In <--");
    printf("\nSign Up");
    printf("\n\n");
}

void option2()
{
    system("cls");
    printStartScreen();
    printf("\n\nLog In");
    printf("\nSign Up <--");
    printf("\n\n");
}