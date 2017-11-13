/* CS261- Assignment 1 - Q.3*/
/* Name: Frederick Eley
 * Date: 9/29/17
 * Solution description:
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <assert.h>
#include "time.h"


void sort(int *number, int n) {
    /*Sort the given array number , of length n*/
    int i, j, temp;

    for (i = 0; i < (n - 1); i++) {
        for (j = 0; j < (n - 1); j++) {
            if (number[j + 1] < number[j]) {
                temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
    }
}

int main() {

    /*initialize random number generator*/
    time_t t;
    srand((unsigned) time(&t));

    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
    int *intArray = (int *) malloc(n * sizeof(int));
    assert(intArray != NULL);

    /*Fill this array with random numbers, using rand().*/
    int i;
    for (i = 0; i < n; i++) {
        intArray[i] = rand() % 100;
    }

    /*Print the contents of the array.*/
    printf("Unsorted array\n");
    for (i = 0; i < n; i++) {
        printf("%d ", intArray[i]);
    }
    printf("\n\n");


    /*Pass this array along with n to the sort() function of part a.*/
    sort(intArray, n);


    /*Print the contents of the array.*/
    printf("Sorted array\n");
    for (i = 0; i < n; i++) {
        printf("%d ", intArray[i]);
    }
    printf("\n\n");

    free(intArray);

    return 0;
}
