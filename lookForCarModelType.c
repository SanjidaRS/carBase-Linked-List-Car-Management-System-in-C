#include "../include/headerA3.h"

//function 6
int lookForCarModelType (struct car * headLL, char key [100]){
int cPosition = 1;  //initializing position to 1
struct car *currentCar = headLL;

 while (currentCar != NULL){   //iterating until the end of LL reached
  int j = 0;
  //flags for matching both the model and type with the current key
  int modelMatch = 1;
  int typeMatch = 1;

   while (currentCar->model[j] != '\0' && key[j] != ' ' && key[j] != '\0') {
// if none of the characters match, then 'modelMatch' is set to zero
            if (currentCar->model[j] != key[j]) {
                modelMatch = 0;
                break;
            }
            j++;
        }
// If the end of the model string or the key part doesn't reached, set modelMatch to 0.
   if (currentCar->model[j] != '\0' || key[j] != ' ') {
            modelMatch = 0;
        }

//checking model matches with initializing 'k' as an index
   if (modelMatch) {
            int k = 0;
            j++;  // Move past the space in the key
            while (currentCar->type[k] != '\0' && key[k] != '\0') {
// if none of the characters match, then 'typeMatch' is set to zero
                if (currentCar->type[k] != key[j]) {
                    typeMatch = 0;
                    break;
                }
                k++;
                j++;
            }

//If the end of the type string or the key part doesn't reached, set modelMatch to 0.
    if (currentCar->type[k] != '\0' || key[j] != '\0') {
                typeMatch = 0;
            }
        }

    if (modelMatch && typeMatch) {
            return cPosition;  // returning the position if both model and type match
        }

    currentCar = currentCar->nextCar;  // moving to the next node in LL
        cPosition++;
    }

    return -1;
}
