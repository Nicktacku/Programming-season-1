#include <stdio.h>
#include <ctype.h>

int main(){
    char polygon;
    float area, perimeter, side, side1,
    side2, side3, lenght, width;
    int invalid = 0;

    //does the path of whatever value entered
    printf("Enter Polygon (s, r, or t): ");
    scanf(" %c", &polygon);
    polygon = tolower(polygon);

    if(polygon == 's'){
        printf("Enter Side: ");
        scanf("%f", &side);

        area = side * side;
        perimeter = 4 * side;
    }
    else if(polygon == 'r'){
        printf("Enter Lenght: ");
        scanf("%f", &lenght);
        printf("Enter Width: ");
        scanf("%f", &width);

        area = lenght * width;
        perimeter = (2 * lenght) + (2 * width);
    }
    else if(polygon == 't'){
        printf("Enter base: ");
        scanf("%f", &side1);
        printf("Enter height: ");
        scanf("%f", &side2);
        printf("Enter hypotenuse: ");
        scanf("%f", &side3);

        area = side1 / 2 * side2;
        perimeter = side1 + side2 + side3;
    }

    else{
        printf("Invalid input");

        //will result in not printing the area and perimeter
        invalid = 1;
    }

    //uses a boolean system for the
    //outputting will not be redundant
    if(invalid == 0){
        printf("\nArea: %.2f\n", area);
        printf("Perimeter: %.2f", perimeter);
    }

}