//#include "mainA3.c"
#include "../include/headerA3.h"

//function 4
void printOne (struct car * headLL, int whichOne){
 int cPosition = 1; //initializing current position to 1
 struct car *cCarPosition = headLL;

 //transversing LL until 'whichOne' is found
 while (cCarPosition != NULL && cPosition < whichOne){
    cCarPosition = cCarPosition->nextCar; //moving to next node
    cPosition++;
 }

// checking if the car at the specified position has been found
 if (cCarPosition != NULL && cPosition == whichOne){
 int wholeNumber = (int)cCarPosition->price; //extracting whole number
 int thousandNumber = wholeNumber / 1000; //calculating the thousands part of the price
 int remainder = wholeNumber % 1000; /// Calculate the remainder for the part after the comma
 double fractionalNumber = cCarPosition->price - wholeNumber; //// Calculate the fractional part of the price

   printf("Car id: %d\n", cCarPosition->carId);
   printf("Model: %s\n", cCarPosition->model);
   printf("Type: %s\n", cCarPosition->type);
   printf("Price: CDN $%d,%03d.%02d\n", thousandNumber, remainder, (int)(fractionalNumber * 100));
   printf("Year of Manufacture: %d\n", cCarPosition->year);
 } else {
   printf("No car found at position %d.\n", whichOne);
 }

}
