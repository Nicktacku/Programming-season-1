#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int weight, mars, jupiter, fw;
    char planet[10], planet_lowered[10];

    printf("Enter planet: ");
    scanf("%s", planet);

    // lowers the input so it will be controlled
    for (int i = 0; i < strlen(planet); ++i) {
        planet_lowered[i] = tolower(planet[i]);
    }

    printf("Enter weight: ");
    scanf("%d", &weight);

    // compares then if same then returns 0
    mars = strcmp(planet_lowered, "mars");
    jupiter = strcmp(planet_lowered, "jupiter");

    if(mars == 0){
        //if mars
        fw = weight * .38;
        printf("\nYour weight in mars is: %d", fw);
    } else if(jupiter == 0){
        //if jupiter
        fw = weight * 2.64;
        printf("\nYour weight in jupiter is: %d", fw);
    } else {
        printf("Invalid planet");
    }

    return 0;
}