/* CS261- Assignment 1 - Q.2*/
/* Name: Frederick Eley
 * Date: 9/28/17
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int *a, int *b, int c) {
    /*Set a to double its original value*/
    *a = 2 * *a;

    /*Set b to half its original value*/
    *b = *b / 2;

    /*Assign a+b to c*/
    c = *a + *b;

    /*Return c*/
    return c;
}

int main() {
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/

    int x = 5,
            y = 6,
            z = 7;

    /*Print the values of x, y and z*/

    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of z is %d\n\n", z);

    /*Call foo() appropriately, passing x,y,z as parameters*/

    int fooValue = foo(&x, &y, z);

    /*Print the value returned by foo*/

    printf("The value returned by foo is %d\n\n", fooValue);

    /*Print the values of x, y and z again*/
    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of z is %d\n\n", z);

    /*Is the return value different than the value of z?  Why?
     * The value returned by foo is different than the value of z
     * because z was passed by value not by reference so the value of
     * c inside foo is at a totally different memory address than that of z.*/
    return 0;
}
    
    
