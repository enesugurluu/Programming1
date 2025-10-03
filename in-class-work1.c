#include <stdio.h>

int main() {

    int a,b;
    
    printf("Please enter first,second value...");
    scanf("%d%d",&a,&b);

    int sum = a + b;
    int substract = a - b;
    int divide = a/b;
    int multiply = a*b;
    int mod = a % b;



    printf("Operation of sum result is %d",sum);
    printf("\nOperation of substract result is %d",substract);
    printf("\nOperation of divide result is %d",divide);
    printf("\nOperation of multiply result is %d",multiply);
    printf("\nOperation of mod result is %d",mod);


    return 0;
}