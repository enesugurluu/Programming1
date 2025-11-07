#include <stdio.h>

int main() {
    // for (int i = 1; i <= 10; i++) {
    //     printf("%d\n", i);
    // }

    int sum = 0;

    for (int i = 1; i <= 15; i++)
    {
        sum += i;
        
    }
    
    printf("The sum is %d\n", sum);
    
    return 0;
}