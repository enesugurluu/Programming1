#include <stdio.h>

void printArray(int arr[3][3]);

int main(int argc, char const *argv[])
{
    int b[3][3] = {
        {2, 3, 4},
        {1, 2, 4},
        {5, 6, 7}};

    printf("Displaying the 3x3 array:\n");
    printArray(b);

    return 0;
}

void printArray(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            printf("%d ", arr[i][k]);
        }
        printf("\n");
    }
}