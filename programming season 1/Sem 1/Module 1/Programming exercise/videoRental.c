#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int days_late, cd, vhs;
    char type[10];

    printf("Enter how many days its late: ");
    scanf("%d", &days_late);
    printf("What type? Cd or Vhs: ");
    scanf("%s", type);

     for (int i = 0; i < strlen(type); ++i) {
        type[i] = tolower(type[i]);
    }

    cd = strcmp("cd", type);
    vhs = strcmp("vhs", type);

    if(days_late <= 2){
        printf("Fine: 10.00");
    } else if(days_late <= 4){
        printf("Fine: 15.00");
    } else if(days_late <= 6){
        printf("Fine: 20.00");
    } else if (days_late >= 7){
        if(cd == 0){
            printf("Fine: 50.00");
        } else {
            printf("Fine: 35.00");
        }
    }

    return 0;
}