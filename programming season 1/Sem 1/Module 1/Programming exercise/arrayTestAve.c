#include <stdio.h>

int test();

int main(){
    char name[20];
    double ave;

    printf("Enter student name: ");
    scanf("%s", name);

    int sum = test();

    // average
    ave = sum / 5;

    // prints them all
    printf("\n%s, your total score is %d and your average score is %lf", name, sum, ave);
    return 0;
}

int test(){
    int scores[5];
    int i, sum = 0;

    for(i = 0; i < 5; i++){
        // gets the score
        printf("Enter Answer #%d: ", i + 1);
        scanf("%d", &scores[i]);

        // returns value if base if its 1-5
        if(scores[i] < 6){
            sum += scores[i];
        } else{
            sum += 0;
        }
    }

    return sum;
}