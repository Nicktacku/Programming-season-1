#include <stdio.h>

int reverse(int n);

int main(){
    int x, y, n;

    printf("Enter number of value of array: ");
    scanf("%d", &n);

    reverse(n);

    return 0;
}

int reverse(int n){
    // reverse the entered array
    int x[n];
    int y[n];
    int i, j;

    for(i = 0; i < n; i++){
        printf("Enter number till %d: ", n);
        scanf("%d", &x[i]);
    }
    // puts whats in x first place to y last place
    // its it while the x is increasing
    // and y is decreasing
    for(i = 0, j = n - 1; i < n; i++, j--){
        y[j] = x[i];
    }

    for(i = 0; i < n; i++){
        printf("%d\n", y[i]);
    }

}