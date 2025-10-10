#include <stdio.h>

int main() {
    int height, width;

    printf("Enter height and weight: ");
    scanf("%d%d", &height, &width);

    int rectangle_area = height * width;
    printf("Area: %d\n", rectangle_area);


    int perimeter = 2 * (height + width);
    printf("Perimeter: %d\n", perimeter);
    
    return 0;
}