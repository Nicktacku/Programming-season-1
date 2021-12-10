#include <stdio.h>

int main(){
    int w, x = 10, y = 0, z = 1, result;

    for(w = 0; w < x; w++){
        if(w % 2 == 0){
            result = y + z;
            printf("%d ", result);
            z = result;
        }
        else{
            result = y + z;
            printf("%d ", result);
            y = result;
        }
    }
}