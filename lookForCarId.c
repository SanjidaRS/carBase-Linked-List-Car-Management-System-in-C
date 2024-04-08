//#include "mainA3.c"
#include "../include/headerA3.h"

//function 5
int lookForCarId (struct car * headLL, int key){
 int cPosition = 1;  //head of LL
 struct car *currentCar = headLL;

 //transversing the LL
 while (currentCar != NULL){
   if (currentCar->carId == key){
     return cPosition;  //if the key is found a match with carId
   }
   currentCar = currentCar->nextCar;  //move to next node
   cPosition++;
 }
 return -1;  // if no car with the key is matched
}
