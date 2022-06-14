#include <stdio.h>

int knowByAge(int age);

int main(){
    int age;

//takes the age
    printf("Enter Age: ");
    scanf("%d", &age);

    knowByAge(age);
    return 0;
}

int knowByAge(int age){
    //determines based on the age
    if(age < 12){
        printf("C");
    } else if(age > 12 && age < 20){
        printf("T");
    } else {
        printf("A");
    }
}