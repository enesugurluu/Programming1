#include <stdio.h>

int main() {
    int entered_value;
    printf("Enter a positive integer: ");
    scanf("%d", &entered_value);

    int result;
    int end_of_multipication = 10;

    // for (int i = 1; i <= end_of_multipication; i++)
    // {
    //     result = entered_value * i;
    //     printf("%d x %d = %d\n", entered_value, i, result);
    // }
    int i = 1;
    while (i <= end_of_multipication)
    {
        result = entered_value * i;
        printf("%d x %d = %d\n", entered_value, i, result);
        i++;
    }
    
    

    return 0;
}