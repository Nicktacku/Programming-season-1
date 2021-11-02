#include <stdio.h>

int operationExplosion(int a, int b, int c);

int main() {
    int a, b, c;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter third number: ");
    scanf("%d", &c);

    operationExplosion(a, b, c);
    return 0;
}

int operationExplosion(int a, int b, int c){
    //computes the different kind of operations
    printf("\nsum: %d\ndifference: %d\nproduct: %d\nquotient: %d\nsum of squares: %d",
    a + b + c, a - b - c, a * b * c, a / b / c, (a * a) + (b * b) + (c * c)); // was done in 1 print because will result in error if seperated
}
