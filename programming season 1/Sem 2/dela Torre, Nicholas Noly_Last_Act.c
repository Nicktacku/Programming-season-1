#include <myfunctions.h>

void create();
void order();
void display();
void search();
void back_up();
int total();
int total_search(char *date);

int main()
{
    int choice = 0;
    char press;
    char end = 'n';

    line2(2, 2, 80, 6);
    line2(2, 2, 80, 24);
    printxy(4, 4, "Aice Order Recorder");

    gotoxy(77, 4);
    putchar('X');
    gotoxy(73, 4);
    putchar(254);
    gotoxy(69, 4);
    putchar(196);

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

    gotoxy(22, 14);
    putchar(174);
    gotoxy(4, 22);

    while (end != 'y')
    {
        press = getch();

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
                end = 'y';
            }
        }

        if (choice == 0)
        {
            clearportion(9, 19, 12, 19);
            clearportion(18, 15, 22, 15);
            gotoxy(22, 14);
            putchar(174);
            gotoxy(4, 22);
        }
        else if (choice == 1)
        {
            clearportion(22, 14, 25, 14);
            clearportion(22, 16, 25, 16);
            gotoxy(18, 15);
            putchar(174);
            gotoxy(4, 22);
        }
        else if (choice == 2)
        {
            clearportion(18, 15, 22, 15);
            clearportion(11, 17, 14, 17);
            gotoxy(22, 16);
            putchar(174);
            gotoxy(4, 22);
        }
        else if (choice == 3)
        {
            clearportion(22, 16, 25, 16);
            clearportion(12, 18, 15, 18);
            gotoxy(11, 17);
            putchar(174);
            gotoxy(4, 22);
        }
        else if (choice == 4)
        {
            clearportion(11, 17, 14, 17);
            clearportion(9, 19, 12, 19);
            gotoxy(12, 18);
            putchar(174);
            gotoxy(4, 22);
        }
        else if (choice == 5)
        {
            clearportion(12, 18, 15, 18);
            clearportion(22, 14, 25, 14);
            gotoxy(9, 19);
            putchar(174);
            gotoxy(4, 22);
        }
    }
    gotoxy(0, 26);
    return 0;
}

void create()
{
    int choice;

    printf("\nIt will overwrite the existing record if there is one.");
    printf("\nContinue? ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        FILE *ic_record = fopen("Records.txt", "w");
        printf("File has been created");
        fclose(ic_record);
    }
    else if (choice == 2)
    {
        return;
    }
}

void order()
{
    FILE *ic_record = fopen("Records.txt", "a");
    int choice, amount;
    double price, rprice, total, profit;
    char date[11], product[40];
    int quit;

    system("cls");
    printf("\nEnter the date of the order (mm/dd/yyyy): ");
    scanf("%s", date);

    fprintf(ic_record, "SOR");
    fprintf(ic_record, "\n%s", date);

    while (quit != 1)
    {
        system("cls");
        printf("\nFlavors:\n");

        printf("\n1) Milk Stick\t");
        printf("2) Watermelon\t");
        printf("3) Chocolate\n\n");

        printf("4) Milk Melon\t");
        printf("5) Coffee Crispy\t");
        printf("6) Sweetcorn\n\n");

        printf("7) Chocolate Sunday\t");
        printf("8) Chocolate Crispy\t");
        printf("9) Strawberry Cone\n\n");

        printf("10) Choco Melt\t");
        printf("11) Alpukat Strawberry\t");
        printf("12) Pineapple\n\n");

        printf("13) Strawberry Crispy\t");
        printf("14) Mango Slush\t");
        printf("15) Vanilla Mochi\n\n");

        printf("16) Mochi Chocolate\t");
        printf("17) Choco Vanilla 2in1\t");
        printf("18) Choco Cup\n\n");

        printf("19) Ice Pop\t");
        printf("20) Strawberry Sundae\t");
        printf("21) Choco Cookies\n\n");

        printf("Choose the flavor that will be ordered: ");
        scanf("%d", &choice);

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

        printf("\nEnter the number of ice cream that will be ordered: ");
        scanf("%d", &amount);
        printf("\nEnter the price you will sell the product (should be more than %.2lf): ", rprice);
        scanf("%lf", &price);
        total = rprice * amount;
        profit = (price * amount) - total;

        fprintf(ic_record, "\n%d %.2lf %.2lf %d %.2lf %.2lf", choice, rprice, price, amount, total, profit);

        printf("Are you going to order product? ");
        scanf("%d", &quit);
    }
    fprintf(ic_record, "\nEOR\n\n");
    fclose(ic_record);
}

void display()
{
    FILE *ic_record = fopen("Records.txt", "r");
    int choice, amount, ctrpg = 0, ctr = 0, counter, pr, page = 1, items, count;
    double price, rprice, profit;
    char date[11], product[40];
    char init[255];
    char *split;
    char chc;

    system("cls");

    count = total();

    while (!feof(ic_record))
    {
        fgets(init, 255, ic_record);

        if (strcmp(init, "EOR") == 1 && ctr == 2)
        {
            ctr = 0;
            printf("\nPage: %d of %d", page, count);
            getch();
            system("cls");
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
            printf("\nDate: %s\n", init);
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
                printf("\nPage: %d of %d", page, count);
                getch();
                system("cls");
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
                    printf("\nFlavor: %s ", product);
                    pr = 0;
                }
                else
                {
                    if (strcmp(init, "EOR") == -1)
                    {
                        printf("%s ", split);
                    }
                }
                split = strtok(NULL, " ");
            }
            ctrpg++;
        }
    }
    fclose(ic_record);
}

int total()
{
    FILE *ic_record = fopen("Records.txt", "r");
    int choice, amount, ctrpg = 0, ctr = 0, counter, pr, page = 1, items, count, total;
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
    int it = 0, ctr = 0, pr = 1, counter = 0, page = 1, pgctr = 0, dt = 0, total;

    printf("Enter date to be searched (Format: mm/dd/yyyy): ");
    scanf("%s", date);

    total = total_search(date);

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
                    printf("\n%s ", product);
                    counter++;
                }
                else if (counter > 0)
                {

                    printf("%s ", split);
                    counter++;

                    if (counter == 6)
                    {
                        counter = 0;
                        pgctr++;

                        if (pgctr == 3)
                        {
                            getch();
                            system("cls");
                            page++;
                            printf("\npage: %d", page);
                            printf(" of %d", total);
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
                printf("\ndate: %s", date);
                printf("\npage: %d", page);
                printf(" of %d", total);
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
    }
    else
    {
        printf("\nThere is no match");
    }
}

void back_up()
{
    FILE *orig = fopen("Records.txt", "r");
    FILE *back_up = fopen("Records Back Up.txt", "w");
    char line[255];

    while (!feof(orig))
    {
        fgets(line, 255, orig);
        fprintf(back_up, "%s", line);
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
