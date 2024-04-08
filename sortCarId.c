//#include "mainA3.c"
#include "../include/headerA3.h"

//function 8
void sortCarId (struct car ** headLL){

   if (*headLL == NULL || (*headLL)->nextCar == NULL) {
        return;  // No need to sort if the list is empty or has only one element
    }

    struct car *currentCar = *headLL;
    struct car *indexCar = NULL;
    struct car *minCar = NULL;

    // Traversing the LL
    while (currentCar != NULL) {
        minCar = currentCar;
        indexCar = currentCar->nextCar;


        // Finding the smallest carId in the remaining LL
        while (indexCar != NULL) {
            if (indexCar->carId < minCar->carId) {
                minCar = indexCar;
            }
            indexCar = indexCar->nextCar;
        }

        // Swaping data if minCar is not already in the correct position
        if (minCar != currentCar) {
            // Swaping carId
            int tempId = currentCar->carId;
            currentCar->carId = minCar->carId;
            minCar->carId = tempId;

            // Swaping model
            char tempModel[MAX_LENGTH];
            strcpy(tempModel, currentCar->model);
            strcpy(currentCar->model, minCar->model);
            strcpy(minCar->model, tempModel);

            // Swaping type
            char tempType[MAX_LENGTH];
            strcpy(tempType, currentCar->type);
            strcpy(currentCar->type, minCar->type);
            strcpy(minCar->type, tempType);

            // Swaping price
            double tempPrice = currentCar->price;
            currentCar->price = minCar->price;
            minCar->price = tempPrice;


            // Swaping year
            int tempYear = currentCar->year;
            currentCar->year = minCar->year;
            minCar->year = tempYear;
        }

        currentCar = currentCar->nextCar;  // Moving to the next node in LL
    }
}
