//#include "mainA3.c"
#include "../include/headerA3.h"

//function 2
void loadCarData (struct car ** headLL, char fileName [MAX_LENGTH]){
 FILE *fptr = fopen(fileName, "r");

 if (fptr == NULL) {
        printf("Error in opening the file could not be opened\n");
        return;
    }

    char textFile[100];
    while (fgets(textFile, sizeof(textFile), fptr)) { //reading until EOF
        struct car *newCarDetails = malloc(sizeof(struct car));
        sscanf(textFile, "%d,%[^,],%[^,],%d,%lf", &newCarDetails->carId, newCarDetails->model, newCarDetails->type, &newCarDetails->year, &newCarDetails->price);
        newCarDetails->nextCar = NULL;

        // Check for unique carId in the current list
        struct car *tempCar = *headLL;
        //srand(time(NULL)); // Initialize random seed
        while (tempCar != NULL) {
            if (tempCar->carId == newCarDetails->carId) {
                newCarDetails->carId = newCarDetails->carId + (rand() % 999) + 1; // Add random number between 1 and 999
                tempCar = *headLL; //checking from the beginning again
            } else {
                tempCar = tempCar->nextCar; //moving to the next car in LL
            }
        }

           if (*headLL == NULL) { //checking whether the LL is empty or not
        *headLL = newCarDetails; //if LL is empty, then 'newCarDetails' is the first and only node
    } else {
     //finding the last car in the LL
        struct car *lastCar = *headLL;
        while (lastCar->nextCar != NULL) {
            lastCar = lastCar->nextCar;
        }
        lastCar->nextCar = newCarDetails; //adding 'newCarDetails' at the end of the LL
    }
  }

 fclose(fptr);
}
