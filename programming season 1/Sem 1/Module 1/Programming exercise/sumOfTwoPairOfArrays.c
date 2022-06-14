#include <stdio.h>

int main(){
    int first[11];
    int last[10];
    int i, sum;

    for(i = 0; i < 11; i++){
        printf("Enter number: ");
        scanf("%d", &first[i]);
    }

    for(i = 0; i < 10; i++){
        // adds the first element and the next element
        sum = first[i] + first[i + 1];
        last[i] = sum;
        printf("%d\n", last[i]);
    }

    return 0;
}