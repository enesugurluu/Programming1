#include <stdio.h>

int main() {
    
    int entered_value;
    printf("Enter an integer: ");
    scanf("%d", &entered_value);

    if (entered_value == 0){
        printf("%d is zero.\n", entered_value);
    } else if (entered_value > 0){
        printf("%d is positive.\n", entered_value);
    } else {
        printf("%d is negative.\n", entered_value);
    }

    return 0;
}