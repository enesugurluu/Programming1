#include <stdio.h>
#include <math.h>
#include <stdlib.h>




int main()
{
    int seed = 14;
    
    srand(seed);
    for (int i = 1; i <= 12; i++)
    {
        printf("%d -", 1 + (rand() % 6));
    }
    
    printf("%d", 1 + (rand() % 6));
    
    return 0;
}

