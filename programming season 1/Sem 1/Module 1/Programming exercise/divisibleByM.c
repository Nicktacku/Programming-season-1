#include <stdio.h>

int divisibleByM(int n1, int n2, int m);

int main(){
    int n1, n2, m;

    // gets the inputs
    printf("Enter starting number: ");
    scanf("%d", &n1);
    printf("Enter ending number: ");
    scanf("%d", &n2);
    printf("Enter divisor: ");
    scanf("%d", &m);

    divisibleByM(n1, n2, m);

    return 0;
}

int divisibleByM(int n1, int n2, int m){
    int ctr = 0;

    // made it so it will only print only when
    // it is divisible and when it does the counter
    //increments
    for(n1; n1 <= n2; n1++){
        if(n1 % m == 0){
            printf("%d, ", n1);
            ctr++;
        }
    }
    printf("%d numbers are divisible by %d", ctr, m);
}