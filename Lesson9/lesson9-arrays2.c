#include <stdio.h>

#define SIZE 5
#define SIZE1 5


int main(int argc, char const *argv[])
{
    int array1[SIZE] = {1,2,5,4,0};

    int grades[SIZE1] = {54,42,61,82,94};


    for (size_t i = 0; i < SIZE; i++)
    {
        /* code */
    }


    float sum = 0;
    for (int i = 0; i < SIZE1; i++)
    {
        sum = sum + grades[i];
    }
    
    printf("Average grade is %f" , sum / SIZE1);

    return 0;

    
}
