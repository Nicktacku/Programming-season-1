#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int highest(int numbers[6], int lenght);
int lowest(int numbers[6], int lenght);

void gotoxy(int x, int y)
{
    HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD row;
    row.X = x;
    row.Y = y;
    SetConsoleCursorPosition(col, row);
}

void line1(int col1, int row1, int col2, int row2)
{
    int x;
    for (x = col1; x <= col2; x++)
    {
        gotoxy(x, row1);
        putchar(196);
        gotoxy(x, row2);
        putchar(196);
    }
    for (x = row1; x <= row2; x++)
    {
        gotoxy(col1, x);
        putchar(179);
        gotoxy(col2, x);
        putchar(179);
    }
    gotoxy(col1, row1);
    putchar(218);
    gotoxy(col2, row1);
    putchar(191);
    gotoxy(col1, row2);
    putchar(192);
    gotoxy(col2, row2);
    putchar(217);
}

void line2(int col1, int row1, int col2, int row2)
{
    int x;
    for (x = col1; x <= col2; x++)
    {
        gotoxy(x, row1);
        putchar(205);
        gotoxy(x, row2);
        putchar(205);
    }
    for (x = row1; x <= row2; x++)
    {
        gotoxy(col1, x);
        putchar(186);
        gotoxy(col2, x);
        putchar(186);
    }
    gotoxy(col1, row1);
    putchar(201);
    gotoxy(col2, row1);
    putchar(187);
    gotoxy(col1, row2);
    putchar(200);
    gotoxy(col2, row2);
    putchar(188);
}

void printxy(int col, int row, char ch[])
{
    gotoxy(col, row);
    puts(ch);
}

int main()
{
    // Nicholas Noly dela Torre
    int numbers[6];
    // divides the size of the array to one of its element
    // to measure how many elements is in the array
    int lenght = sizeof(numbers) / sizeof(numbers[0]);
    int i, w, toQuit;
    char decision;

    while (toQuit == 0)
    {
        // resets the screen for when another input is given
        system("cls");
        // process for the inputting of the elements of the array
        for (i = 0; i < 5; i++)
        {
            printf("Enter the number [%d]: ", i + 1);
            scanf("%d", &numbers[i]);
        }
        system("cls");

        // builds the body of the program
        line1(3, 3, 50, 18);
        line2(3, 3, 50, 6);
        printxy(5, 4.5, "Highest and Lowest Number Printer v1.0");

        // for the array
        printxy(5, 9, "Array");
        line2(13, 8, 45, 10);
        for (i = 0, w = 15; i < lenght - 1; i++, w += 3)
        {
            // print the elements of the array
            gotoxy(w, 9);
            printf("%d ", numbers[i]);
        }

        // for the highest element
        printxy(5, 12, "Highest");
        line2(13, 11, 45, 13);

        gotoxy(15, 12);
        printf("%d", highest(numbers, lenght));

        // for the lowest element
        printxy(5, 15, "Lowest");
        line2(13, 14, 45, 16);

        gotoxy(15, 15);
        printf("%d", lowest(numbers, lenght));

        // prompts the decision of the user
        gotoxy(0, 20);
        printf("Do you want to continue? (Y) or (N): ");
        scanf(" %c", &decision);

        // if the decision is no then the program will quit
        if (decision == 'n' || decision == 'N')
        {
            toQuit = 1;
        }
    }
    return 0;
}

int highest(int numbers[6], int lenght)
{
    int i, max = numbers[0];
    for (i = 0; i < lenght - 1; i++)
    {
        // loops through the array, if the number is bigger
        // than the placeholder then the bigger value will be
        // saved
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    return max;
}

int lowest(int numbers[6], int lenght)
{
    int i, min = numbers[0];
    for (i = 0; i < lenght - 1; i++)
    {
        // loops through the array, if the number is smaller
        // than the placeholder then the smaller value will be
        // saved
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }
    return min;
}