#include <stdio.h>

int main(){
    int i, sum, x = 10;

    //changable by changing x
    for(i = 1; i <= x; i++){
        sum += i;
    }
    printf("sum: %d", sum);
}