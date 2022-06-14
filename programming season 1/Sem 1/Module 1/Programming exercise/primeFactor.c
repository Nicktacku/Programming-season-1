#include <stdio.h>
#include <stdbool.h>

int primeFactor(int num);
int primes(int num);

int main(){
    int num;

    printf("Enter non-negative number: ");
    scanf("%d", &num);

    if(num > 0){
        primeFactor(num);
        }
    else{
        printf("Invalid input");
    }

    return 0;
}

int primeFactor(int num){
    int i, divisible;

    printf("Prime factors are: ");
    for(i = 1; i < num; i++){
        divisible = num % i;
        if(divisible == 0 && primes(i) == true){
            printf("%d ", i);
        }
    }
}

int primes(int num){
    int j = 2;
    bool prime = false;

    for(j; j < num; j++){
        if(num % j == 0){
            prime = true;
        }

    }
    if(prime == false){
        return true;
    } else {
        return false;
    }


}