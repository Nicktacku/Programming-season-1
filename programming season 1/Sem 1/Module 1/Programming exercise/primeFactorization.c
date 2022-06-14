#include <stdio.h>
#include <stdbool.h>

int primeFactorization(int num);
//determines if prime or not
int isItPrime(int num);
int firstPrime(int num);

int main(){
    int num;

    printf("Enter number: ");
    scanf("%d", &num);

    if(num > 0){
        primeFactorization(num);
        printf("%d", num);
    } else{
        printf("Invalid Input");
    }

    return 0;
}

//function that most process will be done
int primeFactorization(int num){
    int i, next, nums[50];
    bool end = false;

    //until it isnt prime will ouput the prime factors
    while(end == false && isItPrime(i) == false){
        printf("%d ", firstPrime(num));
        num = num / firstPrime(num);
        // if prime then will prepare to point at the starting number
        if(isItPrime(num) == true){
            printf("%d = ", num);
            end = true;
        }
    }
}

int isItPrime(int num){
    int i = 2;
    bool prime = false;

    for(i; i < num; i++){
        if(num % i == 0){
            prime = true;
        }

    }
    if(prime == false){
        return true;
    } else {
        return false;
    }
}

int firstPrime(int num){
    int i, nums[50], ctr, next;
    bool end = false;

    //return the lowest multiple
    for(i = 2; i < num; i++){
            if(num % i == 0){
                return i;
        }
    }
}