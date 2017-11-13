#include <stdio.h>
#include <math.h>

int main() {

    double  side1,
            side2,
            side3,
            halfPerimeter,
            area;

    printf("\nThis program will calculate the area of a triangle given the lengths of it's sides.\n\n");

//get user input
    printf("Enter the length of side 1: ");
    scanf("%lf", &side1);
    printf("Enter the length of side 2: ");
    scanf("%lf", &side2);
    printf("Enter the length of side 3: ");
    scanf("%lf", &side3);

//calculations
    halfPerimeter = (side1 + side2 + side3) / 2;
    area = sqrt(halfPerimeter * (halfPerimeter - side1) * (halfPerimeter - side2) * (halfPerimeter - side3));

//print results
    printf("\nThe area of the triangle is %f.\n\n", area);
    return 0;
}