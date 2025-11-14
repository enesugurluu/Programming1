#include <stdio.h>

int main()
{
    int result = 1;
 
    for (int i = 1; i <= 10; i++)
    {
        result = result * i;
        printf("%d Faktoriyel:  %d\n", i, result);
    }
    
    return 0;
}
