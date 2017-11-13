/* CS261- Assignment 1 - Q.4*/
/* Name: Frederick Eley
 * Date: 9/29/17
 * Solution description:
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <assert.h>
#include <time.h>

struct student {
    int id;
    int score;
};

void sort(struct student *students, int n) {
    /*Sort the n students based on their score*/
    int i, j;
    struct student temp;

    for (i = 0; i < (n - 1); i++) {
        for (j = 0; j < (n - 1); j++) {
            if (students[j + 1].score < students[j].score) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}


int main() {

    /*initialize random number generator*/
    time_t t;
    srand((unsigned) time(&t));

    /*Declare an integer n and assign it a value.*/
    int n = 10;

    /*Allocate memory for n students using malloc.*/
    struct student *studentArray = (struct student *) malloc(n * sizeof(struct student));
    assert(studentArray != NULL);

    /*Generate random and uniqueArrayque IDs and random scores for the n students, using rand().*/
    int i, j, temp;

    //create IDs in order
    for (i = 0; i < n; i++) {
        studentArray[i].id = i + 1;

        //Assign random score
        studentArray[i].score = rand() % 101;
    }

    //Use Fisher-Yates algorithm to shuffle IDs
    for (i = (n - 1); i > 0; i--) {
        j = rand() % (i + 1);
        temp = studentArray[j].id;
        studentArray[j].id = studentArray[i].id;
        studentArray[i].id = temp;
    }


    /*Print the contents of the array of n students.*/
    printf("Unsorted students\n\n");
    for (i = 0; i < n; i++) {
        printf("StudentID: %d   Score: %d\n", studentArray[i].id, studentArray[i].score);
    }
    printf("\n\n");

    /*Pass this array along with n to the sort() function*/
    sort(studentArray, n);

    /*Print the contents of the array of n students.*/
    printf("\nSorted students\n\n");
    for (i = 0; i < n; i++) {
        printf("StudentID: %d   Score: %d\n", studentArray[i].id, studentArray[i].score);
    }
    printf("\n");

    free(studentArray);

    return 0;
}
