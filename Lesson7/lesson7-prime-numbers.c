#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number;

    int isPrime = 1;

    printf("Enter a number : "),
    scanf("%d", &number);

    for (int i = 2; i < number-1; i++)
    {
        if (number % i == 0)
        {
            isPrime = -1;
            break;
        }
        
    }

    if (isPrime == 1)
    {
        printf("%d the number is prime number" , number);
    }else
    {
        printf("%d the number is not prime number" , number);
    }

    return 0;
}
