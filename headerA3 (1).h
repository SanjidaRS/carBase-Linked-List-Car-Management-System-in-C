#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_LENGTH 25

struct car
{
   int year;
   double price;
   char model[MAX_LENGTH];
   char type[MAX_LENGTH];
   int carId;   // this is auto-generated by the program must be unique for each car
   struct car * nextCar;
};


typedef struct car a3Car;

void addNewCar (struct car ** headLL);
void printAll (struct car * headLL);
void printOne (struct car * headLL, int whichOne);
int lookForCarId (struct car * headLL, int key);
int lookForCarModelType (struct car * headLL, char key [100]);
void sortCarId (struct car ** headLL);
void loadCarData (struct car ** headLL, char fileName [MAX_LENGTH]);
int countCars (a3Car * headLL);
void noMoreCars (a3Car ** headLL);
void oneLessCar (a3Car ** headLL, int whichOne);
