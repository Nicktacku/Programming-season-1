#include <stdio.h>

int candyCost(char type, int kg);

int main() {
    char type;
    int kg;

    printf("\nEnter candy type: ");
    scanf("%c", & type);

    //makes sure the type is within the choices
    if(type == 'a' || type == 'b' || type == 'c' || type == 'd'){
        printf("Enter how many kilograms: ");
        scanf("%d", &kg);

        printf("Candy cost: %d", candyCost(type, kg));
    } else {
        printf("Invalid type");
    }

    return 0;
}

int candyCost(char type, int kg){
    // makes the calculation for the chosen type and entered kilogram
    if(type == 'a' || type == 'A'){
        return 35 * kg;
    } else if(type == 'b' || type == 'B'){
        return 45 * kg;
    } else if(type == 'c' || type == 'C'){
        return 56 * kg;
    } else if(type == 'd' || type == 'D'){
        return 57.50 * kg;
    }
}