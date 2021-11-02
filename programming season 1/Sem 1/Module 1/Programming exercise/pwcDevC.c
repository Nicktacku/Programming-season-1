#include <stdio.h>
#include <string.h>

int main(){
    int weight, mars, jupiter, fw;
    char planet[10];

    printf("Enter planet: ");
    scanf("%s", planet);
    printf("Enter weight: ");
    scanf("%d", &weight);

    mars = strcmp(planet, "mars");
    jupiter = strcmp(planet, "jupiter");

    if(mars == 0){
        fw = weight * .38;
    } else if(jupiter == 0){
        fw = weight * 2.64;
    } else {
        printf("Invalid planet");
    }
    printf("the weight is: %d", fw);

    return 0;
}