#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

// declarations
int validator();
int generator();

// Nicholas Noly C. dela Torre
int main() {
    // char toQuit is equal to anything but y and n
    // for the program to work
    char choice, toQuit = 'h';
    // quit and ws are used as boolean values
    int i, quit = 0, ws;

    // Simple welcome of the program
    printf("\n************************************");
    printf("\n*                                  *");
    printf("\n* PASSWORD GENERATOR AND VALIDATOR *");
    printf("\n*                                  *");
    printf("\n************************************");
    printf("\n\nPassword Criteria:");
    printf("\n\n- Must have lowercase and uppercase letters");
    printf("\n- Must have a number");
    printf("\n- Must have a special character");
    printf("\n- Lenght of the password should be 8 or more words");
    printf("\n\n*****************************************************");

    // main system
    while(quit == 0){
        // ws is set here so it will be 0 every repeat
        ws = 0;
        // prompts the user
        printf("\n\nWhat do you want to do? Validate (v) or Generate (g) password: ");
        scanf(" %c", &choice);
        // considers the case of the inputted char
        choice = tolower(choice);

        // Does the function based on the inputted char
        if (choice == 'v'){
            validator();
        } else if (choice == 'g'){
            generator();
        } else {
            system("cls");
            printf("\nInvalid Input.\n");
        }

        // system that will quit or continue the program
        while(ws == 0){
            printf("\nDo you still want to continue? Yes (y) or No (n): ");
            scanf(" %c", &toQuit);
            toQuit = tolower(toQuit);

            if(toQuit == 'y'){
                // Continue the program
                quit = 0;
                ws = 1;
                system("cls");
            } else if(toQuit == 'n'){
                // quit the program
                system("cls");
                printf("Nicholas Noly C. dela Torre");
                quit = 1;
                ws = 1;
            } else{
                // if the input is none of the choice
                system("cls");
                printf("\nInvalid Input.\n");
            }
        }
    }
}


int validator(){
    char password[20];
    int i, j, passLenght, sum;
    // unique counters to see the validity by adding them
    int lowCtr = 0, upCtr = 0, numCtr = 0, symCtr = 0;
    char lettersLowerCase[30] = {'a', 'b', 'c', 'd', 'e',
    'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r','s', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char lettersUpperCase[30];
    char numbers[15] = {'1', '2', '3', '4', '5', '6', '7',
     '8', '9', '0'};
    char specialCharacters[35] = {'`', '~', '!', '@', '#',
    '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+',
     '{', '[', ']', '}', '|', '\\', ':', ';', '\'', '\"',
     '/', '?'};

    system("cls");

    // Converts the lowercase alphabet into a list
    // of uppercase letter, for lesser manual work
    for(i = 0; i < 26; i++){
        char makeUpper = toupper(lettersLowerCase[i]);
        lettersUpperCase[i] = makeUpper;
    }

    printf("\nEnter Password: ");
    scanf("%s", password);

    // this will be used in the for loops
    // as well to check the validity of
    // password entered
    passLenght = strlen(password);

    if (passLenght > 4){

        // this set of for loops will scan through
        // the password checking each character
        for(i = 0; i < passLenght; i++){
            for(j = 0; j < 26; j++){
                if (lettersLowerCase[j] == password[i]){
                    lowCtr += 1;
                }
            }
        }

        for(i = 0; i < passLenght; i++){
            for(j = 0; j < 26; j++){
                if (lettersUpperCase[j] == password[i]){
                    upCtr += 1;
                }
            }
       }

        for(i = 0; i < passLenght; i++){
            for(j = 0; j < 10; j++){
                if (numbers[j] == password[i]){
                    numCtr += 1;
                }
            }
        }

        for(i = 0; i < passLenght; i++){
            for(j = 0; j < 28; j++){
                if (specialCharacters[j] == password[i]){
                    symCtr += 1;
                }
            }
        }

        // adds the present secured feature/s of the password
        if(lowCtr > 0){
            sum += 1;
        }

        if(upCtr > 0){
            sum += 1;
        }

        if(numCtr > 0){
            sum += 1;
        }

        if(symCtr > 0){
            sum += 1;
        }

        if(passLenght >= 8){
            sum += 1;
        }

        // checks the password and will have remark
        // based on the sum
        if(sum == 5){
            printf("\nYour password is secure, Good Job!\n");
        } else if(sum == 4){
            printf("\nYour password is decent, Keep it up!\n");
        } else if(sum == 3){
            printf("\nYour password is Unsecured, Try to make it safer.\n");
        } else if(sum <= 2){
            printf("\nYour password is Hackable, I recommend you to try our password generator.\n");
        }

    // makes sure the password is not short
    } else {
        system("cls");
        printf("\nPassword is too short\n");
    }

}

int generator(){
    int passLength, i, which;
    int min = 8;
    int max = 15;
    char letter, number, symbol;
    char lettersLowerCase[30] = {'a', 'b', 'c', 'd', 'e',
    'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r','s', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char lettersUpperCase[30];
    char numbers[15] = {'1', '2', '3', '4', '5', '6', '7',
     '8', '9', '0'};
    char specialCharacters[35] = {'`', '~', '!', '@', '#',
    '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+',
     '{', '[', ']', '}', '|', '\\', ':', ';', '\'', '\"',
     '/', '?'};

    system("cls");

    for(i = 0; i < 26; i++){
        char makeUpper = toupper(lettersLowerCase[i]);
        lettersUpperCase[i] = makeUpper;
    }


    // seed of the random function with
    // time function within to serve as
    // a random variable
    srand(time(NULL));

    // gives a random number from the range of
    // 8 to 15
    passLength = (rand() % (max - min + 1)) + min;

    printf("\nPassword: ");

    // Prints out the random password
    // until a password with lenght of
    // 8 to 15 is made
    for(i = 0; i < passLength; i++){
        which = rand() % 4;

        if (which == 0){
            letter = rand() % 26;
            printf("%c",lettersLowerCase[letter]);
        } else if (which == 1){
            letter = rand() % 26;
            printf("%c",lettersUpperCase[letter]);
        } else if (which == 2){
            number = rand() % 10;
            printf("%c",numbers[number]);
        } else if (which == 3){
            symbol = rand() % 28;
            printf("%c",specialCharacters[symbol]);
        }
    }
    printf("\n");
}
