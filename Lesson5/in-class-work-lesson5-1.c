#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Enter the max number: ");
    int max;
    scanf("%d", &max);
    int counter = 1;

    printf("N\t10*N\t100*N\t1000*N\n");
    while (counter <= max)
    {
        int pure_value = counter * (1);
        int value_with_10 = counter * (10);
        int value_with_100 = counter * (100);
        int value_with_1000 = counter * (1000);

        printf("%d\t%d\t%d\t%d\n",pure_value,value_with_10,value_with_100,value_with_1000);

        counter++;
    }
    
    
    return 0;
}
