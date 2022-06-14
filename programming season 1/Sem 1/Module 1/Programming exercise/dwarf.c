#include <stdio.h>

// returns if dwarf or not
int dwarf(int num);
// returns sum of the factor
int factor(int num);

int main(){
    int num;

    printf("Enter number: ");
    scanf("%d", &num);

    dwarf(num);

    return 0;
}

int dwarf(int num){
    int sum, quotient;
    sum = factor(num);
    quotient = num / 2;

    if(num > 0){
        if(sum > quotient){
            printf("Dwarf");
        } else{
            printf("Not Dwarf");
        }
    } else{
        printf("Invalid input");
    }
}

int factor(int num){
    int i = 1, result = 0;

    for(i; i < num; i++){
        if(num % i == 0){
            result += i;
        }
    }
    return result;
}