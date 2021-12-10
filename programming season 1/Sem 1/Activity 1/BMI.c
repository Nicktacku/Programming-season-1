#include <stdio.h>

int main(){
    float bmi, height, weight;

    printf("Enter weight: ");
    scanf("%f", &weight);
    printf("Enter height: ");
    scanf("%f", &height);
    bmi = weight / (height * height);

    if(bmi >= 40){
        printf("BMI: %.2f\nRemarks: Morbid Obesity\nMust do: You need to lose weight");
    } else if(bmi <= 39.99 || bmi >= 35){
        printf("BMI: %.2f\nRemarks: Morbid Obesity\nMust do: You need to lose weight");
    } else if(bmi <= 34.99 || bmi >= 30){
        printf("BMI: %.2f\nRemarks: Morbid Obesity\nMust do: You need to lose weight");
    } else if(bmi <= 29.99 || bmi >= 25){
        printf("BMI: %.2f\nRemarks: Morbid Obesity\nMust do: You need to lose weight");
    } else if(bmi <= 24.99 || bmi >= 18.6){
        printf("BMI: %.2f\nRemarks: Morbid Obesity\nMust do: Keep it up!");
    } else if(bmi <= 18.5){
        printf("BMI: %.2f\nRemarks: Morbid Obesity\nMust do: You need to gain weight");
    }
}