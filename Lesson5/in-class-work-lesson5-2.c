#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int max;
    printf("Enter the max number: ");
    scanf("%d", &max);
    int counter_row = 1;
    
    
    while (counter_row <= max)
    {
        
        int starter = 1;
        while (starter <= counter_row)
        {
            printf("*");
            starter++;
        }

        printf("\n");
        counter_row++;
    }
    
    return 0;
}
