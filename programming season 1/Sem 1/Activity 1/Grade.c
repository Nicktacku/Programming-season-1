#include <stdio.h>
#include <ctype.h>

int main(){
    float q1, q2, q3, q4, ave;
    char gradingSystem;

    printf("Enter 1st quarter grade: ");
    scanf("%f", &q1);
    printf("Enter 2nd quarter grade: ");
    scanf("%f", &q2);
    printf("Enter 3rd quarter grade: ");
    scanf("%f", &q3);
    printf("Enter 4th quarter grade: ");
    scanf("%f", &q4);
    printf("Enter grading system: ");
    scanf(" %c", &gradingSystem);
    gradingSystem = tolower(gradingSystem);

    if(gradingSystem == 'a'){
        ave = (q1 + q2 + q3 + q4) / 4;
    } else if (gradingSystem == 'w'){
        ave = q1 * .2 + q2 * .2 + q3 * .2 + q4 * .4;
    } else if (gradingSystem == 'c'){
        ave = q4;
    } else{
        printf("\nInvalid grading system");
    }

    printf("\naverage: %.2f", ave);
}