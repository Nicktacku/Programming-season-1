#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void gotoxy(int x, int y)
{
    HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD row;
    row.X = x;
    row.Y = y;
    SetConsoleCursorPosition(col, row);
}

void box(int col1, int row1, int col2, int row2, char ch)
{
    int x;
    for (x = col1; x <= col2; x++)
    {
        gotoxy(x, row1);
        putchar(ch);
        gotoxy(x, row2);
        putchar(ch);
    }
    for (x = row1; x <= row2; x++)
    {
        gotoxy(col1, x);
        putchar(ch);
        gotoxy(col2, x);
        putchar(ch);
    }
}

void fillscreen(int col1, int row1, int col2, int row2, char ch)
{
    int col, row;

    for (col = col1; col <= col2; col++)
    {
        for (row = row1; row <= row2; row++)
        {
            gotoxy(col, row);
            putchar(ch);
        }
    }
}

void clearportion(int col1, int row1, int col2, int row2)
{
    int col, row;

    for (col = col1; col <= col2; col++)
    {
        for (row = row1; row <= row2; row++)
        {
            gotoxy(col, row);
            putchar(' ');
        }
    }
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

void hline(int col1, int row1, int col2, char ch)
{
    int x;
    for (x = col1; x <= col2; x++)
    {
        gotoxy(x, row1);
        putchar(ch);
    }
}

void vline(int col1, int row1, int row2, char ch)
{
    int x;
    for (x = row1; x <= row2; x++)
    {
        gotoxy(col1, x);
        putchar(ch);
    }
}

void printxy(int col, int row, char ch[])
{
    gotoxy(col, row);
    puts(ch);
}

void center(int row, char ch[])
{
    int col = (80 - strlen(ch)) / 2 + 1;
    gotoxy(col, row);
    puts(ch);
}

main()
{
    // Nicholas Noly dela torre

    // ears
    line2(6, 5, 10, 10);
    line2(43, 5, 47, 10);
    fillscreen(7, 6, 9, 9, 178);
    fillscreen(44, 6, 46, 9, 178);

    // neck
    fillscreen(18, 15, 35, 17, 178);

    // body
    line1(3, 17, 50, 24);

    // arm
    vline(9, 20, 23, 179);
    vline(44, 20, 23, 179);
    vline(9, 24, 24, 217);
    vline(44, 24, 24, 192);

    // head
    line2(10, 2, 43, 15);

    // eyes
    box(12, 6, 41, 9, 178);

    // mouth
    line1(17, 11, 36, 13);

    line1(15, 12, 17, 14);
    vline(17, 12, 12, 217);
    vline(17, 13, 13, 218);

    line1(36, 12, 38, 14);
    vline(36, 12, 12, 192);
    vline(36, 13, 13, 191);

    // accessory
    line1(32, 19, 41, 21);
    printxy(34, 20, "Robert");

    getch();
}