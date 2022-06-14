#include <stdio.h>

//takes the inputs and return in descended order
int descending(int num1, int num2, int num3);

int main(){
    int num1, num2, num3;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter third number: ");
    scanf("%d", &num3);

    descending(num1, num2, num3);

    return 0;
}

int descending(int num1, int num2, int num3){
    if(num1 > num2 && num1 > num3){
        if(num2 > num3){
            printf("\n%d, %d, %d", num1, num2, num3);
        } else {
            printf("%d, %d, %d", num1, num3, num2);
        }
    } else if(num2 > num1 && num2 > num3){
        if(num1 > num3){
            printf("%d, %d, %d", num2, num1, num3);
        } else {
            printf("%d, %d, %d", num2, num3, num1);
        }
    } else {
        if(num1 > num2){
            printf("%d, %d, %d", num3, num1, num2);
        } else {
            printf("%d, %d, %d", num3, num2, num1);
        }
    }
}