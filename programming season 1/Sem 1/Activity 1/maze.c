#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// dela Torre, Nicholas Noly

void gotoxy(int x,int y)
{
	HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD row;
	row.X = x;
	row.Y = y;
	SetConsoleCursorPosition(col, row);
}

int main()
{ 	//caritativo-lingon
	int x = 0, y = 0, s = 20;

	// 1
	for(y = 2; y <= 24; y++)
	{
		gotoxy(2, y);
		putchar('*');
		Sleep(s);
	}

	// 2
	for (x = 2; x <= 78; x++)
	{
		gotoxy(x, 24);
		putchar('*');
		Sleep(s);
	}

	// 3
	for (y = 24; y >= 2; y--)
	{
		gotoxy(78, y);
		putchar('*');
		Sleep(s);
	}

	// 4
	for(x = 78; x >= 5; x--)
	{
		gotoxy(x, 2);
		putchar('*');
		Sleep(s);
	}

	// 5
	for(y = 2; y <= 22; y++)
	{
		gotoxy(5, y);
		putchar('*');
		Sleep(s);
	}

	// 6
	for (x = 5; x <= 74; x++)
	{
		gotoxy(x, 22);
		putchar('*');
		Sleep(s);
	}

	// 7
	for (y = 22; y >= 4; y--)
	{
		gotoxy(74, y);
		putchar('*');
		Sleep(s);
	}

	// 8
	for(x = 74; x >= 8; x--)
	{
		gotoxy(x, 4);
		putchar('*');
		Sleep(s);
	}

	// 9
	for(y = 4; y <= 20; y++)
	{
		gotoxy(8, y);
		putchar('*');
		Sleep(s);
	}

	// 10
	for (x = 8; x <= 70; x++)
	{
		gotoxy(x, 20);
		putchar('*');
		Sleep(s);
	}

	// 11
	for (y = 20; y >= 7; y--)
	{
		gotoxy(70, y);
		putchar('*');
		Sleep(s);
	}

	// 12
	for(x = 70; x >= 11; x--)
	{
		gotoxy(x, 6);
		putchar('*');
		Sleep(s);
	}

    // 13
	for(y = 6; y <= 18; y++)
	{
		gotoxy(11, y);
		putchar('*');
		Sleep(s);
	}

	// 14
	for (x = 11; x <= 67; x++)
	{
		gotoxy(x, 18);
		putchar('*');
		Sleep(s);
	}

	// 15
	for (y = 18; y >= 8; y--)
	{
		gotoxy(67, y);
		putchar('*');
		Sleep(s);
	}

	// 16
	for(x = 67; x >= 14; x--)
	{
		gotoxy(x, 8);
		putchar('*');
		Sleep(s);
	}

	// 17
	for(y = 8; y <= 16; y++)
	{
		gotoxy(14, y);
		putchar('*');
		Sleep(s);
	}

	// 18
	for (x = 14; x <= 64; x++)
	{
		gotoxy(x, 16);
		putchar('*');
		Sleep(s);
	}

	// 19
	for (y = 16; y >= 10; y--)
	{
		gotoxy(64, y);
		putchar('*');
		Sleep(s);
	}

	// 20
	for(x = 64; x >= 17; x--)
	{
		gotoxy(x, 10);
		putchar('*');
		Sleep(s);
	}

	// 21
	for(y = 10; y <= 14; y++)
	{
		gotoxy(17, y);
		putchar('*');
		Sleep(s);
	}

	// 22
	for (x = 17; x <= 61; x++)
	{
		gotoxy(x, 14);
		putchar('*');
		Sleep(s);
	}

	// 23
	for (y = 14; y >= 12; y--)
	{
		gotoxy(61, y);
		putchar('*');
		Sleep(s);
	}

	// 24
	for(x = 61; x >= 20; x--)
	{
		gotoxy(x, 12);
		putchar('*');
		Sleep(s);
	}

	Sleep(50);
	gotoxy(0, 26);
	printf("Maze done");

	Sleep(100);
	gotoxy(0, 27);
	printf("Press any key to exit..");

	getch();
}
