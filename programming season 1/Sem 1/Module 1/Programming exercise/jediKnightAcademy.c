#include <stdio.h>

int isAccepted(int height, int age, int cc, int rc);

int main(){
    int height, age, cc, rc;

    printf("Enter height in cm: ");
    scanf("%d", &height);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter \"1\" if a citizen of endor, \"0\" if not: ");
    scanf("%d", &cc);
    printf("Enter \"1\" if a recmmended by jedi master obi wan, \"0\" if not: ");
    scanf("%d", &rc);

    // determines if the applicant passed
    isAccepted(height, age, cc, rc);

    return 0;
}

int isAccepted(int height, int age, int cc, int rc){
    if(height >= 200 && (age > 21 || age < 25) && cc == 1){
        printf("\nApplicant is accepted");
    } else if(rc == 1){
        printf("\nApplicant is accepted");
    } else {
        printf("\nApplicant is rejected");
    }
}