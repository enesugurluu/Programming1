
#include <stdio.h>

int main(void) {
    // Declare variable 'a' as a double (64-bit floating-point) and initialize it to 0.1
    double a = 0.1;
    // Declare variable 'b' as a double and initialize it to 0.2
    double b = 0.2;
    // Declare variable 'c' as a double and add a and b, store the result in c
    // Due to floating-point precision limitations, a + b may not equal exactly 0.3
    double c = a + b;

    // Print the sum with 17 decimal places to show the floating-point precision issue
    // %.17f means print with 17 digits after the decimal point
    printf("a + b = %.17f\n", c);

    // Check if c is EXACTLY equal to 0.3
    // This comparison often FAILS because computers cannot represent 0.1, 0.2, and 0.3 exactly
    // in binary floating-point format, so a + b typically equals 0.30000000000000004 instead of 0.3
    if (c == 0.3)
    {
        printf("The sum is correct.\n");
    }
    else
    {
        printf("The sum is incorrect.\n");
    }

    // Return 0 to indicate the program completed successfully
    return 0;
}