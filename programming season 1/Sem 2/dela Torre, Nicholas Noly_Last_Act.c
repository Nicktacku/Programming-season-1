#include <myfunctions.h>

void create();
void order();
void display();
void search();
void back_up();
int total();
int total_search(char *date);
void frame();
void frame_erase();

// Nicholas Noly C. dela Torre
int main()
{
    int choice = 0;
    char press;
    char end = 'n';

    frame();

    while (end != 'y')
    {
        if (choice == 0)
        {
            clearportion(9, 19, 12, 19);
            clearportion(18, 15, 22, 15);
            gotoxy(22, 14);
            putchar(174);
        }
        else if (choice == 1)
        {
            clearportion(22, 14, 25, 14);
            clearportion(22, 16, 25, 16);
            gotoxy(18, 15);
            putchar(174);
        }
        else if (choice == 2)
        {
            clearportion(18, 15, 22, 15);
            clearportion(11, 17, 14, 17);
            gotoxy(22, 16);
            putchar(174);
        }
        else if (choice == 3)
        {
            clearportion(22, 16, 25, 16);
            clearportion(12, 18, 15, 18);
            gotoxy(11, 17);
            putchar(174);
        }
        else if (choice == 4)
        {
            clearportion(11, 17, 14, 17);
            clearportion(9, 19, 12, 19);
            gotoxy(12, 18);
            putchar(174);
        }
        else if (choice == 5)
        {
            clearportion(12, 18, 15, 18);
            clearportion(22, 14, 25, 14);
            gotoxy(9, 19);
            putchar(174);
        }

        printxy(4, 8, "This is a recorder for the orders of your aice branch");
        printxy(4, 9, "it creates a file under the name \"Records\"");
        printxy(4, 11, "(use \"w\" and \"s\" to navigate the menu and \"e\" to choose it)");

        printxy(4, 13, "Menu:");
        printxy(4, 14, "Create new record");
        printxy(4, 15, "Add new order");
        printxy(4, 16, "Display all order");
        printxy(4, 17, "Search");
        printxy(4, 18, "Back Up");
        printxy(4, 19, "Exit");
        gotoxy(4, 22);
        press = tolower(getch());

        if (press == 'w')
        {
            choice--;
            if (choice == -1)
            {
                choice = 5;
            }
        }
        else if (press == 's')
        {
            choice++;
            if (choice == 6)
            {
                choice = 0;
            }
        }
        else if (press == 'e')
        {
            frame_erase();
            if (choice == 0)
            {
                create();
            }
            else if (choice == 1)
            {
                order();
            }
            else if (choice == 2)
            {
                display();
            }
            else if (choice == 3)
            {
                search();
            }
            else if (choice == 4)
            {
                back_up();
            }
            else if (choice == 5)
            {
                center(15, "Thank you for using the program <3");
                end = 'y';
            }
        }
        else
        {
            gotoxy(4, 22);
            printf("(press \"w\" and \"s\" to navigate the menu and \"e\" to choose it)");
        }
    }
    gotoxy(0, 26);
    return 0;
}

void create()
{
    char pressed;
    int choice = 1;

    while (pressed != 'e')
    {
        if (choice == 1)
        {
            gotoxy(40, 16);
            putchar(174);
            clearportion(44, 16, 44, 16);
        }
        else if (choice == 2)
        {
            gotoxy(44, 16);
            putchar(174);
            clearportion(40, 16, 40, 16);
        }
        center(11, "Warning!");
        center(12, "It will overwrite the existing record if there is one.");
        center(13, "(use \"a\" and \"d\" to choose answer and \"e\" to enter");
        center(15, "Continue?");
        printxy(37, 16, "Yes");
        printxy(42, 16, "No");
        pressed = tolower(getch());

        if (pressed == 'a')
        {
            choice--;
            if (choice < 1)
            {
                choice = 2;
            }
        }
        else if (pressed == 'd')
        {
            choice++;
            if (choice > 2)
            {
                choice = 1;
            }
        }
    }

    if (choice == 1)
    {
        FILE *ic_record = fopen("Records.txt", "w");
        frame_erase();
        gotoxy(4, 22);
        printf("File has been created");
        fclose(ic_record);
    }

    else if (choice == 2)
    {
        frame_erase();
    }
}

void order()
{
    FILE *ic_record = fopen("Records.txt", "a");
    int amount;
    double price, rprice, total, profit;
    char date[11], product[40];
    int quit;

    printxy(10, 15, "Enter the date of the order (mm/dd/yyyy):");
    gotoxy(53, 15);
    scanf("%s", date);
    frame();

    fprintf(ic_record, "SOR");
    fprintf(ic_record, "\n%s", date);

    while (quit != 2)
    {
        int choice = 1, column = 1;
        char pressed = ' ';

        frame_erase();

        printxy(4, 8, "Choose the flavor that will be ordered:");

        printxy(4, 10, "1) Milk Stick");
        printxy(30, 10, "2) Watermelon");
        printxy(57, 10, "3) Chocolate");

        printxy(4, 12, "4) Milk Melon");
        printxy(30, 12, "5) Coffee Crispy");
        printxy(57, 12, "6) Sweetcorn");

        printxy(4, 14, "7) Chocolate Sundae");
        printxy(30, 14, "8) Chocolate Crispy");
        printxy(57, 14, "9) Strawberry Cone");

        printxy(4, 16, "10) Choco Melt");
        printxy(30, 16, "11) Alpukat Strawberry");
        printxy(57, 16, "12) Pineapple");

        printxy(4, 18, "13) Strawberry Crispy");
        printxy(30, 18, "14) Mango Slush");
        printxy(57, 18, "15) Vanilla Mochi");

        printxy(4, 20, "16) Mochi Chocolate");
        printxy(30, 20, "17) Choco Vanilla 2in1");
        printxy(57, 20, "18) Choco Cup");

        printxy(4, 22, "19) Ice Pop");
        printxy(30, 22, "20) Strawberry Sundae");
        printxy(57, 22, "21) Choco Cookies");

        printxy(4, 23, "(use \"a\", \"s\", \"w\", \"d\" to navigate and \"e\" to enter)");

        while (pressed != 'e')
        {
            if (pressed == 's')
            {
                choice += 3;
                column++;

                if (column > 7)
                {
                    column = 1;
                }

                if (choice == 22)
                {
                    choice = 1;
                }
                else if (choice == 23)
                {
                    choice = 2;
                }
                else if (choice == 24)
                {
                    choice = 3;
                }
            }
            else if (pressed == 'w')
            {
                choice -= 3;
                column--;

                if (column < 1)
                {
                    column = 7;
                }

                if (choice == -2)
                {
                    choice = 19;
                }
                else if (choice == -1)
                {
                    choice = 20;
                }
                else if (choice == 0)
                {
                    choice = 21;
                }
            }
            else if (pressed == 'd')
            {
                choice++;

                if (choice > 3 && column == 1)
                {
                    choice = 1;
                }
                else if (choice > 6 && column == 2)
                {
                    choice = 4;
                }
                else if (choice > 9 && column == 3)
                {
                    choice = 7;
                }
                else if (choice > 12 && column == 4)
                {
                    choice = 10;
                }
                else if (choice > 15 && column == 5)
                {
                    choice = 13;
                }
                else if (choice > 18 && column == 6)
                {
                    choice = 16;
                }
                else if (choice > 21 && column == 7)
                {
                    choice = 19;
                }
            }
            else if (pressed == 'a')
            {
                choice -= 1;

                if (choice < 1 && column == 1)
                {
                    choice = 3;
                }
                else if (choice < 4 && column == 2)
                {
                    choice = 6;
                }
                else if (choice < 7 && column == 3)
                {
                    choice = 9;
                }
                else if (choice < 10 && column == 4)
                {
                    choice = 12;
                }
                else if (choice < 13 && column == 5)
                {
                    choice = 15;
                }
                else if (choice < 16 && column == 6)
                {
                    choice = 18;
                }
                else if (choice < 19 && column == 7)
                {
                    choice = 21;
                }
            }

            if (choice == 1)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(26, 10);
                putchar(174);
            }
            else if (choice == 2)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(54, 10);
                putchar(174);
            }
            else if (choice == 3)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(78, 10);
                putchar(174);
            }
            else if (choice == 4)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(26, 12);
                putchar(174);
            }
            else if (choice == 5)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(54, 12);
                putchar(174);
            }
            else if (choice == 6)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(78, 12);
                putchar(174);
            }
            else if (choice == 7)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(26, 14);
                putchar(174);
            }
            else if (choice == 8)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(54, 14);
                putchar(174);
            }
            else if (choice == 9)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(78, 14);
                putchar(174);
            }
            else if (choice == 10)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(26, 16);
                putchar(174);
            }
            else if (choice == 11)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(54, 16);
                putchar(174);
            }
            else if (choice == 12)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(78, 16);
                putchar(174);
            }
            else if (choice == 13)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(26, 18);
                putchar(174);
            }
            else if (choice == 14)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(54, 18);
                putchar(174);
            }
            else if (choice == 15)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(78, 18);
                putchar(174);
            }
            else if (choice == 16)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(26, 20);
                putchar(174);
            }
            else if (choice == 17)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(54, 20);
                putchar(174);
            }
            else if (choice == 18)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(78, 20);
                putchar(174);
            }
            else if (choice == 19)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(26, 22);
                putchar(174);
            }
            else if (choice == 20)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(54, 22);
                putchar(174);
            }
            else if (choice == 21)
            {
                clearportion(26, 10, 27, 22);
                clearportion(54, 10, 54, 22);
                clearportion(78, 10, 79, 22);
                gotoxy(78, 22);
                putchar(174);
            }

            gotoxy(57, 23);

            pressed = tolower(getch());
        }

        if (choice == 1 || choice == 2 || choice == 3 || choice == 12)
        {
            rprice = 7.50;
        }
        else if (choice == 4)
        {
            rprice = 9.63;
        }
        else if (choice == 5)
        {
            rprice = 15.25;
        }
        else if (choice == 6)
        {
            rprice = 11.25;
        }
        else if (choice == 7 || choice == 18 || choice == 20)
        {
            rprice = 20;
        }
        else if (choice == 8 || choice == 13 || choice == 21)
        {
            rprice = 16.25;
        }
        else if (choice == 9 || choice == 10)
        {
            rprice = 17.50;
        }
        else if (choice == 11 || choice == 17)
        {
            rprice = 111.11;
        }
        else if (choice == 14)
        {
            rprice = 15;
        }
        else if (choice == 15 || choice == 16)
        {
            rprice = 10.63;
        }
        else if (choice == 19)
        {
            rprice = 12;
        }

        frame_erase();

        printxy(4, 14, "Enter the number of ice cream that will be ordered:");
        gotoxy(57, 14);
        scanf("%d", &amount);
        gotoxy(4, 15);
        printf("Enter the price you will sell the product (should be more than %.2lf):", rprice);
        gotoxy(76, 15);
        scanf("%lf", &price);
        frame();

        total = rprice * amount;
        profit = (price * amount) - total;
        fprintf(ic_record, "\n%d %.2lf %.2lf %d %.2lf %.2lf", choice, rprice, price, amount, total, profit);

        frame_erase();
        center(14, "Are you going to order another product?");
        printxy(30, 16, "Yes");
        printxy(50, 16, "No");

        char qpressed = ' ';
        quit = 1;
        while (qpressed != 'e')
        {
            if (quit == 1)
            {
                clearportion(53, 16, 53, 16);
                gotoxy(34, 16);
                putchar(174);
            }
            else if (quit == 2)
            {
                clearportion(34, 16, 34, 16);
                gotoxy(53, 16);
                putchar(174);
            }

            qpressed = tolower(getch());

            if (qpressed == 'a')
            {
                quit--;

                if (quit < 1)
                {
                    quit = 2;
                }
            }
            else if (qpressed == 'd')
            {
                quit++;

                if (quit > 2)
                {
                    quit = 1;
                }
            }
        }
    }
    fprintf(ic_record, "\nEOR\n");
    fclose(ic_record);

    frame_erase();
    gotoxy(4, 22);
    printf("Order has been recorded");
}

void display()
{
    FILE *ic_record = fopen("Records.txt", "r");
    int choice, amount, ctrpg = 0, ctr = 0, counter, pr, page = 1, items, count, row = 4, column = 12, position = 0;
    double price, rprice, profit;
    char date[11], product[40];
    char init[255];
    char *split;
    char chc;

    count = total();

    printxy(6, 10, "Product");
    printxy(25, 10, "Retail Price");
    printxy(41, 10, "Selling Price");
    printxy(57, 10, "Pieces");
    printxy(65, 10, "Total");
    printxy(72, 10, "Profit");

    while (!feof(ic_record))
    {
        fgets(init, 255, ic_record);

        if (strcmp(init, "EOR") == 1 && ctr == 2)
        {
            row = 4;
            column = 12;
            position = 0;
            ctr = 0;
            gotoxy(32, 18);
            printf("Page: %d of %d", page, count);
            gotoxy(4, 20);
            printf("Press any key to continue..");
            getch();
            clearportion(4, 12, 79, 17);
            page++;
        }

        if (ctr == 0)
        {
            if (strcmp(init, "SOR") == 1)
            {
                ctr = 1;
            }
        }
        else if (ctr == 1)
        {
            gotoxy(4, 8);
            printf("Date: %s", init);
            ctrpg = 0;
            ctr = 2;
        }
        else if (ctr == 2)
        {
            pr = 1;
            split = strtok(init, " ");

            if (ctrpg == 3)
            {
                row = 4;
                column = 12;
                position = 0;
                pr = 1;
                ctrpg = 0;
                gotoxy(32, 18);
                printf("Page: %d of %d", page, count);
                gotoxy(4, 20);
                printf("Press any key to continue..");
                getch();
                clearportion(4, 12, 79, 17);
                page++;
            }

            while (split != NULL)
            {
                if (pr == 1)
                {
                    if (strcmp(split, "1") == 0)
                    {
                        char ms[40] = "Milk Stick";
                        strcpy(product, ms);
                    }
                    else if (strcmp(split, "2") == 0)
                    {
                        char wm[40] = "Watermelon";
                        strcpy(product, wm);
                    }
                    else if (strcmp(split, "3") == 0)
                    {
                        char cst[40] = "Chocolate Stick";
                        strcpy(product, cst);
                    }
                    else if (strcmp(split, "12") == 0)
                    {
                        char p[40] = "Pineapple";
                        strcpy(product, p);
                    }
                    else if (strcmp(split, "4") == 0)
                    {
                        char mm[40] = "Milk Melon";
                        strcpy(product, mm);
                    }
                    else if (strcmp(split, "5") == 0)
                    {
                        char cc[40] = "Coffee Crispy";
                        strcpy(product, cc);
                    }
                    else if (strcmp(split, "6") == 0)
                    {
                        char s[40] = "Sweetcorn";
                        strcpy(product, s);
                    }
                    else if (strcmp(split, "7") == 0)
                    {
                        char cs[40] = "Chocolate Sundae";
                        strcpy(product, cs);
                    }
                    else if (strcmp(split, "18") == 0)
                    {
                        char ccp[40] = "Choco Cup";
                        strcpy(product, ccp);
                    }
                    else if (strcmp(split, "20") == 0)
                    {
                        char ss[40] = "Strawberry Sundae";
                        strcpy(product, ss);
                    }
                    else if (strcmp(split, "8") == 0)
                    {
                        char csp[40] = "Chocolate Crispy";
                        strcpy(product, csp);
                    }
                    else if (strcmp(split, "13") == 0)
                    {
                        char scp[40] = "Strawberry Crispy";
                        strcpy(product, scp);
                    }
                    else if (strcmp(split, "21") == 0)
                    {
                        char cck[40] = "Choco Cookies";
                        strcpy(product, cck);
                    }
                    else if (strcmp(split, "9") == 0)
                    {
                        char scn[40] = "Strawberry Cone";
                        strcpy(product, scn);
                    }
                    else if (strcmp(split, "10") == 0)
                    {
                        char cm[40] = "Choco Melt";
                        strcpy(product, cm);
                    }
                    else if (strcmp(split, "11") == 0)
                    {
                        char as[40] = "Alpukat Strawberry";
                        strcpy(product, as);
                    }
                    else if (strcmp(split, "17") == 0)
                    {
                        char cv[40] = "Choco Vanilla 2in1";
                        strcpy(product, cv);
                    }
                    else if (strcmp(split, "14") == 0)
                    {
                        char ms[40] = "Mango Slush";
                        strcpy(product, ms);
                    }
                    else if (strcmp(split, "15") == 0)
                    {
                        char vm[40] = "Vanilla Mochi";
                        strcpy(product, vm);
                    }
                    else if (strcmp(split, "16") == 0)
                    {
                        char mc[40] = "Mochi Chocolate";
                        strcpy(product, mc);
                    }
                    else if (strcmp(split, "19") == 0)
                    {
                        char ip[40] = "Ice Pop";
                        strcpy(product, ip);
                    }
                    gotoxy(row, column);
                    printf("%s", product);
                    position++;
                    pr = 0;
                }
                else
                {
                    if (strcmp(init, "EOR") == -1)
                    {
                        if (position == 1)
                        {
                            row += 25;
                        }
                        else if (position == 2)
                        {
                            row += 14;
                        }
                        else if (position == 3)
                        {
                            row += 15;
                        }
                        else if (position == 4)
                        {
                            row += 6;
                        }
                        else if (position == 5)
                        {
                            row += 9;
                        }
                        gotoxy(row, column);
                        printf("%s", split);
                        position++;
                    }
                }
                split = strtok(NULL, " ");
            }
            ctrpg++;
            row = 4;
            column += 2;
            position = 0;
        }
    }
    fclose(ic_record);
    frame_erase();
}

int total()
{
    FILE *ic_record = fopen("Records.txt", "r");
    int choice, amount, ctrpg = 0, ctr = 0, counter, pr, page = 1, items, count, total = 0;
    double price, rprice, profit;
    char date[11], product[40];
    char init[255];
    char *split;
    char chc;

    while (!feof(ic_record))
    {
        fgets(init, 255, ic_record);

        if (strcmp(init, "EOR") == 1 && ctr == 2)
        {
            ctr = 0;
            total++;
        }

        if (ctr == 0)
        {
            if (strcmp(init, "SOR") == 1)
            {
                ctr = 1;
            }
        }
        else if (ctr == 1)
        {
            ctrpg = 0;
            ctr = 2;
        }
        else if (ctr == 2)
        {
            pr = 1;
            split = strtok(init, " ");

            if (ctrpg == 3)
            {
                pr = 0;
                ctrpg = 0;
                total++;
            }

            while (split != NULL)
            {
                if (pr == 1)
                {
                    if (strcmp(split, "1") == 0)
                    {
                        char ms[40] = "Milk Stick";
                        strcpy(product, ms);
                    }
                    else if (strcmp(split, "2") == 0)
                    {
                        char wm[40] = "Watermelon";
                        strcpy(product, wm);
                    }
                    else if (strcmp(split, "3") == 0)
                    {
                        char cst[40] = "Chocolate Stick";
                        strcpy(product, cst);
                    }
                    else if (strcmp(split, "12") == 0)
                    {
                        char p[40] = "Pineapple";
                        strcpy(product, p);
                    }
                    else if (strcmp(split, "4") == 0)
                    {
                        char mm[40] = "Milk Melon";
                        strcpy(product, mm);
                    }
                    else if (strcmp(split, "5") == 0)
                    {
                        char cc[40] = "Coffee Crispy";
                        strcpy(product, cc);
                    }
                    else if (strcmp(split, "6") == 0)
                    {
                        char s[40] = "Sweetcorn";
                        strcpy(product, s);
                    }
                    else if (strcmp(split, "7") == 0)
                    {
                        char cs[40] = "Chocolate Sundae";
                        strcpy(product, cs);
                    }
                    else if (strcmp(split, "18") == 0)
                    {
                        char ccp[40] = "Choco Cup";
                        strcpy(product, ccp);
                    }
                    else if (strcmp(split, "20") == 0)
                    {
                        char ss[40] = "Strawberry Sundae";
                        strcpy(product, ss);
                    }
                    else if (strcmp(split, "8") == 0)
                    {
                        char csp[40] = "Chocolate Crispy";
                        strcpy(product, csp);
                    }
                    else if (strcmp(split, "13") == 0)
                    {
                        char scp[40] = "Strawberry Crispy";
                        strcpy(product, scp);
                    }
                    else if (strcmp(split, "21") == 0)
                    {
                        char cck[40] = "Choco Cookies";
                        strcpy(product, cck);
                    }
                    else if (strcmp(split, "9") == 0)
                    {
                        char scn[40] = "Strawberry Cone";
                        strcpy(product, scn);
                    }
                    else if (strcmp(split, "10") == 0)
                    {
                        char cm[40] = "Choco Melt";
                        strcpy(product, cm);
                    }
                    else if (strcmp(split, "11") == 0)
                    {
                        char as[40] = "Alpukat Strawberry";
                        strcpy(product, as);
                    }
                    else if (strcmp(split, "17") == 0)
                    {
                        char cv[40] = "Choco Vanilla 2in1";
                        strcpy(product, cv);
                    }
                    else if (strcmp(split, "14") == 0)
                    {
                        char ms[40] = "Mango Slush";
                        strcpy(product, ms);
                    }
                    else if (strcmp(split, "15") == 0)
                    {
                        char vm[40] = "Vanilla Mochi";
                        strcpy(product, vm);
                    }
                    else if (strcmp(split, "16") == 0)
                    {
                        char mc[40] = "Mochi Chocolate";
                        strcpy(product, mc);
                    }
                    else if (strcmp(split, "19") == 0)
                    {
                        char ip[40] = "Ice Pop";
                        strcpy(product, ip);
                    }
                    pr = 0;
                }
                else
                {
                    if (strcmp(init, "EOR") == -1)
                    {
                    }
                }
                split = strtok(NULL, " ");
            }
            ctrpg++;
        }
    }

    return total;
}

void search()
{
    FILE *ic_record = fopen("Records.txt", "r");
    char date[20];
    char *split;
    char line[255];
    char product[30];
    int it = 0, ctr = 0, pr = 1, counter = 0, page = 1, pgctr = 0, dt = 0, total, row = 4, column = 12, position = 0;

    gotoxy(10, 15);
    printf("Enter date to be searched (Format: mm/dd/yyyy):");
    gotoxy(58, 15);
    scanf("%s", date);
    frame();

    total = total_search(date);

    frame_erase();

    printxy(6, 10, "Product");
    printxy(25, 10, "Retail Price");
    printxy(41, 10, "Selling Price");
    printxy(57, 10, "Pieces");
    printxy(65, 10, "Total");
    printxy(72, 10, "Profit");

    while (fscanf(ic_record, "%s", line) != EOF)
    {
        split = strtok(line, " ");

        if (ctr == 1 && strcmp(line, "EOR") != 0)
        {
            while (split != NULL)
            {
                it = 1;
                if (counter == 0)
                {
                    if (strcmp(split, "1") == 0)
                    {
                        char ms[40] = "Milk Stick";
                        strcpy(product, ms);
                    }
                    else if (strcmp(split, "2") == 0)
                    {
                        char wm[40] = "Watermelon";
                        strcpy(product, wm);
                    }
                    else if (strcmp(split, "3") == 0)
                    {
                        char cst[40] = "Chocolate Stick";
                        strcpy(product, cst);
                    }
                    else if (strcmp(split, "12") == 0)
                    {
                        char p[40] = "Pineapple";
                        strcpy(product, p);
                    }
                    else if (strcmp(split, "4") == 0)
                    {
                        char mm[40] = "Milk Melon";
                        strcpy(product, mm);
                    }
                    else if (strcmp(split, "5") == 0)
                    {
                        char cc[40] = "Coffee Crispy";
                        strcpy(product, cc);
                    }
                    else if (strcmp(split, "6") == 0)
                    {
                        char s[40] = "Sweetcorn";
                        strcpy(product, s);
                    }
                    else if (strcmp(split, "7") == 0)
                    {
                        char cs[40] = "Chocolate Sundae";
                        strcpy(product, cs);
                    }
                    else if (strcmp(split, "18") == 0)
                    {
                        char ccp[40] = "Choco Cup";
                        strcpy(product, ccp);
                    }
                    else if (strcmp(split, "20") == 0)
                    {
                        char ss[40] = "Strawberry Sundae";
                        strcpy(product, ss);
                    }
                    else if (strcmp(split, "8") == 0)
                    {
                        char csp[40] = "Chocolate Crispy";
                        strcpy(product, csp);
                    }
                    else if (strcmp(split, "13") == 0)
                    {
                        char scp[40] = "Strawberry Crispy";
                        strcpy(product, scp);
                    }
                    else if (strcmp(split, "21") == 0)
                    {
                        char cck[40] = "Choco Cookies";
                        strcpy(product, cck);
                    }
                    else if (strcmp(split, "9") == 0)
                    {
                        char scn[40] = "Strawberry Cone";
                        strcpy(product, scn);
                    }
                    else if (strcmp(split, "10") == 0)
                    {
                        char cm[40] = "Choco Melt";
                        strcpy(product, cm);
                    }
                    else if (strcmp(split, "11") == 0)
                    {
                        char as[40] = "Alpukat Strawberry";
                        strcpy(product, as);
                    }
                    else if (strcmp(split, "17") == 0)
                    {
                        char cv[40] = "Choco Vanilla 2in1";
                        strcpy(product, cv);
                    }
                    else if (strcmp(split, "14") == 0)
                    {
                        char ms[40] = "Mango Slush";
                        strcpy(product, ms);
                    }
                    else if (strcmp(split, "15") == 0)
                    {
                        char vm[40] = "Vanilla Mochi";
                        strcpy(product, vm);
                    }
                    else if (strcmp(split, "16") == 0)
                    {
                        char mc[40] = "Mochi Chocolate";
                        strcpy(product, mc);
                    }
                    else if (strcmp(split, "19") == 0)
                    {
                        char ip[40] = "Ice Pop";
                        strcpy(product, ip);
                    }
                    gotoxy(row, column);
                    printf("%s", product);
                    position++;
                    counter++;
                }
                else if (counter > 0)
                {
                    if (position == 1)
                    {
                        row += 25;
                    }
                    else if (position == 2)
                    {
                        row += 14;
                    }
                    else if (position == 3)
                    {
                        row += 15;
                    }
                    else if (position == 4)
                    {
                        row += 6;
                    }
                    else if (position == 5)
                    {
                        row += 9;
                    }
                    gotoxy(row, column);
                    printf("%s", split);
                    position++;
                    counter++;

                    if (counter == 6)
                    {
                        counter = 0;
                        pgctr++;
                        row = 4;
                        column += 2;
                        position = 0;

                        if (pgctr == 3)
                        {
                            gotoxy(4, 20);
                            printf("Press any key to continue..");
                            getch();
                            clearportion(4, 12, 79, 17);
                            page++;
                            row = 4;
                            column = 12;
                            position = 0;
                            pgctr = 0;
                            gotoxy(32, 18);
                            printf("page: %d  of %d", page, total);
                        }
                    }
                }

                split = strtok(NULL, " ");
            }
        }

        split = strtok(line, " ");

        if (dt == 1)
        {
            if (strcmp(date, line) == 0)
            {
                gotoxy(4, 8);
                printf("date: %s", date);
                gotoxy(32, 18);
                printf("page: %d of %d", page, total);
                ctr = 1;
                dt = 0;
            }
            else
            {
                dt = 0;
            }
        }

        if (strcmp(split, "SOR") == 0)
        {
            dt = 1;
        }

        if (strcmp(split, "EOR") == 0)
        {
            ctr = 0;
            gotoxy(4, 20);
            printf("Press any key to continue..");
            getch();
        }
    }

    if (it != 1)
    {
        printf("\nThere is no match");
    }
    frame_erase();
}

void back_up()
{
    char pressed;
    int choice = 1;

    while (pressed != 'e')
    {
        if (choice == 1)
        {
            gotoxy(40, 16);
            putchar(174);
            clearportion(44, 16, 44, 16);
        }
        else if (choice == 2)
        {
            gotoxy(44, 16);
            putchar(174);
            clearportion(40, 16, 40, 16);
        }
        center(11, "Warning!");
        center(12, "It will overwrite the existing back up if there is one.");
        center(13, "(use \"a\" and \"d\" to choose answer and \"e\" to enter");
        center(15, "Continue?");
        printxy(37, 16, "Yes");
        printxy(42, 16, "No");
        pressed = tolower(getch());

        if (pressed == 'a')
        {
            choice--;
            if (choice < 1)
            {
                choice = 2;
            }
        }
        else if (pressed == 'd')
        {
            choice++;
            if (choice > 2)
            {
                choice = 1;
            }
        }
    }

    if (choice == 1)
    {
        FILE *orig = fopen("Records.txt", "r");
        FILE *back_up = fopen("Records Back Up.txt", "w");
        char line[255];

        while (!feof(orig))
        {
            fgets(line, 255, orig);
            fprintf(back_up, "%s", line);
        }
        fclose(orig);
        fclose(back_up);
        frame_erase();
        gotoxy(4, 22);
        printf("Back up has been created");
    }
    else if (choice == 2)
    {
        frame_erase();
    }
}

int total_search(char *date)
{
    FILE *ic_record = fopen("Records.txt", "r");
    char *split;
    char line[255];
    char product[30];
    int it = 0, ctr = 0, pr = 1, counter = 0, page = 1, pgctr = 0, dt = 0, total;

    while (fscanf(ic_record, "%s", line) != EOF)
    {
        split = strtok(line, " ");

        if (ctr == 1 && strcmp(line, "EOR") != 0)
        {
            while (split != NULL)
            {
                it = 1;
                if (counter == 0)
                {
                    if (strcmp(split, "1") == 0)
                    {
                        char ms[40] = "Milk Stick";
                        strcpy(product, ms);
                    }
                    else if (strcmp(split, "2") == 0)
                    {
                        char wm[40] = "Watermelon";
                        strcpy(product, wm);
                    }
                    else if (strcmp(split, "3") == 0)
                    {
                        char cst[40] = "Chocolate Stick";
                        strcpy(product, cst);
                    }
                    else if (strcmp(split, "12") == 0)
                    {
                        char p[40] = "Pineapple";
                        strcpy(product, p);
                    }
                    else if (strcmp(split, "4") == 0)
                    {
                        char mm[40] = "Milk Melon";
                        strcpy(product, mm);
                    }
                    else if (strcmp(split, "5") == 0)
                    {
                        char cc[40] = "Coffee Crispy";
                        strcpy(product, cc);
                    }
                    else if (strcmp(split, "6") == 0)
                    {
                        char s[40] = "Sweetcorn";
                        strcpy(product, s);
                    }
                    else if (strcmp(split, "7") == 0)
                    {
                        char cs[40] = "Chocolate Sundae";
                        strcpy(product, cs);
                    }
                    else if (strcmp(split, "18") == 0)
                    {
                        char ccp[40] = "Choco Cup";
                        strcpy(product, ccp);
                    }
                    else if (strcmp(split, "20") == 0)
                    {
                        char ss[40] = "Strawberry Sundae";
                        strcpy(product, ss);
                    }
                    else if (strcmp(split, "8") == 0)
                    {
                        char csp[40] = "Chocolate Crispy";
                        strcpy(product, csp);
                    }
                    else if (strcmp(split, "13") == 0)
                    {
                        char scp[40] = "Strawberry Crispy";
                        strcpy(product, scp);
                    }
                    else if (strcmp(split, "21") == 0)
                    {
                        char cck[40] = "Choco Cookies";
                        strcpy(product, cck);
                    }
                    else if (strcmp(split, "9") == 0)
                    {
                        char scn[40] = "Strawberry Cone";
                        strcpy(product, scn);
                    }
                    else if (strcmp(split, "10") == 0)
                    {
                        char cm[40] = "Choco Melt";
                        strcpy(product, cm);
                    }
                    else if (strcmp(split, "11") == 0)
                    {
                        char as[40] = "Alpukat Strawberry";
                        strcpy(product, as);
                    }
                    else if (strcmp(split, "17") == 0)
                    {
                        char cv[40] = "Choco Vanilla 2in1";
                        strcpy(product, cv);
                    }
                    else if (strcmp(split, "14") == 0)
                    {
                        char ms[40] = "Mango Slush";
                        strcpy(product, ms);
                    }
                    else if (strcmp(split, "15") == 0)
                    {
                        char vm[40] = "Vanilla Mochi";
                        strcpy(product, vm);
                    }
                    else if (strcmp(split, "16") == 0)
                    {
                        char mc[40] = "Mochi Chocolate";
                        strcpy(product, mc);
                    }
                    else if (strcmp(split, "19") == 0)
                    {
                        char ip[40] = "Ice Pop";
                        strcpy(product, ip);
                    }
                    counter++;
                }
                else if (counter > 0)
                {
                    counter++;

                    if (counter == 6)
                    {
                        counter = 0;
                        pgctr++;

                        if (pgctr == 3)
                        {
                            pgctr = 0;
                            total++;
                        }
                    }
                }

                split = strtok(NULL, " ");
            }
        }

        split = strtok(line, " ");

        if (dt == 1)
        {
            if (strcmp(date, line) == 0)
            {
                ctr = 1;
                dt = 0;
            }
            else
            {
                dt = 0;
            }
        }

        if (strcmp(split, "SOR") == 0)
        {
            dt = 1;
        }

        if (strcmp(split, "EOR") == 0)
        {
            ctr = 0;
        }
    }

    if (it == 1)
    {
        return total;
    }
}

void frame()
{
    line2(2, 2, 80, 6);
    line2(2, 2, 80, 24);
    printxy(4, 4, "Aice Order Recorder");

    gotoxy(77, 4);
    putchar('X');
    gotoxy(73, 4);
    putchar(254);
    gotoxy(69, 4);
    putchar(196);
}

void frame_erase()
{
    clearportion(3, 7, 79, 23);
}
