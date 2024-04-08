//#include "mainA3.c"
#include "../include/headerA3.h"

//function 10
void noMoreCars (a3Car ** headLL){
  a3Car *currentCar = *headLL;
    a3Car *nextNodeCar;

    while (currentCar != NULL) {   //iterating until the end of LL reached
        nextNodeCar = currentCar->nextCar;  //saving the next node before freeing
        free(currentCar);
        currentCar = nextNodeCar;  //moving to the next node in the LL
    }

//after all nodes are freed, setting the head of LL to NULL to indicate that it is empty
    *headLL = NULL;
}
