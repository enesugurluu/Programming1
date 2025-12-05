#include <stdio.h>
#include <math.h>

int square(int);
int biggest(int,int,int);
int smallest(int,int,int);


int main()
{
    printf("%d\n",square(23));
    printf("%d\n", biggest(15,48,75));
    printf("%d\n", smallest(15,48,75));

    double result = pow(5,3);
    printf("%1f\n",result);
    
    return 0;
}

int square(int x)
{
    int result;
    result = x * x;
    return result;
}

int biggest(int num1,int num2, int num3){
    if (num1 > num2 && num1 > num3)
        return num1;
    else if (num2 > num1 && num2 > num3)
        return num2;
    else
        return num3;    
}

int smallest(int num1,int num2, int num3){
    if (num1 < num2 && num1 < num3)
    {
        return num1;
    }else if (num2 < num1 && num2 < num3)
    {
        return num2;
    }else
    {
        return num3;
    }
    
}