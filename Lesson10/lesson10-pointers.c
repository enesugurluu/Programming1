#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 7;

    int *aPtr = &a;

    printf("value of a via pointer (*aPtr): %d\n", *aPtr);

    // Addresses must be printed with %p (pointer format), not %d.
    printf("address of a (&a):           %p\n", &a);
    printf("value stored in aPtr (aPtr): %p\n", aPtr);
    printf("address of pointer (&aPtr):  %p\n", &aPtr);

    // Note: *&aPtr == aPtr (it is still a pointer value, not an int)
    printf("*&aPtr (same as aPtr):       %p\n", *&aPtr);

    return 0;
}
