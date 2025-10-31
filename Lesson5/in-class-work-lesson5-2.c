#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int max;
    printf("Enter the max number: ");
    scanf("%d", &max);
    int counter = 1;
    
    
    while (counter <= max)
    {
        
        int starter = 1;
        while (starter <= counter)
        {
            printf("*");
            starter++;
        }

        printf("\n");
        counter++;
    }
    
    return 0;
}
