#include <stdio.h>

int main(){
    int i, z = 0, y = 1;

    for(i = 1; i < 5; i++){
        printf("%d ", y);
        z = z + y;
        y = y + z;
        printf("%d\n", z);
    }
}