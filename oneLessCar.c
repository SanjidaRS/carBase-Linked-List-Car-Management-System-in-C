//#include "mainA3.c"
#include "../include/headerA3.h"

//function 9
void oneLessCar (a3Car ** headLL, int whichOne){
if (*headLL == NULL || whichOne < 1) {
     return;  // List is empty or invalid position
    }

    a3Car *currentCar = *headLL;
    a3Car *previousCar = NULL;
    int cPosition = 1;

   if (whichOne == 1) {
        *headLL = currentCar->nextCar;  // Head now points to the second node
        free(currentCar);  // Free the memory of the original head
        return;
    }

    // Traverse the list to find the node before the one to remove
    while (currentCar != NULL && cPosition < whichOne) {
        previousCar = currentCar;
        currentCar = currentCar->nextCar;
        cPosition++;
    }

    // If the node to be removed exists in the list
    if (currentCar != NULL) {
        previousCar->nextCar = currentCar->nextCar;  // Unlink the node from the list
        free(currentCar);  // Free the memory of the node to be removed
    }

}
