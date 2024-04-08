//#include "mainA3.c"
#include "../include/headerA3.h"

//function 1
void addNewCar (struct car ** headLL){
 struct car *newCarDetails = malloc(sizeof(struct car));
 struct car *lastCarDetails = *headLL;
 //user input for the struct
    printf("Enter the car model: ");
    scanf("%s", newCarDetails->model);
    printf("Enter the car type: ");
    scanf("%s", newCarDetails->type);
    printf("Enter its year of manufacture: ");
    scanf("%d", &newCarDetails->year);
    printf("Enter its price: CDN $ ");
    scanf("%lf", &newCarDetails->price);

 //calculating carId using ascii value of car's model and length of car's type
    newCarDetails->carId = 0;
    for (int i = 0; newCarDetails->model[i] != '\0'; i++) {
        newCarDetails->carId = newCarDetails->carId + newCarDetails->model[i];
    }
    newCarDetails->carId = newCarDetails->carId + strlen(newCarDetails->type);

 //if a carId already exists, then generate a random value
    srand(time(NULL)); //ensuring 'rand()' produces a different sequence of random numbers each time the program is run
    while (lastCarDetails != NULL) {  //last points to current node in the LL
        if (lastCarDetails->carId == newCarDetails->carId) {  //checking if the current 'carId' ('lastCarDetails->carId') is the same as the new car 'carId>            newCarDetails->carId = newCarDetails->carId + (rand() % 999) + 1; // Adding random number between 1 and 999
            lastCarDetails = *headLL; //resetting last to point to the head of the list
        } else {
            lastCarDetails = lastCarDetails->nextCar;  //moves 'last' pointer to the next node in the list
        }
    }


    newCarDetails->nextCar = NULL; //means the new car node will be at the end of the LL
    if (*headLL == NULL) {
        *headLL = newCarDetails;  //sets the head of the LL, making 'newCar' the first and only node in the list
    } else {
        while (lastCarDetails->nextCar != NULL) { //continues as long as the 'nextCar' pointer of the current node is not NULL
            lastCarDetails = lastCarDetails->nextCar;  //transversing
        }
        lastCarDetails->nextCar = newCarDetails;
    }

    printf("Your computer-generated carId is %d\n", newCarDetails->carId);
}
