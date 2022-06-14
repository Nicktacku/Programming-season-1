#include <stdio.h>

int factorial(int num);

int main(){
    int num;
    printf("Enter number: ");
    scanf("%d", &num);

    if(num > 0){
        printf("result: %d", factorial(num));
    } else {
        printf("Invalid Input");
    }
    return 0;
}

int factorial(int num){
    int i, result = 1;
    for(i = 1; i <= num; i++){
        //if the number is 0 it will return 1
        if(num == 0){
            return 1;
        } else{
            result *= i;
        }
    }
    return result;
}