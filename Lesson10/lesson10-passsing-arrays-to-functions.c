#include <stdio.h>

void change(int x, int y)
{
  y = 100;
  x = 100;
}

int main(int argc, char const *argv[])
{
  int a = 12;
  int b = 13;

  change(a, b);

  printf("%d -- %d", a, b); // A and B is not 100, a is 12, b is 13

  return 0;
}
