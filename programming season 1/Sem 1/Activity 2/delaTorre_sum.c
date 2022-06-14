#include <stdio.h>

//Nicholas Noly dela Torre

int main(){
    int i, sum, limit = 10;

    //changable by changing limit
    for(i = 1; i <= limit; i++){
        sum += i;
    }
    printf("sum: %d", sum);
}