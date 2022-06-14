#include <stdio.h>

int htmConverter(int hour);

int main() {
    int hour;

    printf("\nConvert Hours to Minutes\n\n");

    printf("Enter Hour: ");
    scanf("%d", &hour);

    // hour if 1, if more then hours
    if (hour > 1){
        printf("%d hours is equal to %d minutes", hour, htmConverter(hour));
    } else {
        printf("%d hour is equal to %d minutes", hour, htmConverter(hour));
    }
    return 0;
}

int htmConverter(int hour) {
    return hour * 60; //converts hours to minutes
}