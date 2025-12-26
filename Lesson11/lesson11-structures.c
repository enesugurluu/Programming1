#include <stdio.h>

struct Complex
{
    float real;
    float imaginary;
};


int main(int argc, char const *argv[])
{
    struct Complex ComplexNum1, ComplexNum2, result;

    ComplexNum1.real = 3;
    ComplexNum1.imaginary = 4.9;

    ComplexNum2.real = 0.0;
    ComplexNum2.imaginary = 10.0;

    result.real = ComplexNum1.real + ComplexNum2.real;
    result.imaginary = ComplexNum1.imaginary + ComplexNum2.imaginary;
    
    return 0;
}
