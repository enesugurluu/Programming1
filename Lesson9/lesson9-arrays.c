#include <stdio.h>

int main(int argc, char const *argv[])
{
    int array1[5] = {1,2,5,4,0};

    for (int i = 0; i < 5; i++)
        printf("%d\n", array1[i]);
    
    printf("------------square------------\n");

    for (int i = 0; i < 5; i++)
    {
        array1[i] = array1[i] * array1[i];
    }

    
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", array1[i]);
    }

    return 0;

    
}
