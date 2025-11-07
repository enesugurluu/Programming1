#include <stdio.h>

int main() {
    int entered_value;
    printf("Enter a number : ");
    scanf("%d", &entered_value);

    int cube;
    for (int i = 1; i <= entered_value; i++)
    {
        cube = i * i * i;

        printf("Number is : %d and cube of the %d is : %d\n", i, i, cube);

    }
    
    

    
    


    
    

    return 0;
}