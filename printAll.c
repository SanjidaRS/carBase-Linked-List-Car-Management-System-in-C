//#include "mainA3.c"
#include "../include/headerA3.h"

//function 3
void printAll (struct car * headLL){
 if (headLL == NULL) {
        printf("No cars found\n");
        return;
    }

    int count = 0;
    struct car *tempCar = headLL;
    int wholeNumber = (int)tempCar->price;  //getting whole no.
    int thousandNumber = wholeNumber / 1000; //getting the thousands no.
    int remainder = wholeNumber % 1000; // getting the remainder
    double fractionalNumber = tempCar->price - wholeNumber; //getting the fractional

    while (tempCar != NULL) {
        count++;
        printf("Car # %d:\n", count);
        printf("\tCar id: %d\n", tempCar->carId);
        printf("\tModel: %s\n", tempCar->model);
        printf("\tType: %s\n", tempCar->type);
        printf("\tPrice: CDN $%d,%03d%.2lf\n", thousandNumber, remainder, fractionalNumber);
        printf("\tYear of Manufacture: %d\n\n", tempCar->year);

        tempCar = tempCar->nextCar;
    }

    printf("Currently, there are %d cars.\n", count);
}
