#include <stdio.h>

// determines the price per area
int bestPizzaDeterminer(int diameter, int price);
//determines which is the cheapest
int sulitDeterminer(int fp1, int fp2, int fp3);

int main(){
    int pizza1, pizza2, pizza3;
    // made as arrays to be organized
    int diameter[3] = {10, 12, 14};
    int price[3] = {178, 259, 314};

    // declared as variables to be comparable
    pizza1 = bestPizzaDeterminer(diameter[0], price[0]);
    pizza2 = bestPizzaDeterminer(diameter[1], price[1]);
    pizza3 = bestPizzaDeterminer(diameter[2], price[2]);

    //compares the 3 pizzas
    sulitDeterminer(pizza1, pizza2, pizza3);
    return 0;
}

int bestPizzaDeterminer(int diameter, int price){
    int radius;
    float area, final_price;
    radius = diameter / 2;
    area = 3.14 * (radius * radius);
    final_price = price / area;

    return final_price;

}

int sulitDeterminer(int fp1, int fp2, int fp3){
    if(fp1 > fp2 && fp1 > fp3){
        printf("\nFirst pizza is the least expensive\n");
    } else if(fp2 > fp1 && fp2 > fp3){
        printf("\nSecond pizza is the least expensive\n");
    } else{
        printf("\nThird pizza is the least expensive\n");
    }
}