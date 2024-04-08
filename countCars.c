//#include "mainA3.c"
#include "../include/headerA3.h"

//function 7
int countCars (a3Car * headLL){
  int count = 0;
  a3Car *currentCar = headLL;

  while (currentCar != NULL){
    count++;
    currentCar = currentCar->nextCar;
  }
 return count;
}
