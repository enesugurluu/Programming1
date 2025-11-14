#include <stdio.h>

int main()
{
    int entered_number;
    printf("Enter a number :");
    scanf("%d", &entered_number);

    int first_digit = entered_number / 100;
    int second_digit = (entered_number % 100) / 10;
    int third_digit = entered_number % 10;

    printf("%d number reverse form is %d%d%d", entered_number , third_digit, second_digit, first_digit);
    
    
    return 0;
}
