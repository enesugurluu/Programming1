#include <stdio.h>

/*
 * in-class-work-lesson5-1.c
 * Simple program: reads an integer `max` and prints a table of N, 10*N, 100*N, 1000*N
 * for N = 1..max.
 */

int main(int argc, char const *argv[])
{
    /* prompt and read the upper bound */
    printf("Enter the max number: ");
    int max;
    scanf("%d", &max);
    int counter = 1; /* start from 1 */

    /* print table header */
    printf("N\t10*N\t100*N\t1000*N\n");
    /* loop from 1 to max and print multiples */
    while (counter <= max)
    {
        int pure_value = counter * (1);       /* N */
        int value_with_10 = counter * (10);   /* 10*N */
        int value_with_100 = counter * (100); /* 100*N */
        int value_with_1000 = counter * (1000); /* 1000*N */

        printf("%d\t%d\t%d\t%d\n", pure_value, value_with_10, value_with_100, value_with_1000);

        counter++;
    }

    return 0;
}
