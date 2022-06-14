#include <stdio.h>

int even(int num);

int main(){
    int BSIT[20];
    int i, sum;

    for(i = 0; i < 20; i++){
        printf("Enter Number: ");
        scanf("%d", &BSIT[i]);
        sum += even(BSIT[i]);
    }

    for(i = 0; i < 20; i++){
        printf("%d\n", BSIT[i]);
    }

    printf("sum: %d", sum);

    return 0;
}

int even(int num){
    //checks if its even
    if(num % 2 == 0){
        return num;
    }else {
        return 0;
    }
}