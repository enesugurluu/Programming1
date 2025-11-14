#include <stdio.h>

int main() {
    int entered_value;
    printf("Enter a possitive number for factorial  : ");
    scanf("%d", &entered_value);

    while(entered_value < 0)
    {
        printf("Please enter valid second for factorial  : ");
        scanf("%d", &entered_value);
    }

    int result = 1;
    // int i = 1;
    // while (i <= entered_value)
    // {
    //     result = result * i;
    //     i++;
    // }

    for (int i = 1; i <= entered_value; i++)
    {
        result = result * i;
    }
    
    
    printf("%d Faktoriyel %d",entered_value,result);
    


    
    

    return 0;
}