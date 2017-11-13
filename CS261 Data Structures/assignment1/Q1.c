/* CS261- Assignment 1 - Q.1*/
/* Name: Frederick Eley
 * Date: 9/15/17
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <time.h>

struct student {
    int id;
    int score;
};

struct student *allocate() {
    /*Allocate memory for ten students*/
    struct student *s = malloc(10 * (sizeof(struct student)));
    assert(s != NULL);

    /*return the pointer*/
    return s;
}

void generate(struct student *students) {
    /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/

    int i, j, temp;

    //create IDs in order
    for (i = 0; i < 10; i++) {
        students[i].id = i + 1;

        //Assign random score
        students[i].score = rand() % 101;
    }

    //Use Fisher-Yates algorithm to shuffle IDs
    for (i = 9; i > 0; i--) {
        j = rand() % (i + 1);
        temp = students[j].id;
        students[j].id = students[i].id;
        students[i].id = temp;
    }
}

void output(struct student *students) {
    /*Output information about the ten students in the format:
             ID1 Score1
             ID2 score2
             ID3 score3
             ...
             ID10 score10*/
    int i;
    for (i = 0; i < 10; i++) {
        printf("StudentID: %d   Score: %d\n", students[i].id, students[i].score);
    }
}

void summary(struct student *students) {
    /*Compute and print the minimum, maximum and average scores of the ten students*/
    int i, min, max;
    double sum, avg;

    //compute minimum
    min = students[0].score;
    for (i = 1; i < 10; i++) {
        if (students[i].score < min) {
            min = students[i].score;
        }
    }

    //compute maximum
    max = students[0].score;
    for (i = 1; i < 10; i++) {
        if (students[i].score > max) {
            max = students[i].score;
        }
    }

    //compute average
    sum = 0;
    for (i = 0; i < 10; i++) {
        sum += students[i].score;
    }
    avg = sum / 10;


    //print results
    printf("\nThe minimum score is %d\n", min);
    printf("The maximum score is %d\n", max);
    printf("The average score is %f\n", avg);


}

void deallocate(struct student *stud) {
    /*Deallocate memory from stud*/
    assert(stud != NULL);
    free(stud);
}

int main() {

    /*initialize random number generator*/
    time_t t;
    srand((unsigned) time(&t));

    struct student *stud = NULL;

    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
}
