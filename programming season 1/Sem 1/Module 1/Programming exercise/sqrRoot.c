#include <stdio.h>
#include <math.h>

int main(){
    // 20 elemnts int he array ending with senti value
    int x[20] = {63, 50, 47, 58, 93, 75, 7, 55, 59,
    32, 81, 23, 12, 98, 79, 84, 88, 58, 84, 0};
    int y[20] = {59, 84, 84, 38, 8, 83, 43, 1, 82, 67,
     57, 36, 9, 34, 71, 46, 89, 15, 2, 0};
    double z[20], n;
    int i;

    // adds them then squre roots the sum before putting in array z
    for(i = 0; i < 20; i++){
        n = x[i] + y[i];
        z[i] = sqrt(n);
    }

    for(i = 0; i < 20; i++){
        printf("%.2lf\n", z[i]);
    }
}