/*
Student Name: Sanjida Rahman Supti
Student ID: 1215651
Due Date: 5th April, 2024
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/

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
