#include <myfunctions.h>

void create();
void order();
void display();
void search();
void back_up();

int main()
{
    int choice;
    char end = 'y';

    printf("Aice order recorder\n\n");
    printf("Menu:\n\n");
    printf("Create new record\n");
    printf("Add new order\n");
    printf("Display all order\n");
    printf("Search\n");
    printf("Back Up\n");
    printf("Exit\n");

    printf("\n\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        create();
    }
    else if (choice == 2)
    {
        order();
    }
    else if (choice == 3)
    {
        display();
    }
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
    int choice, amount, ctrpg = 0, ctr = 0, counter, pr, page = 1;
    double price, rprice, total, profit;
    char date[11], product[40];
    char init[255];
    char *split;

    system("cls");

    while (!feof(ic_record))
    {
        fgets(init, 255, ic_record);

        if (strcmp(init, "EOR") == 1)
        {
            ctr = 0;
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
            ctr = 2;
        }
        else if (ctr == 2)
        {
            pr = 1;
            split = strtok(init, " ");

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
                    printf("\n%s ", product);
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
        page++;
    }
    fclose(ic_record);
}