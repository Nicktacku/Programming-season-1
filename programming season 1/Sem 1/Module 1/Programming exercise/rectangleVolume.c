#include <stdio.h>

// calculates and print rectangle volume

int calcRecVol(int l, int w, int h);

int main() {
    int l, w, h;

    printf("\nPrints the volume of a rectangle\n\n");

    printf("Enter lenght: ");
    scanf("%d", &l);

    printf("Enter width: ");
    scanf("%d", &w);

    printf("Enter height: ");
    scanf("%d", &h);

    printf("Volume: %d", calcRecVol(l, w, h));
    return 0;
}

int calcRecVol(int l, int w, int h){
    return l * w * h; // formula for rectangle
}