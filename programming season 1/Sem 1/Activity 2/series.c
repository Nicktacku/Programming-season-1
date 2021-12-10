#include <stdio.h>


int main(){
    int start, stop, step, i;

    printf("Enter start of the series: ");
    scanf("%d", &start);
    printf("Enter stop of the series: ");
    scanf("%d", &stop);
    printf("Enter step for the series: ");
    scanf("%d", &step);

    if(start < stop){
        for(i = start; i <= stop; i+=step){
            printf("%d ", i);
        }
    }
    else if(start > stop){
        for(i = start; i >= stop; i -= step){
            printf("%d ", i);
        }
    }
    else if(start == stop){
        printf("%d %d", start, stop);
    }
}