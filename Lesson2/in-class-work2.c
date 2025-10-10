#include <stdio.h>

int main() {
    int height, width;

    printf("Enter height and weight: ");
    scanf("%d%d", &height, &width);

    int rectangle_area = height * width;
    printf("Area: %d\n", rectangle_area);
    return 0;
}