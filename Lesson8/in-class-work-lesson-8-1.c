#include <stdio.h>

int isPrime(int x){
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
        
        
    }
    return 1;
    
}


int main(int argc, char const *argv[])
{
    if (isPrime(19) == 1)
    {
        printf("Yes, the number is prime");
    }else
    {
        printf("No, the number is not prime");
        
    }
    
    
    return 0;
}
