#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void gotoxy(int x, int y);
void line2(int col1, int row1, int col2, int row2);
void hline(int col1, int row1, int col2, char ch);
void printxy(int col, int row, char ch[]);
void clearportion(int col1, int row1, int col2, int row2);
void menuDisplay();
void optionA();
void optionB();
void optionC();
void oup(int *ctr);
const char *vehicle(char vhc);
const char *destination(char dest);
double discount(char disc);
void inp(int *ctr, double *prc, char *cp);
int notInChoices(char choice);

struct Vacation
{
    char vehicle;
    char destination;
    char discount;
    double price;
    double total;
} plan[10];

// made global so it can be easily accessed everywhere
struct Vacation plan[10];

int main()
{
    int menu = 1, end = 0, counter = 0;
    double price;
    char menuChoice, currentPlace;

    // initial display
    menuDisplay();
    optionA();

    // main program process
    // will run until exited
    while (end == 0)
    {
        // allows the user to press a key and make it as an input
        menuChoice = getch();

        // gives the illusion of animation
        if (menuChoice == 'w')
        {
            menu -= 1;
            if (menu < 1)
            {
                menu = 3;
            }
        }
        else if (menuChoice == 's')
        {
            menu += 1;
            if (menu > 3)
            {
                menu = 1;
            }
        }
        // enters the option which is based on the value of menu
        // and based on that value will do the function
        else if (menuChoice == 'e')
        {
            if (menu == 1)
            {
                inp(&counter, &price, &currentPlace);

                // allows the output to stay till continued
                gotoxy(0, 21);
                printf("\n\nPress any key to continue..");
                getch();

                // gives display to make it goes back to
                // starting menu
                menuDisplay();
            }
            else if (menu == 2)
            {
                oup(&counter);

                // allows the output to stay till continued
                gotoxy(0, 21);
                printf("\n\nPress any key to continue..");
                getch();

                // gives display to make it goes back to
                // starting menu
                menuDisplay();
            }
            else if (menu == 3)
            {
                // exits the program
                end = 1;
            }
        }

        // moves the arrow
        if (menu == 1)
        {
            optionA();
        }
        else if (menu == 2)
        {
            optionB();
        }
        else if (menu == 3)
        {
            optionC();
        }
    }

    // direct the ending line so it wont destroy the display
    gotoxy(0, 21);
    return 0;
}

void optionA()
{
    // erases the old arrows
    clearportion(11, 16, 14, 16);
    clearportion(9, 17, 12, 17);

    // puts the arrow in place
    printxy(10, 15, "<--");
    gotoxy(4, 15);
}

void optionB()
{
    // erases the old arrows
    clearportion(10, 15, 13, 15);
    clearportion(9, 17, 12, 17);

    // puts the arrow in place
    printxy(11, 16, "<--");
    gotoxy(4, 16);
}

void optionC()
{
    // erases the old arrows
    clearportion(11, 16, 14, 16);
    clearportion(10, 15, 13, 15);

    // puts the arrow in place
    printxy(9, 17, "<--");
    gotoxy(4, 17);
}
void inp(int *ctr, double *prc, char *cp)
{
    double distance = 0, fare = 0, total = 0;
    int i;

    // display of the input function
    system("cls");
    line2(2, 2, 80, 6);
    line2(2, 2, 80, 19);
    printxy(4, 4, "Journey Price Calculator v1");

    // makes sure the input is in the option
    while (notInChoices(plan[*ctr].vehicle) != 0)
    {
        clearportion(4, 8, 79, 14);
        printxy(4, 8, "Vehicle:");
        printxy(4, 9, "a) Grab");
        printxy(4, 10, "b) Angkas");
        printxy(4, 11, "c) Jeep");
        printxy(4, 12, "d) Bus");
        printxy(4, 14, "Enter letter of the vehicle: ");
        gotoxy(33, 14);

        // put the input into the struct array
        scanf(" %c", &plan[*ctr].vehicle);

        // notify the user of the error
        if (notInChoices(plan[*ctr].vehicle) != 0)
        {
            printxy(4, 16, "The choice is not in the option, try again");
        }
        // erase the warning if the input is now in the option
        else
        {
            clearportion(4, 16, 50, 16);
        }
    }

    // makes sure the input is in the option
    while (notInChoices(plan[*ctr].destination) != 0)
    {
        clearportion(4, 8, 79, 14);
        printxy(4, 8, "Destination:");
        printxy(4, 9, "a) Antipolo");
        printxy(4, 10, "b) Morong");
        printxy(4, 11, "c) Teresa");
        printxy(4, 12, "d) Tanay");
        printxy(4, 14, "Enter letter of the destination: ");
        gotoxy(37, 14);

        // put the input into the struct array
        scanf(" %c", &plan[*ctr].destination);

        // notify the user of the error
        if (notInChoices(plan[*ctr].destination) != 0)
        {
            printxy(4, 16, "The choice is not in the option, try again");
        }
        // erase the warning if the input is now in the option
        else
        {
            clearportion(4, 16, 50, 16);
        }
    }

    // makes sure the input is in the option
    while (notInChoices(plan[*ctr].discount) != 0)
    {
        clearportion(4, 8, 79, 14);
        printxy(4, 8, "Discount:");
        printxy(4, 9, "a) Student");
        printxy(4, 10, "b) Pwd");
        printxy(4, 11, "c) Senior Citizen");
        printxy(4, 12, "d) None");
        printxy(4, 14, "Enter letter of the discount: ");
        gotoxy(34, 14);

        // put the input into the struct array
        scanf(" %c", &plan[*ctr].discount);

        // notify the user of the error
        if (notInChoices(plan[*ctr].discount) != 0)
        {
            printxy(4, 16, "The choice is not in the option, try again");
        }
        // erase the warning if the input is now in the option
        else
        {
            clearportion(4, 16, 50, 16);
        }
    }

    // designate the new place, used to calculate the distance
    char np = plan[*ctr].destination;

    // gives the value of the distance based from the current place
    // and the new place
    if (*cp == 'a')
    {
        if (np == 'b')
        {
            distance = 28.6;
        }
        else if (np == 'c')
        {
            distance = 30.6;
        }
        else if (np == 'd')
        {
            distance = 39.5;
        }
    }
    else if (*cp == 'b')
    {
        if (np == 'a')
        {
            distance = 25.0;
        }
        else if (np == 'c')
        {
            distance = 9.2;
        }
        else if (np == 'd')
        {
            distance = 31.0;
        }
    }
    else if (*cp == 'c')
    {
        if (np == 'a')
        {
            distance = 28.6;
        }
        else if (np == 'b')
        {
            distance = 13.5;
        }
        else if (np == 'd')
        {
            distance = 25.2;
        }
    }
    else if (*cp == 'd')
    {
        if (np == 'a')
        {
            distance = 43.7;
        }
        else if (np == 'b')
        {
            distance = 32.7;
        }
        else if (np == 'c')
        {
            distance = 38.4;
        }
    }

    // calculates the fare based on the chosen vehicle
    switch (plan[*ctr].vehicle)
    {
    case 'a':
        fare = 26.64;
        break;
    case 'b':
        fare = 25.0;
        break;
    case 'c':
        fare = 10.0;
        break;
    case 'd':
        fare = 15.25;
        break;
    }

    // calculates the price based on the fare, distance, and discount
    double totalPrice = (fare * distance);
    double discountPrice = discount(plan[*ctr].discount) * totalPrice;
    plan[*ctr].price = totalPrice - discountPrice;

    // iteration and assigning for the next call of input
    *ctr += 1;
    *cp = np;

    // calculates the price based on the collected price in the struct array
    for (i = 0; i < *ctr; i++)
    {
        total += plan[i].price;
    }
    plan[*ctr - 1].total = total;

    // called to show the table
    oup(&*ctr);
}

void oup(int *ctr)
{
    int i, y = 8;
    double total = 0;

    // initializes the display for the output
    system("cls");
    line2(2, 2, 80, 6);
    line2(2, 2, 80, 19);
    printxy(4, 4, "Journey Price Calculator v1");

    // makes sure the content of ctr cant exceed 9 and
    // notifies the user that they cant add anymore
    if (*ctr >= 10)
    {
        printxy(8, 18, "Cant add more");
        *ctr = 9;
    }

    if (*ctr < 10)
    {
        // initialize the titles of the display
        printxy(8, 7, "Journey #");
        printxy(22, 7, "Vehicle");
        printxy(32, 7, "Destination");
        printxy(46, 7, "Discount");
        printxy(58, 7, "Price");
        printxy(68, 7, "Total");

        // display the collected inputs
        for (i = 0; i < *ctr; i++)
        {
            gotoxy(10, y);
            printf("%d", i + 1);
            gotoxy(23, y);
            printf("%s\t", vehicle(plan[i].vehicle));
            gotoxy(33, y);
            printf("%s\t", destination(plan[i].destination));
            gotoxy(48, y);
            printf("%.2lf\t", discount(plan[i].discount));
            gotoxy(58, y);
            printf("%.2lf\t", plan[i].price);
            gotoxy(68, y);
            printf("%.2lf", plan[i].total);

            // the value iterates to place the next display in the next line
            y += 1;
        }
    }
}

// returns string for display in vehicle
const char *vehicle(char vhc)
{
    switch (vhc)
    {
    case 'a':
        return "grab";
    case 'b':
        return "angkas";
    case 'c':
        return "jeep";
    case 'd':
        return "bus";
    }
}

// return the destination for display
const char *destination(char dest)
{
    switch (dest)
    {
    case 'a':
        return "antipolo";
    case 'b':
        return "morong";
    case 'c':
        return "teresa";
    case 'd':
        return "tanay";
    }
}

// returns the discount to be useed for calculation and\
// display
double discount(char disc)
{
    switch (disc)
    {
    case 'a':
        return .05;
    case 'b':
        return .1;
    case 'c':
        return .15;
    case 'd':
        return 0;
    }
}

// function of displays
void gotoxy(int x, int y)
{
    HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD row;
    row.X = x;
    row.Y = y;
    SetConsoleCursorPosition(col, row);
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

void printxy(int col, int row, char ch[])
{
    gotoxy(col, row);
    puts(ch);
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

// for the menu display
void menuDisplay()
{
    system("cls");
    line2(2, 2, 80, 6);
    line2(2, 2, 80, 19);
    printxy(4, 4, "Journey Price Calculator v1");

    printxy(4, 8, "This is a journey helper, it calculate the amount needed for the journey");
    printxy(4, 9, "you can enter up to 9 destination plans");
    printxy(4, 13, "use \"w\" and \"s\" to choose an option and \"e\" to select it:");
    printxy(4, 15, "Input");
    printxy(4, 16, "Output");
    printxy(4, 17, "Exit");
}

// check if the choice is within the option
int notInChoices(char choice)
{
    switch (choice)
    {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
        return 0;
        break;
    default:
        return 1;
    }
}