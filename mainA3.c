#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "../include/headerA3.h"

#define MAX_LENGTH 25

int main (){
 struct car *head = NULL;
 int choice, position, carid;
 char key[100];

  char fileName [MAX_LENGTH];
  
while (1) {
 printf("\nPlease choose an option from the following menu:\n");
 printf("1. Add data on a new car\n");
 printf("2. Load data on cars from a given text file\n");
 printf("3. Print data of all cars\n");
 printf("4. Print data of the nth car\n");
 printf("5. Search car data based on carId\n");
 printf("6. Search car data based on model and type\n");
 printf("7. Count the total number of cars in the list\n");
 printf("8. Sort the cars in the list based on carId\n");
 printf("9. Remove data of the nth car\n");
 printf("10. Remove all car data\n");
 printf("11. Exit\n");
 scanf("%d", &choice);

 switch(choice){

  case 1:
    addNewCar(&head);
    break;

  case 2:
    strcpy (fileName, "inputFile.txt");
    loadCarData(&head, fileName);
    break;

  case 3:
    printAll(head);
    break;

  case 4:
    printf("Enter a position: ");
    scanf("%d", &position);
    printOne(head, position);
    break;

  case 5:
    printf("Enter a car Id: ");
    scanf("%d", &carid);
    int position = lookForCarId(head, carid);
    if (position != -1){
     printOne(head, position);
    } else {
     printf("Car with Id %d not found.\n", position);
    }
     break;

  case 6:
    printf("Enter the model and type (separated by a space): ");
getchar();
    fgets(key, sizeof(key), stdin);
    key[strlen(key) - 1] = '\0';
    int position1 = lookForCarModelType(head, key);
    if (position1 != -1) {
        printOne(head, position1);
    } else {
        printf("Car with model and type '%s' not found.\n", key);
    }
    break;

  case 7:
    printf("Total number of cars = %d\n", countCars(head));
    break;

  case 8:
    sortCarId(&head);
    printAll(head);
    break;

  case 9:
    int carCount = countCars(head);
    if (carCount == 0) {
        printf("There are no cars to remove.\n");
    } else {
        int rIndex;
        printf("Currently there are %d cars.\n", carCount);
        while (1) {
            printf("Which car do you wish to remove – enter a value between 1 and %d: ", carCount);
            scanf("%d", &rIndex);

            if (rIndex >= 1 && rIndex <= carCount) {
                break;
            } else {
                printf("Invalid input. Please enter a number between 1 and %d.\n", carCount);
            }
        }

        oneLessCar(&head, rIndex);
        printf("Car [id: %d] removed.\n", rIndex);
        printf("There are now %d cars remaining.\n", countCars(head));
    }
    break;


  case 10:
    char userInput = '\0';
    printf("Choose a menu option: 10\n");

    while (userInput != 'y' && userInput != 'n') {
        printf("Are you sure you want to remove all car data (enter y for yes, n for no): ");
        scanf(" %c", &userInput);

        if (userInput == 'y') {
            noMoreCars(&head);
            printf("All removed. Linked list is now empty.\n");
        } else if (userInput == 'n') {
            printf("Operation canceled.\n");
        } else {
            printf("Invalid input. Please enter 'y' for yes or 'n' for no.\n");
        }
    }
     break;

   case 11:
    printf("Exiting the program.\n");
    return 0;

   default:
    printf("Invalid option. Please choose from 1 to 11.\n");
    break;

    }
 }

 return 0;
}

